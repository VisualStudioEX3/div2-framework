/* ----------------------------------------------------------------------------
 * DIV Games Studio 2 library and helper functions.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "_div2lib.h"

void* div_realloc(void* ptr, size_t size)
{
    void* newPtr = div_malloc(size);
	
    memcpy(newPtr, ptr, size);
    div_free(ptr);
    
    return newPtr;
}

void* div_calloc(size_t nitems, size_t size)
{
    size_t memSize = nitems * size;
    void* ptr = div_malloc(memSize);
    
    memset(ptr, 0, memSize);
    
    return ptr;
}
