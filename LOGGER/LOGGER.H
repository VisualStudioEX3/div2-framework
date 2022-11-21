/* ----------------------------------------------------------------------------
 * LOGGER.DLL - File logger for DIV Games Studio 2.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_LOGGER_H_
    #define __DIV_LOGGER_H_

    #include <direct.h>
    #include <stdio.h>

    #include "..\shared\_div2lib.h"
    #include "..\shared\_time.h"

    #define LOG_FOLDER                  "LOGS"
    #define LOG_OK                      file != NULL
    #define LINE_SEPARATOR				"-------------------------------------------------------------------------------"
    #define LINE_CHAR_MAX_LENGTH		80

    static FILE* file;

    static void createRootLogFolder();
    static void createTodayFolder(const struct tm* today);
    static void createLogFile(const struct tm* today);
    static void restoreInitialPath();
    static void logHeader(const struct tm* today);
    static void init();
    static int  log(const string message);
    static void writeLineSeparator();
    static void closeLogFile();

    /** 
     * Writes a message to log file.
     *
     * @param {string} message - Message to write in the log file.
     *
     * @return {int} - Returns 0 if the log file is not created, 1 otherwise.
     *
     * @remarks The message is formatted as follow: "[dd/MM/yyyy HH:mm:ss] %message%"
     */
    void div_log();
    #define DIV_LOG_NAME    "log"
    #define DIV_LOG_PARAMS  1
#endif
