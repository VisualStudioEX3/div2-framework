/* ----------------------------------------------------------------------------
 * Text circular buffer for DEBUG.DLL for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __TEXT_BUFFER_H_
    #define __TEXT_BUFFER_H_

    typedef struct _string_node_t
    {
        string value;
        _string_node_t* next;
    } string_node_t;

    #define STRING_NODE_SIZE    sizeof(string_node_t)

    typedef struct _string_list_t
    {
        int capacity;
        int count;
        string_node_t* first;
        string_node_t* last;
    } string_list_t;

    #define STRING_LIST_SIZE    sizeof(string_list_t)

    typedef void (*print_node_callback)(const string, int, int);

    string_list_t* createBuffer(const int capacity);
    void destroyBuffer(string_list_t* list);
    void addText(string_list_t* list, const string value);
    void clearBuffer(string_list_t* list);
    void printBuffer(const string_list_t* list, print_node_callback printTextFunc);
    void copyTo(string_list_t* dst, const string_list_t* src);
#endif
