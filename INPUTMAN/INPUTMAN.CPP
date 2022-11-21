/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "inputman.h"


void __export divlibrary(LIBRARY_PARAMS)
{
    //COM_export("get_input_actions_count", div_getCount, 0);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}
