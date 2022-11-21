/* ----------------------------------------------------------------------------
 * PROCESS.DLL - Functions to operate with processes in DIV Games Studio 2.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "process.h"

static DIV_Process* findProcess(const int id)
{
    if (isClamped(id, id_init_offset, id_end_offset))
        for (int offset = id_init_offset; offset <= id_end_offset; offset += process_size)
        {
            DIV_Process* proc = (DIV_Process*)getDivStruct(offset);
			
            if (proc->reserved.id == id)
                return proc;
        }
	
    return NULL;
}

static int getStatus(const int id)
{   
	DIV_Process* proc = findProcess(id);
    int ret = proc ? proc->reserved.status : RESULT_ERROR;
	
	return ret;
}

void div_typeOf()
{
	int id = getparm();
	DIV_Process* proc = findProcess(id);
    int ret = proc ? proc->reserved.block : RESULT_ERROR;
	
	retval(ret);
}

void div_getStatus()
{
	int id = getparm();
    bool ret = getStatus(id);
	
    retval(ret);
}

void div_exists()
{
    int id = getparm();
    bool ret = getStatus(id) != PROCESS_STATUS_NOT_EXISTS;
	
    retval(ret);
}

void div_isAlive()
{
    int id = getparm();
    bool ret = getStatus(id) == PROCESS_STATUS_ALIVE;
	
    retval(ret);
}

void div_isAsleep()
{
    int id = getparm();
    bool ret = getStatus(id) == PROCESS_STATUS_ASLEEP;
	
    retval(ret);
}

void div_isFrozen()
{
    int id = getparm();
    bool ret = getStatus(id) == PROCESS_STATUS_FROZEN;
	
    retval(ret);
}

void div_getProcBoundsRect()
{	
	rect_t* bounds = getRectParm();
	int id = getparm();
	DIV_Process* proc = findProcess(id);
	bool ok = proc && bounds;
	
	if (ok)
	{
		_reserved resrvd = proc->reserved;
		
		bounds->x0 = resrvd.x0;
		bounds->y0 = resrvd.y0;
		bounds->x1 = resrvd.x1;
		bounds->y1 = resrvd.y1;
	}
	
	retval(ok);
}

void __export divlibrary(LIBRARY_PARAMS)
{    
    COM_export(DIV_TYPE_OF_NAME,    div_typeOf,     	    DIV_TYPE_OF_PARAMS);
    COM_export(DIV_GET_STATUS_NAME, div_getStatus,  		DIV_GET_STATUS_PARAMS);
    COM_export(DIV_EXISTS_NAME,     div_exists,     		DIV_EXISTS_PARAMS);
    COM_export(DIV_IS_ALIVE_NAME,   div_isAlive,    		DIV_IS_ALIVE_PARAMS);
    COM_export(DIV_IS_ASLEEP_NAME,  div_isAsleep,   		DIV_IS_ASLEEP_PARAMS);
    COM_export(DIV_IS_FROZEN_NAME,  div_isFrozen,   		DIV_IS_FROZEN_PARAMS);
	COM_export(DIV_GET_BOUNDS_NAME,	div_getProcBoundsRect,  DIV_GET_BOUNDS_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
	GLOBAL_IMPORT();
}
