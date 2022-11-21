/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "enums.h"
#include "action.h"

void setInputAction(input_action_t* action, 
    const string name,
    const keycode_t* primaryKey, 
    const keycode_t* secondaryKey, 
    const keycode_t* joyButton, 
    const keycode_t* shiftKey,
    int event)
{
    action->name = name;

    action->primaryKey = primaryKey;
    action->secondaryKey = secondaryKey;
    action->joyButton = joyButton;

    action->shiftKey = shiftKey;

    action->event = event;
    
    action->lastState = false;
}

bool getInputActionState(input_action_t* action)
{
    bool state = false;
    bool currentState = action->shiftKey->state && action->primaryKey->state || 
                        action->shiftKey->state && action->secondaryKey->state || 
                        action->joyButton->state;

    switch (action->event)
    {
        case EVENT_KEY_PRESS:  
            state = currentState;
            break;
        case EVENT_KEY_DOWN:
            state = !action->lastState && currentState;
            break;
        case EVENT_KEY_UP:
            state = action->lastState && !currentState;
            break;
    }

    action->lastState = currentState;

    return state;
}

void clearInputAction(input_action_t* action)
{
    memset(action, NULL, INPUT_ACTION_SIZE);
}
