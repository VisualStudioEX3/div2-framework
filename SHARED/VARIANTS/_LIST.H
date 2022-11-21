/* ----------------------------------------------------------------------------
 * Linked list for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "_const.h"

#ifndef __LIST_H_
    #define __LIST_H_

    /**
     * A linked list item.
     */
    typedef struct _list_item_t
    {
        /**
         * Pointer to the value stored in the list item.
         * 
         * @remarks - Don't access directly to this field, use {getListItem()}, {getFirstListItem()} and {getNextListItem()} functions instead.
         */
        void* value;
        /**
         * Pointer to the next item in the list, or {NULL} if this is the last.
         * 
         * @remarks - Don't access directly to this field, use {getNextListItem()} function instead.
         */
        _list_item_t* next;
    } list_item_t;

    /**
     * A linked list object.
     */
    typedef struct _list_t
    {
        /**
         * The items count.
         * 
         * @remarks - Don't access directly to this field, use {getListCount()} function instead.
         */
        int count;
        /**
         * Pointer to the first item in the list.
         * 
         * @remarks - Don't access directly to this field, use {getFirstListItem()} function instead.
         */
        list_item_t* first;
        /**
         * Pointer to the last item in the list.
         * 
         * @remarks - Don't access directly to this field.
         */
        list_item_t* last;
        /**
         * The list iterator pointer.
         * 
         * @remarks - Don't access directly to this field, use {getFirstListItem()} with {getNextListItem()} functions instead.
         */
        list_item_t* iterator;
    } list_t;

    #define LIST_SIZE           sizeof(list_t)
    #define LIST_ITEM_SIZE      sizeof(list_item_t)

    /**
     * Creates a new list.
     * 
     * @return {list_t*} - Returns the pointer to the new list, {NULL} otherwise.
     */
    list_t* createList();

    /**
     * Destroys an existing list.
     * 
     * @param {list_t*} list - Pointer of the list to destroy.
     * 
     * @return {bool} - Returns {true} if the list has succesfully destroyed, {false} otherwise.
     */
    bool destroyList(list_t* list);

    /**
     * Gets the number of elements in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {int} - Returns the number of elements in the list or {RESULT_ERROR} if the pointer is {NULL} or invalid list.
     */
    int getListCount(const list_t* list);

    /**
     * Checks if the list is empty.
     * 
     * @param {list_t*} - Pointer to the list.
     * 
     * @return {bool} - Returns {true} if the list is empty, {false} otherwise.
     */
    bool isListEmpty(const list_t* list);

    /**
     * Adds a value to the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {void*} value - Pointer the value to add.
     * 
     * @return {int} - Returns the index of the new item added.
     */
    int addListItem(list_t* list, void* value);

    /**
     * Inserts a value to the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {void*} value - Pointer the value to add.
     * @param {int} index - Index where insert the new item.
     * 
     * @return {bool} - Returns {true} if the item was successfully inserted in the list, {false} otherwise.
     */ 
    bool insertListItemAt(list_t* list, void* value, int index);

    /**
     * Finds an item position in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {void*} value - Pointer the value to find.
     * 
     * @returns {int} - Returns the item index in the list, or {RESULT_ERROR} otherwise.
     * 
     * @remarks - This function searchs an item that matchs the address of the input item value.
     */
    int findListItem(list_t* list, const void* item);

    /**
     * Gets a value from a list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {int} index - The item index to get.
     * 
     * @return {void*} - Returns the pointer to the item, {NULL} otherwise.
     */
    void* getListItem(const list_t* list, int index);

    /**
     * Intializes the list iterator and gets the first item in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {void*} - Returns the pointer to the item, {NULL} otherwise.
     * 
     * @remarks - Use this function, with {getNextListItem()} function, to iterate each item in the list.
     */
    void* getFirstListItem(list_t* list);

    /**
     * Iterates to the next item in the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @return {void*} - Returns the pointer to the item, {NULL} otherwise.
     * 
     * @remarks - To use this function, you need to call first {getFirstListItem()} function to initializes the list iterator.
     */
    void* getNextListItem(list_t* list);

    /**
     * Removes an item from the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {void*} value - Pointer the value to remove.
     * 
     * @return {bool} - Returns {true} if the item was successfully removed from the list, {false} otherwise.
     * 
     * @remarks - This function only removes the item in the list, no free the memory of the source value.
     */
    bool removeListItem(list_t* list, void* value);

    /**
     * Removes an item from the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * @param {int} index - The item index to remove.
     * 
     * @return {bool} - Returns {true} if the item was successfully removed from the list, {false} otherwise.
     * 
     * @remarks - This function only removes the item in the list, no free the memory of the source value.
     */
    bool removeListItemAt(list_t* list, int index);

    /**
     * Removes all items from the list.
     * 
     * @param {list_t*} list - Pointer to the list.
     * 
     * @remarks - This function only removes the items in the list, no free the memory each source values.
     */
    bool clearList(list_t* list);
#endif
