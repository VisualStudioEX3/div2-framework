/* ----------------------------------------------------------------------------
 * MATH.DLL - Math extensions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "math.h"

void div_min()
{
    int b = getparm();
    int a = getparm();
    bool ret = min(a, b);

    retval(ret);
}

void div_max()
{
    int b = getparm();
    int a = getparm();
    bool ret = max(a, b);

    retval(ret);
}

void div_clamp()
{
    int max = getparm();
    int min = getparm();
    int value = getparm();
    int ret = clamp(value, min, max);

    retval(ret);
}

void div_isClamped()
{
    int max = getparm();
    int min = getparm();
    int value = getparm();
    int ret = isClamped(value, min, max);

    retval(ret);
}

void div_lerp()
{
	int t = getparm();
	int b = getparm();
	int a = getparm();
    int ret = lerp(a, b, t);
	
	retval(ret);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_MIN_NAME,        div_min,        DIV_MIN_PARAMS);
    COM_export(DIV_MAX_NAME,        div_max,        DIV_MAX_PARAMS);
    COM_export(DIV_CLAMP_NAME,      div_clamp,      DIV_CLAMP_PARAMS);
    COM_export(DIV_IS_CLAMPED_NAME, div_isClamped,  DIV_IS_CLAMPED_PARAMS);
	COM_export(DIV_LERP_NAME,		div_lerp,		DIV_LERP_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}
