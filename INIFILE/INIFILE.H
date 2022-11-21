/* ----------------------------------------------------------------------------
 * INIFILE.DLL - INI parser for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#ifndef __DIV_INI_FILE_H_
#define __DIV_INI_FILE_H_

#include <stdio.h>

#include "..\shared\_const.h"
#include "..\shared\_div2lib.h"
#include "..\shared\_string.h"

#define NAME_LENGTH					16
#define VALUE_LENGTH				256
#define LINE_LENGTH					NAME_LENGTH + VALUE_LENGTH + 1
		
#define COMMENT_CHAR				';'
#define SECTION_OPEN_CHAR			'['
#define SECTION_CLOSE_CHAR			']'
#define FIELD_DELIMITER_CHAR		"=" // As string instead of char to able pass as char pointer.
	
#define COMMENT_LINE_TEMPLATE		COMMENT_CHAR + " %s"
#define SECTION_TEMPLATE			SECTION_OPEN_CHAR + "%s" + SECTION_CLOSE_CHAR
#define FIELD_NAME_TEMPLATE			"%s" + FIELD_DELIMITER_CHAR
#define STRING_FIELD_TEMPLATE		FIELD_NAME_TEMPLATE + "%s"
#define INTEGER_FIELD_TEMPLATE		FIELD_NAME_TEMPLATE + "%i"
#define BOOL_FIELD_TEMPLATE			STRING_FIELD_TEMPLATE	// Writes "true" or "false".

#define isCommentLine(str) 		    str[0] == COMMENT_CHAR
#define isSectionHeader(str) 		str[0] == SECTION_OPEN_CHAR && str[strlen(str) - 1] == SECTION_CLOSE_CHAR
#define isEmptyLine(str) 			!str || strempty(str) || isCommentLine(str)

static bool tryReadValue(const char *filename, const char *section, const char *key, char *value);
static bool tryReadLine(FILE *file, char *dest);
static bool checkSectionHeader(const char *src, const char *section);
static bool tryGetKeyParValueInSection(FILE *file, const char *key, char *value);
static bool tryGetKeyParValue(const char *src, const char *key, void *value);
static char *readStringValue(const char *filename, const char *section, const char *key, const char *defaultValue, char *dest);
static int readIntValue(const char *filename, const char *section, const char *key, int defaultValue);
static bool readBoolValue(const char *filename, const char *section, const char *key, bool defaultValue);
static void writeStringValue(const char *filename, const char *section, const char *key, const char *value);
static void writeIntValue(const char *filename, const char *section, const char *key, int value);
static void writeBoolValue(const char *filename, const char *section, const char *key, bool value);
static char *getSectionParam();

void div_iniReadBool();
void div_iniReadInt();
void div_iniReadString();
void div_iniWriteBool();
void div_iniWriteInt();
void div_iniWriteString();

#endif
