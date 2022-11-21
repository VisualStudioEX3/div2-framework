/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_INPUTMAP_H_
    #define __DIV_INPUTMAP_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_string.h"
    #include "..\shared\_list.h"
    #include "keycodes.h"
    #include "action.h"

    typedef struct _input_map_t
    {
        string name;
        list_t* actions;
    } input_map_t;

    #define INPUT_MAP_SIZE      sizeof(input_map_t)

    bool isInputMapEmpty(const input_map_t* map);
    bool isInputMapFull(const input_map_t* map);
    int getInputMapCapacity(const input_map_t* map);
    int getInputMapCount(const input_map_t* map);
    void initializeInputMap(input_map_t* map, const string name, int capacity);
    void clearInputMap(input_map_t* map);
    input_action_t* addInputMapAction(input_map_t* map, 
        const string name, 
        const keycode_t* primaryKey, 
        const keycode_t* secondaryKey, 
        const keycode_t* joyButton, 
        const keycode_t* shiftKey,
        int event);
    input_action_t* getInputMapAction(input_map_t* map, const string name);
#endif
