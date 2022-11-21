/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "map.h"

static bool createInputMapActionCallback(list_t* list, va_list args)
{
    string name = va_arg(args, string);
    bool ret = !getInputMapAction((input_map_t*)list, name);

    return ret;
}

static void clearInputActionCallback(list_item_t* item)
{
    clearInputAction((input_action_t*)item);
}

static bool findInputMapActionCallback(list_item_t* item, va_list args)
{
    input_action_t* action = (input_action_t*)item;
    string name = va_arg(args, string);
    bool match = strequal(name, action->name);

    return match;
}

bool isInputMapEmpty(const input_map_t* map)
{
    return isListEmpty(map->actions);
}

bool isInputMapFull(const input_map_t* map)
{
    return isListFull(map->actions);
}

int getInputMapCapacity(const input_map_t* map)
{
    return getListCapacity(map->actions);
}

int getInputMapCount(const input_map_t* map)
{
    return getListCount(map->actions);
}

void initializeInputMap(input_map_t* map, const string name, int capacity)
{
    map->name = name;
    map->actions = createList(capacity, INPUT_ACTION_SIZE);
}

void clearInputMap(input_map_t* map)
{
    map->name = NULL;
    clearListEx(map->actions, clearInputActionCallback);
}

input_action_t* addInputMapAction(input_map_t* map, const string name, 
    const keycode_t* primaryKey, 
    const keycode_t* secondaryKey, 
    const keycode_t* joyButton, 
    const keycode_t* shiftKey,
    int event)
{
    input_action_t* action = (input_action_t*)createListItemEx(
        map->actions, createInputMapActionCallback, name);

    setInputAction(action, name, primaryKey, secondaryKey, joyButton, shiftKey, event);

    return action;
}

input_action_t* getInputMapAction(input_map_t* map, const string name)
{
    input_action_t* action = NULL;

    if (!strempty(name))
        action = (input_action_t*)findListItem(map->actions, findInputMapActionCallback, name);

    return action;
}
