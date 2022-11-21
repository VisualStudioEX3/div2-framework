/* ----------------------------------------------------------------------------
 * LOGGER.DLL - File logger for DIV Games Studio 2.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "logger.h"

static void createRootLogFolder()
{
	mkdir(LOG_FOLDER);
    chdir(LOG_FOLDER);
}

static void createTodayFolder(const struct tm* today)
{
	char folder[8];
	
	sprintf(folder,
            "%i%02i%02i", // yyyyMMdd.
            today->tm_year,
            today->tm_mon,
            today->tm_mday);

    mkdir(folder);
    chdir(folder);
}

static void createLogFile(const struct tm* today)
{
	char filename[12]; // Log filename format: "HHmmss.LOG"
	
	sprintf(filename,
            "%02i%02i%02i.LOG", // DOS filename 8:3 format.
            today->tm_hour,
            today->tm_min,
            today->tm_sec);

    file = div_fopen(filename, "a+");
}

static void restoreInitialPath()
{
	chdir("..\\.."); // Return before root folder.
}

static void logHeader(const struct tm* today)
{
	char timeStamp[LINE_CHAR_MAX_LENGTH];
	
	strftime(timeStamp, LINE_CHAR_MAX_LENGTH, "Log started on %c", today);
    log(timeStamp);	
    writeLineSeparator();
}

static void init()
{
    struct tm* now = getDateTime();
	
	createRootLogFolder();
	createTodayFolder(now);
	createLogFile(now);
	restoreInitialPath();
	logHeader(now);
}

static void writeLineSeparator()
{
    log(LINE_SEPARATOR);
}

static int log(const string message)
{
    if (LOG_OK)
    {        
        struct tm* now = getDateTime();
		
        fprintf(file,
                "[%02i:%02i:%02i] %s\n", // "[dd/MM/yyyy HH:mm:ss] %message%"
                now->tm_hour,
                now->tm_min,
                now->tm_sec,
                message);
    }

    return LOG_OK;
}

static void closeLogFile()
{
	if (LOG_OK)
	{
		writeLineSeparator();
		log("Program terminated.");
		div_fclose(file);
	}
}

void div_log()
{
	char* message = getStringParm();
	int ret = log(message);
    
    retval(ret);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_LOG_NAME, div_log, DIV_LOG_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
    init();
}

void __export divend(COMMON_PARAMS)
{
	closeLogFile();
}
