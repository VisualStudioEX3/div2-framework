/* ----------------------------------------------------------------------------
 * TIMER.DLL - Advanced timers for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "timer.h"

void div_initialize()
{
    int capacity = getparm();
    bool ret = initialize(capacity);

    retval(ret);
}

void div_terminate()
{
    terminate();

    retval(RESULT_OK);
}

void div_getCapacity()
{
    int ret = getTimersCapacity();

    retval(ret);
}

void div_getTime()
{
    int ret = RESULT_ERROR;
    int index = getparm();    
    timer_t* timer = getTimer(index);

    ret = getTimeCount(timer);
    
    retval(ret);
}

void div_pause()
{
    int index = getparm();
    timer_t* timer = getTimer(index);
    bool ret = timer != NULL;

    pauseTimer(timer);
    
    retval(ret);
}

void div_resume()
{
    int index = getparm();
    timer_t* timer = getTimer(index);
    bool ret = timer != NULL;

    resumeTimer(timer);
    
    retval(ret);
}

void div_isPaused()
{
    int index = getparm();
    timer_t* timer = getTimer(index);    
    bool ret = isTimerPaused(timer);
    
    retval(ret);
}

void div_reset()
{
    int index = getparm();
    timer_t* timer = getTimer(index);
    bool ret = timer != NULL;

    resetTimer(timer);
    
    retval(ret);
}

void div_resetAll()
{
    resetAllTimers();

    retval(RESULT_OK);
}

void div_frame()
{
    updateAllTimers();

    retval(RESULT_OK);
}

void __export divlibrary(LIBRARY_PARAMS)
{
    COM_export(DIV_INITIALIZE_NAME,     div_initialize,     DIV_INITIALIZE_PARAMS);
    COM_export(DIV_TERMINATE_NAME,      div_terminate,      DIV_TERMINATE_PARAMS);
    COM_export(DIV_GET_CAPACITY_NAME,   div_getCapacity,    DIV_GET_CAPACITY_PARAMS);
    COM_export(DIV_GET_TIME_NAME,       div_getTime,        DIV_GET_TIME_PARAMS);
    COM_export(DIV_PAUSE_NAME,          div_pause,          DIV_PAUSE_PARAMS);
    COM_export(DIV_RESUME_NAME,         div_resume,         DIV_RESUME_PARAMS);
    COM_export(DIV_IS_PAUSED_NAME,      div_isPaused,       DIV_IS_PAUSED_PARAMS);
    COM_export(DIV_RESET_NAME,          div_reset,          DIV_RESET_PARAMS);
    COM_export(DIV_RESET_ALL_NAME,      div_resetAll,       DIV_RESET_ALL_PARAMS);
    COM_export(DIV_FRAME_NAME,          div_frame,          DIV_FRAME_PARAMS);
}

void __export divmain(COMMON_PARAMS)
{
    GLOBAL_IMPORT();
}

void __export divend(COMMON_PARAMS)
{
    terminate();
}
