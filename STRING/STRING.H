/* ----------------------------------------------------------------------------
 * STRING.DLL - String extensions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#ifndef __DIV_MATH_H_
    #define __DIV_MATH_H_

    #include "..\shared\_div2lib.h"
    #include "..\shared\_string.h"

    /** 
     * Removes whitespace from left side of a string.
     *
     * @param {string} str - String to trim.
     *
     * @return {int} - Returns the new string length.
     */
    void div_strltrim();
    #define DIV_STRLTRIM_NAME   "strltrim"
    #define DIV_STRLTRIM_PARAMS 1

    /** 
     * Removes whitespace from right side of a string.
     *
     * @param {string} str - String to trim.
     *
     * @return {int} - Returns the new string length.
     */
    void div_strrtrim();
    #define DIV_STRRTRIM_NAME   "strrtrim"
    #define DIV_STRRTRIM_PARAMS 1

    /** 
     * Removes whitespace from both sides of a string.
     *
     * @param {string} str - String to trim.
     *
     * @return {int} - Returns the new string length.
     */
    void div_strtrim();
    #define DIV_STRTRIM_NAME    "strtrim"
    #define DIV_STRTRIM_PARAMS  1

    /** 
     * Converts string expression to integer value.
     *
     * @param {string} str - String value to convert.
     *
     * @return {int} - Returns the integer value converted from the string value.
     */
    void div_atoi();
    #define DIV_ATOI_NAME       "atoi"
    #define DIV_ATOI_PARAMS     1
#endif