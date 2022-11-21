/* ----------------------------------------------------------------------------
 * RECT.DLL - Rectangle functions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#ifndef __DIV_RECT_H_
    #define __DIV_RECT_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_rect.h"

    /** 
     * Is an empty rectangle?
     *
     * @param {int} rect - Pointer to a rectangle struct.
     *
     * @return {bool} Returns {true} the rectangle is empty, {false} otherwise.
     */
    void div_isRectEmpty();
    #define DIV_IS_RECT_EMPTY_NAME          "is_rect_empty"
    #define DIV_IS_RECT_EMPTY_PARAMS        1

    /** Is point inside of a rectangle?
    *
    * @param {int} x - X coordinate.
    * @param {int} y - Y coordinate.
    * @param {int} rect - Pointer to a rectangle struct.
    *
    * @return {bool} Returns {true} the rectangle is empty, {false} otherwise.
    */
    void div_pointInRect();
    #define DIV_POINT_IN_RECT_NAME          "point_in_rect"
    #define DIV_POINT_IN_RECT_PARAMS        3

    /** 
     * Checks if the both rectangles collides.
     *
     * @param {int} a - Pointer to the first rectangle struct.
     * @param {int} b - Pointer to the second rectangle struct.
     *
     * @return {bool} Returns {true} if the both rectangles are collided, {false} otherwise.
     */
    void div_intersectRect();
    #define DIV_INTERSECT_RECT_NAME         "rect_collision"
    #define DIV_INTERSECT_RECT_PARAMS       2

    /** 
     * Checks if the first rectangle intersect the second one and gets the rectangle difference.
     *
     * @param {int} a - Pointer to the first rectangle struct.
     * @param {int} b - Pointer to the second rectangle struct.
     * @param {int} i - Pointer to the rectangle struct to store the rectangle intersection between both rectangles.
     *
     * @return {bool} Returns {true} if the first rectangle intersects the second one, {false} otherwise.
     */
    void div_intersectRectEx();
    #define DIV_INTERSECT_RECT_EX_NAME      "intersect_rect"
    #define DIV_INTERSECT_RECT_EX_PARAMS    3
#endif
