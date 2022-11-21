/* ----------------------------------------------------------------------------
 * Rect functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "_rect.h"

bool isEmptyRect(const rect_t* rect)
{
    return rect && !(rect->x0 < rect->x1 && rect->y0 < rect->y1);
}

bool pointInRect(const int x, const int y, const rect_t* rect)
{
    return rect && (x >= rect->x0 && y >= rect->y0 && x <= rect->x1 && y <= rect->y1);
}

bool intersectRect(const rect_t* rectA, const rect_t* rectB, rect_t* outRect)
{
    bool ret = false;

    if (rectA && rectB)
    {
        rect_t intr;

        intr.x0	= max(rectA->x0, rectB->x0);
        intr.y0 = max(rectA->y0, rectB->y0);
        intr.x1	= min(rectA->x1, rectB->x1);
        intr.y1	= min(rectA->y1, rectB->y1);

        ret = !isEmptyRect(&intr);

        if (ret && outRect)
        {
            outRect->x0 = intr.x0;
            outRect->y0 = intr.y0;
            outRect->x1 = intr.x1;
            outRect->y1 = intr.y1;
        }
    }
    
    return ret;
}
