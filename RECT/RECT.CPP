/* ----------------------------------------------------------------------------
 * RECT.DLL - Rectangle functions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "rect.h"

void div_isEmptyRect()
{
    rect_t* rect = getRectParm();
    bool ret = isEmptyRect(rect);
    
    retval(ret);
}

void div_pointInRect()
{
    rect_t* rect = getRectParm();
    int y = getparm();
    int x = getparm();
    bool ret = pointInRect(x, y, rect);
    
    retval(ret);
}

void div_intersectRect()
{
    rect_t* rectB = getRectParm();
    rect_t* rectA = getRectParm();
    bool ret = intersectRect(rectA, rectB, NULL);
    
    retval(ret);
}

void div_intersectRectEx()
{
    rect_t* outRect = getRectParm();
    rect_t* rectB = getRectParm();
    rect_t* rectA = getRectParm();
    bool ret = intersectRect(rectA, rectB, outRect);
    
    retval(ret);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_IS_RECT_EMPTY_NAME,      div_isEmptyRect,        DIV_IS_RECT_EMPTY_PARAMS);
    COM_export(DIV_POINT_IN_RECT_NAME,      div_pointInRect,        DIV_POINT_IN_RECT_PARAMS);
    COM_export(DIV_INTERSECT_RECT_NAME,     div_intersectRect,      DIV_INTERSECT_RECT_PARAMS);
    COM_export(DIV_INTERSECT_RECT_EX_NAME,  div_intersectRectEx,    DIV_INTERSECT_RECT_EX_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}
