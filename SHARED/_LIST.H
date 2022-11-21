/* ----------------------------------------------------------------------------
 * Fixed size aligned memory list for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdarg.h>
#include "_const.h"
#include "_div2lib.h"

#ifndef __LIST_H_
    #define __LIST_H_

    /**
     * List item type on {list_t} lists.
     * 
     * @remarks Defines the generic type used to represent an item in a {list_t} list.
     */
    typedef byte list_item_t;

    /**
     * Fixed typed capacity aligned memory list.
     * 
     * @remarks Represents a list with fixed capacity. The list allocated all memory 
     * aligned since is created used to store each item data instead of a single 
     * pointer to source, in fact, the list works as a data container, like an array.
     */
    typedef struct _list_t
    {
        /**
         * List capacity.
         * 
         * @return {int} - The max number of elements that can storage the list. 
         */
        int capacity;

        /**
         * Items count.
         * 
         * @return {int} - The current number of elements stored in the list.
         */
        int count;

        /**
         * Item size.
         * 
         * @return {size_t} - The size of the each element in the list.
         * 
         * @remarks This value is used allocated the memory when the list is created
         * and to read the position of each item in the list using his index.
         */
        size_t itemSize;

        /**
         * Items reserved allocated memory.
         * 
         * @return {list_item_t*} - Pointer to the first item in the reserved memory.
         */
        list_item_t* items;
    } list_t;

    /**
     * The size of the {list_t} struct.
     * 
     * @return {size_t} - Returns the size of the {list_t} struct.
     * 
     * @remarks This value not include the size of the memory reserved by the list.
     */
    #define LIST_SIZE       sizeof(list_t)

    /**
     * Callback delegate to define an action to execute in each item when clear a list.
     * 
     * @param {list_item_t*} - The pointer to the item.
     */
    typedef void (*clear_list_item_callback)(list_item_t*);

    /**
     * Callback predicate to define an action to execute before the item is created.
     * 
     * @param {list_t*} - Pointer to the list.
     * @param {va_list} - Variable argument list.
     * 
     * @return {bool} - Returns {true} to create the item, {false} otherwise.
     */
    typedef bool (*create_list_item_callback)(list_t*, va_list);

    /**
     * Callback delegate to define an action to execute for each item in the list.
     * 
     * @param {int} - Index of the item.
     * @param {list_item_t*} - Pointer to the item.
     * @param {va_list} - Variable argument list.
     */
    typedef void (*foreach_list_item_callback)(int, list_item_t*, va_list);

    /**
     * Callback predicate to define an action to check if an item match with a condition.
     * 
     * @param {list_item_t*} - Pointer to the list item.
     * @param {va_list} - Variable argument list.
     * 
     * @return {bool} - Returns {true} if the predicate match an item, {false} otherwise.
     */
    typedef bool (*find_list_item_callback)(list_item_t*, va_list);

    /**
     * Gets the max number of items that can be stored in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {int} - Returns the capacity or {RESULT_ERROR} if the list is {NULL}.
     */
    int getListCapacity(const list_t* list);

    /**
     * Gets the number of items stored in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {int} - Returns the number of items stored or {RESULT_ERROR} if the 
     * list is {NULL}.
     */
    int getListCount(const list_t* list);

    /**
     * Gets if the list is empty.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {int} - Returns {true} if the list is empty, {false} otherwise.
     */
    bool isListEmpty(const list_t* list);

    /**
     * Gets if the list is full.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {int} - Returns {true} if the list is full, {false} otherwise.
     */
    bool isListFull(const list_t* list);

    /**
     * Creates a new list.
     * 
     * @param {int} capacity - Max number of items that can be stored.
     * @param {size_t} itemSize - The size in bytes of the item type.
     * 
     * @return {list_t*} - Returns the pointer to the new list, or {NULL} if the 
     * {$capacity} and/or {$itemSize} is zero or below.
     */
    list_t* createList(int capacity, size_t itemSize);

    /**
     * Clears the content of the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @remarks This function reset the list counter to zero allowing to reuse the 
     * list for store new items. This function not free the memory used by the list.
     */
    void clearList(list_t* list);

    /**
     * Clears the content of the list and execute a callback on each item of the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {clear_list_item_callback} onItem - Callback to execute on each item.
     * 
     * @remarks Like the {clearList()} function, this function only reset the counter to 
     * zero, but allow to execute a callback on each item in the list (e.g. free memory 
     * of a inner pointer).
     */
    void clearListEx(list_t* list, clear_list_item_callback onItem);

    /**
     * Destroys the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @remarks This function free the memory ocuped by the list and by the pointer 
     * itself.
     */
    void destroyList(list_t* list);

    /**
     * Destroys the list and execute a callback on each item of the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {clear_list_item_callback} onItem - Callback to execute on each item.
     * 
     * @remarks Like the {destroyList()} function, this function free the mmeory ocuped 
     * by the list and by the pointer itself, and allow to execute first a clean up 
     * operation on each item, like in {clearListEx()} function.
     */    
    void destroyListEx(list_t* list, clear_list_item_callback onItem);

    /**
     * Creates a new item in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @returns {list_item_t*} - Returns the pointer to the new item in the list, or {NULL} 
     * if the list is full or if the list is {NULL}.
     * 
     * @remarks This function not allocated new memory for the item, only point to the 
     * next available position in the reserved memory.
     */
    list_item_t* createListItem(list_t* list);

    /**
     * Creates a new item in the list with condition callback.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {create_list_item_callback} onBeforeCreate - Function callback that 
     * define a condition to satisfy to create the item.
     * @param ... - Optional list of arguments to use as extra parameters in the 
     * callback.
     * 
     * @returns {list_item_t*} - Returns the pointer to the new item in the list, or {NULL} 
     * if {$onBeforeCreate} function callback returns {false}, if the list is full or 
     * if the list is {NULL}.
     * 
     * @remarks The {$onBeforeCreate} function must be return {true} to able create the 
     * new item. You can use this function to implement behaviours like a dictionary 
     * item key check or another required condition to satify before create the item.
     * 
     * Like the {createListItem()} function, this function not allocated new memory for 
     * the item, only point to the next available position in the reserved memory.
     */
    list_item_t* createListItemEx(list_t* list, create_list_item_callback onBeforeCreate, ...);
    
    /**
     * Gets the pointer to an item in the list.
     * 
     * @param {list_t*} list - Pointer to a list.
     * @param {int} index - Index of the item. Must be a number between 0 and below of 
     * list count.
     * 
     * @returns {list_item_t*} - Returns the pointer to the new item in the list, or {NULL} 
     * if the index is over the list count or capacity or below zero, or if the list 
     * is {NULL}.
     */
    byte* getListItem(const list_t* list, int index);

    /**
     * Loops the entire list and execute a callback in each item.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {foreach_list_item_callback} onItem - Callback to execute in each item.
     * @param ... - Optional list of arguments to use as extra parameters in the 
     * callback.
     * 
     * @remarks Use this function execute a callback on each item in the list 
     * sequentially.
     */
    void forEachList(list_t* list, foreach_list_item_callback onItem, ...);

    /**
     * Finds an item that match with the predicate.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {find_list_item_callback} predicate - Function callback to execute in 
     * each item. This functions define a predicate that an item must be match.
     * @param ... - Optional list of arguments to use as extra parameters in the 
     * callback.
     * 
     * @returns {list_item_t*} - Returns the pointer to the found item in the list, or 
     * {NULL} if {$predicate} function callback returns {false}, if the list is empty or 
     * if the list is {NULL}.
     * 
     * @remarks The {$predicate} function must be return {true} to tell the list what 
     * item match. You can use this function to implement behaviours like a dictionary 
     * item key check or another required condition to satify to find the desired item.
     */
    list_item_t* findListItem(list_t* list, find_list_item_callback predicate, ...);
#endif
