/* ----------------------------------------------------------------------------
 * STRING.DLL - String extensions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "string.h"

void div_strltrim()
{
    string str = getStringParm();
    int len = strltrim(str);
    
    retval(len);
}

void div_strrtrim()
{
    string str = getStringParm();
    int len = strrtrim(str);
    
    retval(len);
}

void div_strtrim()
{
    string str = getStringParm();
    int len = strtrim(str);
    
    retval(len);
}

void div_atoi()
{
    string str = getStringParm();
    int ret = atoi(str);
    
    retval(ret);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_STRLTRIM_NAME,   div_strltrim,   DIV_STRLTRIM_PARAMS);
    COM_export(DIV_STRRTRIM_NAME,   div_strrtrim,   DIV_STRRTRIM_PARAMS);
    COM_export(DIV_STRTRIM_NAME,    div_strtrim,    DIV_STRTRIM_PARAMS);
    COM_export(DIV_ATOI_NAME,       div_atoi,       DIV_ATOI_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}
