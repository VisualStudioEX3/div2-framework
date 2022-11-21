/* ----------------------------------------------------------------------------
 * Rect functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __RECT_H_
    #define __RECT_H_

    #include "_const.h"
    #include "_div2lib.h"
    #include "_math.h"

    /**
     * Rectangle struct.
     * 
     * @remarks - The struct fits the same scheme like the built-in DIV Games Studio rectangle definitions.
     */
    typedef struct _rect_t
    {
        /**
         * @return {int} - The left side of the rectangle.
         */
        int x0;

        /**
         * @return {int} - The top side of the rectangle.
         */
        int y0;

        /**
         * @return {int} - The right side of the rectangle.
         */
        int x1;

        /**
         * @return {int} - The bottom side of the rectangle.
         */
        int y1;
    } rect_t;

    /**
     * Macro to gets a {rect_t} parameter from the DIV Games Studio 2 stack.
     * 
     * @return {rect_t*} - Returns a pointer to the DIV Games Studio 2 {rect_t} struct value.
     */
    #define getRectParm() (rect_t*)getStructParm()

    /**
     * Checks if a rectangle is empty.
     * 
     * @param {rect_t*} rect - Rectangle to check.
     * 
     * @return {bool} - Returns {true} if the rectangle is empty, {false} otherwise.
     */
    bool isEmptyRect(const rect_t* rect);

    /**
     * Checks if a point is contained into a rectangle.
     * 
     * @param {int} x - X coordinate of the point.
     * @param {int} y - Y coordinate of the point.
     * @param {rect_t*} rect - Rectangle to check.
     * 
     * @return {bool} - Returns {true} if the point is contained in the rectangle, {false} otherwise.
     */
    bool pointInRect(const int x, const int y, const rect_t* rect);

    /**
     * Gets the intersection between two rectangles.
     * 
     * @param {rect_t*} rectA - First rectangle to check.
     * @param {rect_t*} rectB - Second rectangle to check.
     * @param {rect_t*} outRect - Returns the rectangle intersection.
     * 
     * @return {bool} - Returns {true} if the both rectangles intersects, {false} otherwise.
     */
    bool intersectRect(const rect_t* rectA, const rect_t* rectB, rect_t* outRect);
#endif
