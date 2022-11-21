/* ----------------------------------------------------------------------------
 * Math functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __MATH_H_
    #define __MATH_H_
    /**
     * Macro that returns the min value bewteen 2 values.
     * 
     * @param {int} a - Left value.
     * @param {int} b - Right value.
     * 
     * @return {int} - Returns the min value between a and b values.
     */
    #define min(a, b)   a < b ? a : b

    /**
     * Macro that returns the max value bewteen 2 values.
     * 
     * @param {int} a - Left value.
     * @param {int} b - Right value.
     * 
     * @return {int} - Returns the max value between a and b values.
     */
    #define max(a, b)   a > b ? a : b

    /**
     * Macro that returns clamped value in a range.
     * 
     * @param {int} v - Value to clamp.
     * @param {int} a - Min value of the range.
     * @param {int} b - Max value of the range.
     * 
     * @return {int} - Returns the min value between a and b values.
     */
    #define clamp(v, a, b)  v < a ? a : (v > b ? b : v)

    /**
     * Macro that checks if a value is clamped into a range.
     * 
     * @param {int} v - Value to check.
     * @param {int} a - Min value of the range.
     * @param {int} b - Max value of the range.
     * 
     * @return {bool} - Returns {true} if the value is clamped, {false} otherwise.
     */
    #define isClamped(v, a, b)  v >= a && v <= b

    /**
     * Macro that interpolate linearly a value between two values.
     * 
     * @param {int} a - Start value.
     * @param {int} b - End value.
     * @param {int} t - The interpolation value between two integer values.
     *
     * @return {int} Returns the interpolated integer result between the two values.
     */
    #define lerp(a, b, t)   a + (((b - a) * t) >> 8)
#endif
