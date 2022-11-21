/* ----------------------------------------------------------------------------
 * DEBUG.DLL - Debug functions for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#ifndef __DIV_DEBUG_H_
    #define __DIV_DEBUG_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_string.h"
    #include "textbuff.h"

    #define SCREEN_HEIGHT       height      // Current DIV Games Studio screen height.
    #define TEXT_LINE_HEIGHT    10          // Default font line size.

    /** 
     * Prints a text string in the screen.
     * 
     * @param {string} text - String value to write.
     * 
     * @return {int} - Always returns {RESULT_OK}.
     *
     * @remarks - This function works like the PRINT command in BASIC interpreters, writing a text string starting in the top of the screen, 
     * and continue line per line downwards, moving to up the previous text strings when filled the screen in the botton side, like a terminal.
     */
    void div_print();
    #define DIV_PRINT_NAME                          "print"
    #define DIV_PRINT_PARAMS                        1

    /** 
     * Clears all text strings in the screen.
     * 
     * @return {int} - Always returns {RESULT_OK}.
     */
    void div_cls();
    #define DIV_CLS_NAME                            "cls"
    #define DIV_CLS_PARAMS                          0

    /** 
     * Refresh the screen text buffer.
     *
     * @remarks - Use this function when set a new viedeo mode in order to create a text buffer size according to the new video mode screen size.
     * 
     * @return {int} - Always returns {RESULT_OK}.
     */
    void div_refreshScreenTextBuffer();
    #define DIV_REFRESH_SCREEN_TEXT_BUFFER_NAME     "refresh_text_screen"
    #define DIV_REFRESH_SCREEN_TEXT_BUFFER_PARAMS   0

    /**
     * Updates the screen text content.
     * 
     * @return {int} - Always returns {RESULT_OK}.
     * 
     * @remarks By default, this DLL updates screen on every frame using the {post_process_buffer} DIV Games Studio entry point.
     * Call this function one time per game frame in case another DLL overwrites the {post_process_buffer} DIV Games Studio entry point.
     */
    void div_frame();
    #define DIV_FRAME_NAME                          "frame_debug"
    #define DIV_FRAME_PARAMS                        0
#endif
