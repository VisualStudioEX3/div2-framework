/* ----------------------------------------------------------------------------
 * Fixed size memory-linear dictionary for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdarg.h>
#include "_const.h"
#include "_div2lib.h"
#include "_list.h"

#ifndef __DICTIONARY_H_
    #define __DICTIONARY_H_

    typedef struct _dictionary_node_t
    {
        void* _key;
        byte* _value;
    } dictionary_node_t;

    typedef struct _dictionary_t
    {
        list_t* list;
        size_t itemSize;
    } dictionary_t;

    #define DICTIONARY_SIZE     sizeof(dictionary_t)

    typedef void (*foreach_dictionary_item_callback)(void*, byte*, va_list);

    int getDictionaryCapacity(const dictionary_t* dictionary);
    int getDictionaryCount(const dictionary_t* dictionary);
    bool isDictionaryEmpty(const dictionary_t* dictionary);
    bool isDictionaryFull(const dictionary_t* dictionary);
    dictionary_t createDictionary(int capacity, size_t itemSize);
    void destroyDictionary(dictionary_t* dictionary);
    void clearDictionary(dictionary_t* dictionary);
    byte* createDictionaryItem(dictionary_t* dictionary, void* keyValue);
    byte* getDictionaryItem(const dictionary_t* dictionary, void* keyValue);
    byte* getDictionaryItemAt(const dictionary_t* dictionary, int index);
    bool existDictionaryItemKey(const dictionary_node_t* dictionary, void* keyValue);
    void forEachDictionary(dictionary_t* dictionary, foreach_dictionary_item_callback onItem, ...);
#endif
