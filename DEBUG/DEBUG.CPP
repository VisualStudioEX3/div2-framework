/* ----------------------------------------------------------------------------
 * DEBUG.DLL - Debug functions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#include "debug.h"

string_list_t* screenBuffer = NULL;

#define createNewBuffer()   createBuffer(SCREEN_HEIGHT / TEXT_LINE_HEIGHT)

static void printTextLine(const string text, int x, int y)
{
    div_text_out((string)text, 0, y * TEXT_LINE_HEIGHT);
}

static void onPostProcessBufferCallback()
{
    printBuffer(screenBuffer, &printTextLine);
}

void div_print()
{
    string str = getStringParm();
    
    addText(screenBuffer, str);
    
    retval(RESULT_OK);
}

void div_cls()
{
    clearBuffer(screenBuffer);
    
    retval(RESULT_OK);
}

void div_refreshScreenTextBuffer()
{
    string_list_t* newBuffer = createNewBuffer();

    copyTo(newBuffer, screenBuffer);
    destroyBuffer(screenBuffer);
    screenBuffer = newBuffer;
    
    retval(RESULT_OK);
}

void div_frame()
{
    onPostProcessBufferCallback();

    retval(RESULT_OK);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_PRINT_NAME,  div_print,  DIV_PRINT_PARAMS);
    COM_export(DIV_CLS_NAME,    div_cls,    DIV_CLS_PARAMS);
    COM_export(DIV_REFRESH_SCREEN_TEXT_BUFFER_NAME, 
               div_refreshScreenTextBuffer,    
               DIV_REFRESH_SCREEN_TEXT_BUFFER_PARAMS);
    COM_export(DIV_FRAME_NAME,  div_frame,  DIV_FRAME_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();    
    DIV_export("post_process_buffer", onPostProcessBufferCallback);
    
    screenBuffer = createNewBuffer();
}

void __export divend(COMMON_PARAMS)
{
    destroyBuffer(screenBuffer);
}
