/* ----------------------------------------------------------------------------
 * DIV Games Studio 2 library and helper functions.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV2LIB_H_
    #define __DIV2LIB_H_

    #include <stdio.h>
    #include <string.h>

    #define GLOBALS // Required by DIV.H (before incluide it).

    #include "..\div.h" // DIV Games Studio 2 API header.

    typedef unsigned char byte;     // BYTE type in DIV Games Studio 2.
    typedef unsigned short word;    // WORD type in DIV Games Studio 2.
    typedef char* string;           // STRING type in DIV Games Studio 2.

    /**
     * Macro to gets the size of an array.
     * 
     * @param {void} a - Array to calculate the size.
     * 
     * @return {int} - Returns the number of elements in the array.
     * 
     * @remarks - Use this macro only with a array values. A pointer reference could be return wrong values.
     */
    #define arrayLen(a) sizeof(a) / sizeof(a[0])

    /**
     * Macro to gets a string parameter from DIV Games Studio 2 stack.
     * 
     * @return {char*} - Returns a char pointer to the DIV Games Studio 2 string value.
     */
    #define getStringParm() (char*)&mem[text_offset + getparm()]

    /**
     * Macro to gets a struct parameter from DIV Games Studio 2 stack.
     * 
     * @return {void*} - Returns a pointer to the DIV Games Studio 2 struct value.
     */
    #define getStructParm() &mem[getparm()]

    /**
     * Macro to gets a DIV Games Studio 2 built-in struct data.
     * 
     * @param {int} offset - The struct offset in DIV Games Studio 2 memory.
     * 
     * @return {void*} - Returns a pointer to the DIV Games Studio 2 built-in struct value.
     * 
     * @remarks - See div.h to know the offset of DIV Games Studio 2 built-in structs.
     */
    #define getDivStruct(offset) &mem[offset]

    /**
     * Custom implementation of standard C {realloc()} function to works with DIV Games Studio 2 memory.
     * 
     * @param {void*} ptr - Pointer to memory section to resize.
     * @param {size_t} size - The new size of this memory section.
     * 
     * @return {void*} - Returns the pointer to the memory section resized.
     * 
     * @remarks - This function works as same as standard C {realloc()} function, preserving the current memory values.
     */
    void* div_realloc(void *ptr, size_t size);

    /**
     * Custom implementation of standard C {calloc()} function to works with DIV Games Studio 2 memory.
     * 
     * @param {size_t} nitems - Number of elements.
     * @param {size_t} size - Size, in bytes, of the data value used in this memory section.
     * 
     * @return {void*} - Returns the pointer to the new memory allocation with all bytes set to zero.
     * 
     * @remarks - This function works as same as standard C {calloc()} function, initializing a memory section with all bytes set to zero.
     */
    void* div_calloc(size_t nitems, size_t size);
#endif
