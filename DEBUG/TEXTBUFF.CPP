/* ----------------------------------------------------------------------------
 * Text circular buffer for DEBUG.DLL for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdlib.h>
#include <string.h>

#include "..\shared\_const.h"
#include "..\shared\_div2lib.h"
#include "..\shared\_string.h"
#include "textbuff.h"

static void resetBuffer(string_list_t* list)
{
    list->count = 0;
    list->first = list->last = NULL;
}

static void printNodeTextValue(string_node_t* node, int counter, void* ptr)
{
    ((print_node_callback)ptr)(node->value, 0, counter);
}

static void addNodeToTempList(string_node_t* node, int counter, void* ptr)
{
    addText((string_list_t*)ptr, node->value);
}

// Loop all current range values in the list and run actionOnItemCallback function pointer for each node.
static void loopBuffer(const string_list_t* list, void (*actionOnItemCallback)(string_node_t*, int, void*), void* ptr)
{
    int i = 0;
    int count = list->count < list->capacity ? list->count : list->capacity;

    for (string_node_t* node = list->last->next; i < count; node = node->next, i++)
        actionOnItemCallback(node, i, ptr);
}

string_list_t* createBuffer(const int capacity)
{
    string_list_t* list = (string_list_t*)div_malloc(STRING_LIST_SIZE);

    if (list)
    {
        list->capacity = capacity;
        resetBuffer(list);
    }

    return list;
}

void destroyBuffer(string_list_t* list)
{
    if (list)
    {
        clearBuffer(list);
        div_free(list);
    }
}

void addText(string_list_t* list, const string value)
{
    if (list)
    {
        string_node_t* node = NULL;

        if (list->count < list->capacity)
        {
            node = (string_node_t*)div_malloc(STRING_NODE_SIZE);

            if (node)
            {
                if (!list->first)
                    list->first = node;
                else
                    list->last->next = node;

                node->next = list->first;
                list->last = node;
                list->count++;
            }
        }
        else
        {
            node = list->last->next;
            list->last = node;
            div_free(node->value);
        }

        if (node)
            node->value = div_strdup(value);
    }
}

void clearBuffer(string_list_t* list)
{
    if (list && list->count > 0)
    {
        string_node_t* current = list->first;

        for (int i = 0; i < list->capacity; i++)
        {
            string_node_t* next = current->next;

            div_free(current->value);
            div_free(current);
            current = next;
        }

        resetBuffer(list);
    }
}

void printBuffer(const string_list_t* list, print_node_callback printTextFunc)
{
    if (list && list->count > 0)
        loopBuffer(list, printNodeTextValue, printTextFunc);
}

void copyTo(string_list_t* dst, const string_list_t* src)
{
    if (dst && src && src->count > 0)
    {
        clearBuffer(dst);
        loopBuffer(src, addNodeToTempList, dst);
    }
}
