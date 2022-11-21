/* ----------------------------------------------------------------------------
 * String functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __STRING_H_
    #define __STRING_H_

    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "_const.h"
    #include "_div2lib.h"

    #define STRING_TRUE		"true"      // String representation of {true} value.
    #define STRING_FALSE	"false"     // String representation of {false} value.

    /**
     * Macro that implements a string version of standard C {realloc()} function to works with DIV Games Studio 2 memory.
     * 
     * @param {string} str - Char pointer to the string to resize.
     * @param {size_t} size - New size of the string.
     * 
     * @return {string} - Returns the pointer to the resized string.
     */
    #define strrealloc(str, size) (char*)div_realloc(str, size)

    /**
     * Macro to convert all chars of a string to upper case.
     * 
     * @param {string} s - Char pointer to the string. The result is written in this pointer.
     */
    #define strupr(s) strcase(s, 0)
    
    /**
     * Macro to convert all chars of a string to lower case.
     * 
     * @param {string} s - Char pointer to the string. The result is written in this pointer.
     */
    #define strlwr(s) strcase(s, 1)

    /**
     * Macro to gets the string representation of a boolean value.
     * 
     * @param {bool} value - Boolean value, or instead int value, to convert.
     * 
     * @return {string} - Returns the string representation of the boolean value.
     * 
     * @remarks - DIV Games Studio interprets {false} as odd values and {true} as even values.
     */
    #define strbool(value) value % 2 == 0 ? STRING_FALSE : STRING_TRUE

    /**
     * Macro to check if two strings are equals.
     * 
     * @param {string} a - Left string to compare.
     * @param {string} b - Right string to compare.
     * 
     * @return {bool} - Returns true if the both strings are equals, false otherwise.
     * 
     * @remarks - This macro is a simple shortcut to standard C {strcmp()} function comparing the result with zero.
     */
    #define strequal(a, b) strcmp(a, b) == 0

    // Internal implementation for strupr and strlwr macros.
    static void strcase(string str, const int mode);

    /**
     * Custom version of {malloc()} to allocate memory for a string value in DIV Games Studio 2 memory.
     * 
     * @param {size_t} size - The size of the string value.
     * 
     * @return {string} - Returns the pointer to the new allocated string value.
     */
    string strmalloc(const size_t size);
    
    /**
     * Removes whitespace from left side of a string.
     * 
     * @param {string} str - Char pointer to the string. The result is written in this pointer.
     * 
     * @return {size_t} - Returns the new lenght of the string, or {RESULT_ERROR} if the string is {NULL} or empty.
     */
    size_t strltrim(string str);
    
    /**
     * Removes whitespace from right side of a string.
     * 
     * @param {string} str - Char pointer to the string. The result is written in this pointer.
     * 
     * @return {size_t} - Returns the new lenght of the string, or {RESULT_ERROR} if the string is {NULL} or empty.
     */
    size_t strrtrim(string str);

    /**
     * Removes whitespace from both sides of a string.
     * 
     * @param {string} str - Char pointer to the string. The result is written in this pointer.
     * 
     * @return {size_t} - Returns the new lenght of the string, or {RESULT_ERROR} if the string is {NULL} or empty.
     */
    size_t strtrim(string str);

    /**
     * Replaces all ocurrences in the string with the new char.
     * 
     * @param {string} str - Char pointer to the string. The result is written in this pointer.
     * @param {char} oldChar - The char to be replaced in the string.
     * @param {char} newChar - The char used to replaces the old chars.
     */
    void strreplace(string str, const char oldChar, const char newChar);

    /**
     * Checks if a string is empty.
     * 
     * @param {string} str - Char pointer to the string.
     * 
     * @return {bool} - Returns {true} if the string is empty (length zero), {false} otherwise.
     */
    bool strempty(const string str);

    /**
     * Converts a string representation of a boolean value to an integer value.
     * 
     * @param {string} str - Char pointer to the string.
     * 
     * @return {int} - Returns the integer representation of the boolean value (0 or 1), or {RESULT_ERROR} if the string is {NULL} or empty.
     */
    int batoi(const string str);

    /**
     * Custom implementation of standard C {strdup()} function to works with DIV Games Studio 2 memory.
     * 
     * @param {string} str - Char pointer to the string to duplicate.
     * 
     * @return {string} - Returns the pointer to the duplicated string, or {NULL} if the string is {NULL} or empty.
     * 
     * @remarks - This function works as same as standard C {strdup()} function.
     */
    string div_strdup(const string str);
#endif
