/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_INPUT_ACTION_H_
    #define __DIV_INPUT_ACTION_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_math.h"
    #include "..\shared\_string.h"
    #include "keycodes.h"

    typedef struct _input_action_t
    {
        string name;
        const keycode_t* primaryKey;
        const keycode_t* secondaryKey;
        const keycode_t* joyButton;
        const keycode_t* shiftKey;
        int event;
        bool lastState;
    } input_action_t;

    #define INPUT_ACTION_SIZE           sizeof(input_action_t)

    void setInputAction(input_action_t* action, 
        const string name,
        const keycode_t* primaryKey, 
        const keycode_t* secondaryKey, 
        const keycode_t* joyButton, 
        const keycode_t* shiftKey,
        int event);
    bool getInputActionState(input_action_t* action);
    void clearInputAction(input_action_t* action);
#endif
