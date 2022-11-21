/* ----------------------------------------------------------------------------
 * Linked list for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdlib.h>
#include <string.h>
#include "_list.h"
#include "_math.h"

static bool _isValidList(const list_t* list)
{
    return list && list->count >= 0;
}

static bool _isValidIndex(const list_t* list, int index)
{
    return isClamped(index, 0, list->count - 1);
}

static void _resetList(list_t* list)
{
    list->first = list->last = list->iterator = NULL;
    list->count = 0;
}

static list_item_t* _createListItem(void* value, list_item_t* next)
{
    list_item_t* item = (list_item_t*)malloc(LIST_ITEM_SIZE);

    if (item)
    {
        item->value = value;
        item->next = next;
    }

    return item;
}

static bool _checkItemByRefConditionCallback(list_item_t* item, void* value, int atIndex, int currentIndex)
{
    return item && value != item->value;
}

static bool _checkItemAtIndexConditionCallback(list_item_t* item, void* value, int atIndex, int currentIndex)
{
    return currentIndex < atIndex;
}

static void _onRemoveListItemActionCallback(list_t* list, list_item_t* previous, list_item_t* current, void* value)
{
    if (previous)
        previous->next = current->next;
    else
        list->first = current->next;

    free(current);

    list->count--;
    list->iterator = list->first;
}

static void _onInsertListItemActionCallback(list_t* list, list_item_t* previous, list_item_t* current, void* value)
{
    list_item_t* item = _createListItem(value, current);

    if (previous)
        previous->next = item;
    else
        list->first = item;

    list->count++;
    list->iterator = list->first;
}

static list_item_t* _localizeListItemAndDoAction(
    list_t* list, 
    void* value, 
    int atIndex, 
    bool (*onConditionCallback)(list_item_t*, void*, int, int),
    void (*onItemLocalizedCallback)(list_t*, list_item_t*, list_item_t*, void*)
)
{
    list_item_t* current = list->first;
    list_item_t* previous = NULL;
    int currentIndex = 0;

    while ((onConditionCallback)(current, value, atIndex, currentIndex))
    {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    (onItemLocalizedCallback)(list, previous, current, value);

    return current;
}

static bool _internalRemoveListItem(list_t* list, void* value, int atIndex, bool (*conditionCallback)(list_item_t*, void*, int, int))
{
    return _localizeListItemAndDoAction(list, value, atIndex, conditionCallback, &_onRemoveListItemActionCallback) != NULL;
}

list_t* createList()
{
    list_t* list = (list_t*)malloc(LIST_SIZE);

    _resetList(list);

    return list;
}

bool destroyList(list_t* list)
{
    bool ret = false;

    if (_isValidList(list))
    {
        clearList(list);
        free(list);
        ret = true;
    }

    return ret;
}

int getListCount(const list_t* list)
{
    return _isValidList(list) ? list->count : -1;
}

bool isListEmpty(const list_t* list)
{
    return _isValidList(list) && !list->first;
}

int addListItem(list_t* list, void* value)
{
    int index = -1;

    if (_isValidList(list))
    {
        list_item_t* item = _createListItem(value, NULL);

        if (!list->first)
            list->first = item;
        else
            list->last->next = item;

        index = list->count;
        list->count++;
        list->last = item;
        list->iterator = list->first;
    }

    return index;
}

bool insertListItemAt(list_t* list, void* value, int index)
{
    bool ret = false;

    if (_isValidList(list) && _isValidIndex(list, index))
    {
        if (isListEmpty(list) || index == list->count - 1)
            ret = addListItem(list, value) != NULL;
        else
            ret = _localizeListItemAndDoAction(list, value, index, 
                &_checkItemAtIndexConditionCallback, 
                &_onInsertListItemActionCallback) != NULL;
    }

    return ret;
}

int findListItem(list_t* list, const void* item)
{
    int ret = -1;

    if (_isValidList(list) && !isListEmpty(list))
    {
        list_item_t* current = list->first;

        for (int i = 0; i < list->count; i++)
            if (current->value == item)
            {
                ret = i;
                break;
            }
            else
                current = current->next;
    }

    return ret;
}

void* getListItem(const list_t* list, int index)
{
    void* value = NULL;

    if (_isValidList(list) && !isListEmpty(list) && _isValidIndex(list, index))
    {
        list_item_t* current = list->first;

        for (int i = 0; i < index; i++)
            current = current->next;

        value = current->value;
    }

    return value;
}

void* getFirstListItem(list_t* list)
{
    void* value = NULL;

    if (_isValidList(list) && !isListEmpty(list))
    {
        list->iterator = list->first;
        value = list->iterator->value;
        list->iterator = list->iterator->next;
    }

    return value;
}

void* getNextListItem(list_t* list)
{
    void* value = NULL;

    if (_isValidList(list) && list->iterator)
    {
        value = list->iterator->value;
        list->iterator = list->iterator->next;
    }

    return value;
}

bool removeListItem(list_t* list, void* value)
{
    bool ret = false;

    if (value && _isValidList(list) && !isListEmpty(list))
        ret = _internalRemoveListItem(list, value, 0, &_checkItemByRefConditionCallback);

    return ret;
}

bool removeListItemAt(list_t* list, int index)
{
    bool ret = false;

    if (_isValidList(list) && !isListEmpty(list) && _isValidIndex(list, index))
        ret = _internalRemoveListItem(list, NULL, index, &_checkItemAtIndexConditionCallback);

    return ret;
}

bool clearList(list_t* list)
{
    bool ret = false;

    if (_isValidList(list))
    {
        list->iterator = list->first;

        while (list->iterator)
        {
            list_item_t* next = list->iterator->next;
            
            free(list->iterator);
            list->iterator = next;
        }

        _resetList(list);
        ret = true;
    }

    return ret;
}
