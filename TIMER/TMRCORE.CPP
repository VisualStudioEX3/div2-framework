/* ----------------------------------------------------------------------------
 * TIMER.DLL - Advanced timers for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include "..\shared\_div2lib.h"
#include "..\shared\_list.h"
#include "tmrcore.h"

list_t* timers;
int cachedCurrentTime = 0;

//#define USE_DIV_TIMERS

#ifdef USE_DIV_TIMERS
    // Use first built-in DIV Games Studio timer:
    #define getCurrentTime()    timer(0)
#else
    #include <time.h>
    #define getCurrentTime()    clock()
#endif

#define isPaused(t)     ((timer_t*)t)->pauseDelta > 0

static void updateCachedCurrentTime()
{
    cachedCurrentTime = getCurrentTime();
}

static void resetTimerCallback(int i, list_item_t* t, va_list args)
{
    resetTimer((timer_t*)t);
}

static void updateTimerCallback(int i, list_item_t* t, va_list args)
{
    updateTimer((timer_t*)t);
}

bool initialize(int capacity)
{
    bool ret = false;

    if (!timers && capacity > 0)
    {
        timers = createList(capacity, TIMER_T_SIZE);
        timers->count = timers->capacity;
        updateCachedCurrentTime();
        resetAllTimers();
        ret = true;
    }

    return ret;
}

void terminate()
{
    destroyList(timers);
}

int getTimersCapacity()
{
    return getListCapacity(timers);
}

timer_t* getTimer(int index)
{
    return (timer_t*)getListItem(timers, index);
}

int getTimeCount(timer_t* t)
{
    return t ? t->time : RESULT_ERROR;
}

void pauseTimer(timer_t* t)
{
    if (t && !isPaused(t))
        t->pauseDelta = cachedCurrentTime;
}

void resumeTimer(timer_t* t)
{
    if (t && isPaused(t))
    {
        t->startTime += cachedCurrentTime - t->pauseDelta;
        t->pauseDelta = 0;
    }
}

bool isTimerPaused(timer_t* t)
{
    return t && isPaused(t);
}

void resetTimer(timer_t* t)
{
    if (t)
    {
        t->startTime = cachedCurrentTime;
        t->pauseDelta = 0;
        t->time = 0;
    }
}

void resetAllTimers()
{
    forEachList(timers, resetTimerCallback);
}

void updateTimer(timer_t* t)
{
    if (t)
        t->time = (isPaused(t) ? t->pauseDelta : cachedCurrentTime) - t->startTime;
}

void updateAllTimers()
{
    updateCachedCurrentTime();
    forEachList(timers, updateTimerCallback);
}
