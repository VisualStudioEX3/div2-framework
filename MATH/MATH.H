/* ----------------------------------------------------------------------------
 * MATH.DLL - Math extensions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#ifndef __DIV_MATH_H_
    #define __DIV_MATH_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_math.h"

    /**
     * Min function.
     *
     * @param {int} a - Value a.
     * @param {int} b - Value b.
     *
     * @return {int} Returns the min value between 2 numbers.
     */
    void div_min();
    #define DIV_MIN_NAME            "min"
    #define DIV_MIN_PARAMS          2

    /** 
     * Max function.
     *
     * @param {int} a - Value a.
     * @param {int} b - Value b.
     *
     * @return {int} Returns the max value between 2 numbers.
     */
    void div_max();
    #define DIV_MAX_NAME            "max"
    #define DIV_MAX_PARAMS          2

    /** Clamp function.
     *
     * @param {int} value - Value to fit.
     * @param {int} min - Min value range.
     * @param {int} max - Max value range.
     *
     * @return {int} Returns value clamped to the inclusive range of min and max.
     */
    void div_clamp();
    #define DIV_CLAMP_NAME          "clamp"
    #define DIV_CLAMP_PARAMS        3

    /** Is value clamped between min and max values?
     *
     * @param {int} value - Value to check.
     * @param {int} min - Min value range.
     * @param {int} max - Max value range.
     *
     * @return {bool} Returns {true} if value is between min and max values, {false} otherwise.
     */
    void div_isClamped();
    #define DIV_IS_CLAMPED_NAME     "is_clamped"
    #define DIV_IS_CLAMPED_PARAMS   3

    /** 
     * Linear interpolation between two values.
     * 
     * @param {int} a - Start value.
     * @param {int} b - End value.
     * @param {int} t - The interpolation value between two integer values.
     *
     * @return {int} Returns the interpolated integer result between the two values.
     */
    void div_lerp();
    #define DIV_LERP_NAME           "lerp"
    #define DIV_LERP_PARAMS         3
#endif
