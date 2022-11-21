/* ----------------------------------------------------------------------------
 * INIFILE.DLL - INI parser for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "inifile.h"

// int vfprintf(FILE *stream, const char *format, va_list arg) - write formatted line to file.
// const char * template = <template_factory> 
// vfprintf(file, template, key, value);

static bool tryReadValue(const char *filename, const char *section, const char *key, char *value)
{
    bool ret = false;
    FILE *file = div_fopen((char*)filename, "r");
    
    if (file)
    {
        char *str = strmalloc(LINE_LENGTH);
        
        while (!ret && tryReadLine(file, str))
        {
            if (section ? checkSectionHeader(str, section) : !isSectionHeader(str))
                ret = tryGetKeyParValueInSection(file, key, value);
            
            if (!section) break;
        }
        
        div_free(str);
    }
    
    div_fclose(file);
    
    return ret;
}

static bool tryReadLine(FILE *file, char *dest)
{
    return fgets(dest, LINE_LENGTH, file) != NULL;
}

static bool checkSectionHeader(const char *src, const char *section)
{
    bool ret = false;
    
    if (_isSectionHeader(src))
    {
        char *sectionPtr = (char*)&src[1];
        char *sectionReaded = strmalloc(VALUE_LENGTH);
        
        strncpy(sectionReaded, sectionPtr, strlen(src) - 1);
        strtrim(sectionReaded);
        ret = strequal(sectionReaded, section);
        div_free(sectionReaded);
    }
    
    return ret;
}

static bool tryGetKeyParValueInSection(FILE *file, const char *key, char *value)
{
    char *str = strmalloc(LINE_LENGTH);
    
    while (tryReadLine(file, str) && !isSectionHeader(str))
    {
        if (!_isEmptyLine(str) && tryGetKeyParValue(str, key, value))
            return true;
    }
    
    div_free(str);
    
    return false;
}

static bool tryGetKeyParValue(const char *src, const char *key, char *value)
{
    bool ret = false;
    char *token = strtok((char*)src, FIELD_DELIMITER_CHAR);
    
    if (token)
    {
        strtrim(token);
        
        char *readedKey = strmalloc(NAME_LENGTH);
        size_t keyLen = strlen(token);
        
        strncpy(readedKey, src, ++keyLen);
        
        if (strequal(readedKey, key))
        {
            char *valuePtr = (char*)&src[keyLen];
            
            ret = strcpy(value, valuePtr) != NULL;
        }
        
        div_free(readedKey);
    }
    
    return ret;
}

static char *readStringValue(const char *filename, const char *section, const char *key, const char *defaultValue, 
    char *dest)
{
    if (!tryReadValue(filename, section, key, dest))
        dest = (char*)defaultValue;
     
    return dest;
}

static int readIntValue(const char *filename, const char *section, const char *key, int defaultValue)
{
    char *value = strmalloc(VALUE_LENGTH);
    int ret = defaultValue;
    
    if (tryReadValue(filename, section, key, value))
        ret = atoi(value);
    
    div_free(value);
    
    return ret;
}

static bool readBoolValue(const char *filename, const char *section, const char *key, bool defaultValue)
{
    char *value = strmalloc(VALUE_LENGTH);
    bool ret = defaultValue;
    
    if (tryReadValue(filename, section, key, value))
        ret = batoi(value);
    
    div_free(value);
     
    return ret;
}

static char *getSectionParam()
{
    char *str = getStringParm();
    
    return strlen(str) > 0 ? str : NULL;
}

/** Read a boolean value.
*
* @param {string} filename - INI filename.
* @param {string} section - Section name. Pass empty string "" to read root section values.
* @param {string} key - Key name.
* @param {int} defValue - Default value if key not exists.
*
* @return {int} - Returns 1 for true or 0 for false.
*/
void div_readBool()
{
    int defValue = getparm();
    char *key = getStringParm();
    char *section = getSectionParam();
    char *filename = getStringParm();
    int ret = readBoolValue(filename, section, key, defValue);

    retval(ret);
}


/** Read an integer value.
*
* @param {string} filename - INI filename.
* @param {string} section - Section name. Pass empty string "" to read root section values.
* @param {string} key - Key name.
* @param {int} defValue - Default value if key not exists.
*
* @return {int} - Returns integer value.
*/
void div_readInt()
{
    int defValue = getparm();
    char *key = getStringParm();
    char *section = getSectionParam();
    char *filename = getStringParm();
    int ret = readIntValue(filename, section, key, defValue);

    retval(ret);
}

/** Read a string value.
*
* @param {string} filename - INI filename.
* @param {string} section - Section name. Pass empty string "" to read root section values.
* @param {string} key - Key name.
* @param {string} defValue - Default value if key not exists.
* @param {string} dest - String variable to store key value.
*
* @return {string} - Returns the string value or the default one if the key not exists.
*/
void div_readString()
{
    char *dest = getStringParm();
    char *defValue = getStringParm();
    char *key = getStringParm();
    char *section = getSectionParam();
    char *filename = getStringParm();
    
    dest = readStringValue(filename, section, key, defValue, dest);

    retval((int)&dest);
}

/** Write a boolean value.
*
* @param {string} key - Key name.
* @param {int} value - Integer value to write. Even numbers are true values, odd numbers are false values.
*
* @return {int} - Returns RESULT_OK if the value is written, RESULT_ERROR if occur any error.
*/
void div_writeBool()
{
    /* int value = getparm();
    char *key = getStringParm();

    retval(ini_puts(section, key, strBool(value), filename)); */
    retval(0);
}

/** Write an integer value.
*
* @param {string} key - Key name.
* @param {int} value - Integer value to write.
*
* @return {int} - Returns RESULT_OK if the value is written, RESULT_ERROR if occur any error.
*/
void div_writeInt()
{
    /* int value = getparm();
    char *key = getStringParm();

    retval(ini_putl(section, key, (long)value, filename)); */
    retval(0);
}

/** Write a string value.
*
* @param {string} key - Key name.
* @param {string} value - String value to write.
*
* @return {int} - Returns RESULT_OK if the value is written, RESULT_ERROR if occur any error.
*/
void div_writeString()
{
    /* char *value = getStringParm();
    char *key = getStringParm();

    retval(ini_puts(section, key, value, filename)); */
    retval(0);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export("ini_read_bool",      div_readBool,      4);
    COM_export("ini_read_int",       div_readInt,       4);
    COM_export("ini_read_string",    div_readString,    5);
    COM_export("ini_write_bool",     div_writeBool,     4);
    COM_export("ini_write_int",      div_writeInt,      4);
    COM_export("ini_write_string",   div_writeString,   4);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}
