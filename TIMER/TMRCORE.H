/* ----------------------------------------------------------------------------
 * TIMER.DLL - Advanced timers for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_TIMER_CORE_H_
    #define __DIV_TIMER_CORE_H_

    #include "..\shared\_const.h"

    typedef struct _timer_t
    {
        int startTime;
        int pauseDelta;
        int time;
    } timer_t;

    #define TIMER_T_SIZE    sizeof(timer_t)

    bool initialize(int capacity);
    void terminate();
    int getTimersCapacity();
    timer_t* getTimer(int index);
    int getTimeCount(timer_t* t);
    void pauseTimer(timer_t* t);
    void resumeTimer(timer_t* t);
    bool isTimerPaused(timer_t* t);
    void resetTimer(timer_t* t);
    void resetAllTimers();
    void updateTimer(timer_t* t);
    void updateAllTimers();
#endif
