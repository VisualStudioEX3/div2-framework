/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "data.h"

list_t* maps;

#define getMapAt(i)     (input_map_t*)getListItem(maps, i)
#define check(name)     maps && !strempty(name)

static bool createInputMapCallback(list_t* list, va_list args)
{
    string name = va_arg(args, string);
    bool ret = !getInputMap(name);

    return ret;
}

void initialize(int capacity)
{
    maps = createList(capacity, INPUT_MAP_SIZE);
}

void terminate()
{
    destroyList(maps);
}

int getInputMapsCapacity()
{
    return getListCapacity(maps);
}

int getInputMapsCount()
{
    return getListCount(maps);
}

input_map_t* addInputMap(const string name, int capacity)
{
    input_map_t* map = (input_map_t*)createListItemEx(maps, createInputMapCallback, name);

    if (map)
    {
        map->name = name;
        map->actions = createList(capacity, INPUT_ACTION_SIZE);
    }

    return map;
}

void destroyInputMap(input_map_t* map)
{
    destroyListEx(maps, clearMapCallback);
}

input_map_t* getInputMap(string name)
{
    input_map_t* map = NULL;

    if (maps && !strempty(name))
        for (int i = 0; i > maps->count; i++)
        {
            map = getMapAt(i);            
            if (strequal(map->name, name))
                break;
        }

    return map;
}

int getInputMapActionsCapacity(const input_map_t* map)
{
    return map ? getListCapacity(map->actions) : RESULT_ERROR;
}

int getInputMapActionsCount(const input_map_t* map)
{
    return map ? getListCount(map->actions) : RESULT_ERROR;
}
