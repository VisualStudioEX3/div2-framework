/* ----------------------------------------------------------------------------
 * Fixed size aligned memory list for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdlib.h>
#include <string.h>
#include "_math.h"
#include "_list.h"

static list_item_t* getItemPointer(const list_t* list, int index)
{
    return &list->items[index * list->itemSize];
}

int getListCapacity(const list_t* list)
{
    return list ? list->capacity : RESULT_ERROR;
}

int getListCount(const list_t* list)
{
    return list ? list->count : RESULT_ERROR;
}

bool isListEmpty(const list_t* list)
{
    return list ? list->count <= 0 : false;
}

bool isListFull(const list_t* list)
{
    return list ? list->count == list->capacity : false;
}

list_t* createList(int capacity, size_t itemSize)
{
    list_t* list = NULL;

    if (capacity > 0 && itemSize > 0)
    {
        list = (list_t*)div_malloc(LIST_SIZE);

        if (list)
        {
            list->capacity = capacity;
            list->count = 0;
            list->itemSize = itemSize;
            list->items = (list_item_t*)div_malloc(list->capacity * list->itemSize);
        }
    }

    return list;
}

void clearList(list_t* list)
{
    clearListEx(list, NULL);
}

void clearListEx(list_t* list, clear_list_item_callback onItem)
{
    if (!isListEmpty(list))
    {
        if (onItem)
            for (int i = 0; i < list->count; i++)
                onItem(getItemPointer(list, i));
        
        list->count = 0;
    }
}

void destroyList(list_t* list)
{
    destroyListEx(list, NULL);
}

void destroyListEx(list_t* list, clear_list_item_callback onItem)
{
    if (list)
    {
        clearListEx(list, onItem);
        div_free(list->items);
        div_free(list);
    }
}

list_item_t* createListItem(list_t* list)
{
    return createListItemEx(list, NULL);
}

list_item_t* createListItemEx(list_t* list, create_list_item_callback onBeforeCreate, ...)
{
    va_list args;
    list_item_t* item = NULL;
    bool canCreate = true;

    if (!isListFull(list))
    {
        if (onBeforeCreate)
        {
            va_start(args, onBeforeCreate);
            canCreate = onBeforeCreate(list, args);
            va_end(args);
        }
        
        if (canCreate)
        {
            item = getItemPointer(list, list->count);
            list->count++;
        }
    }

    return item;
}

list_item_t* getListItem(const list_t* list, int index)
{
    list_item_t* item = NULL;

    if (!isListEmpty(list) && isClamped(index, 0, list->count - 1))
        item = getItemPointer(list, index);

    return item;
}

void forEachList(list_t* list, foreach_list_item_callback onItem, ...)
{
    va_list args;

    if (!isListEmpty(list) && onItem)
    {
        va_start(args, onItem);

        for (int i = 0; i < list->count; i++)
            onItem(i, getItemPointer(list, i), args);
        
        va_end(args);
    }
}

list_item_t* findListItem(list_t* list, find_list_item_callback predicate, ...)
{
    list_item_t* item = NULL;
    va_list args;

    if (!isListEmpty(list) && predicate)
    {
        va_start(args, predicate);
        
        for (int i = 0; i < list->count; i++)
        {
            list_item_t* iter = getListItem(list, i);
            
            if (predicate(iter, args))
            {
                item = iter;
                
                break;
            }
        }

        va_end(args);
    }

    return item;
}
