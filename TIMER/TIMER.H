/* ----------------------------------------------------------------------------
 * TIMER.DLL - Advanced timers for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_TIMER_H_
    #define __DIV_TIMER_H_

    #include <time.h>

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "tmrcore.h"
    
    /** 
     * Creates and initializes timers.
     *
     * @param {int} capacity - Number of timers to create.
     * 
     * @return {bool} - Returns {true} if the timers are initialized, {false} otherwise.
     */
    void div_initialize();
    #define DIV_INITIALIZE_NAME         "initialize_timers"
    #define DIV_INITIALIZE_PARAMS       1

    /** 
     * Destroys all timers.
     *
     * @return {int} - Always returns {RESULT_OK}.
     */
    void div_terminate();
    #define DIV_TERMINATE_NAME          "destroy_timers"
    #define DIV_TERMINATE_PARAMS        0

    /** 
     * Gets number of available timers.
     *
     * @return {int} - Returns the number of available timers.
     */
    void div_getCapacity();
    #define DIV_GET_CAPACITY_NAME       "get_timers_count"
    #define DIV_GET_CAPACITY_PARAMS     0

    /** 
     * Gets current timer value.
     *
     * @param {int} index - The index of timer to query.
     *
     * @return {int} - Returns the time count on selected timer.
     */
    void div_getTime();
    #define DIV_GET_TIME_NAME           "get_timer_value"
    #define DIV_GET_TIME_PARAMS         1

    /** 
     * Pauses timer.
     *
     * @param {int} index - The index of timer to pause.
     *
     * @return {bool} - Returns {true} if the timer is paused, {false} otherwise.
     */
    void div_pause();
    #define DIV_PAUSE_NAME              "pause_timer"
    #define DIV_PAUSE_PARAMS            1

    /** 
     * Resumes timer.
     *
     * @param {int} index - The index of timer to resume.
     *
     * @return {bool} - Returns {true} if the timer is resumed, {false} otherwise.
     */
    void div_resume();
    #define DIV_RESUME_NAME             "resume_timer"
    #define DIV_RESUME_PARAMS           1

    /** 
     * Is timer paused?
     *
     * @param {int} index - The index of timer to query.
     *
     * @return {bool} - Returns {true} if the timer is paused, {false} otherwise.
     */
    void div_isPaused();
    #define DIV_IS_PAUSED_NAME          "is_timer_paused"
    #define DIV_IS_PAUSED_PARAMS        1

    /** 
     * Resets timer.
     *
     * @param {int} index - The index of timer to reset.
     *
     * @return {bool} - Returns {true} if the timer is reset, {false} otherwise.
     */
    void div_reset();
    #define DIV_RESET_NAME              "reset_timer"
    #define DIV_RESET_PARAMS            1

    /** 
     * Resets all timers.
     *
     * @return {int} - Always returns {RESULT_OK}.
     */
    void div_resetAll();
    #define DIV_RESET_ALL_NAME          "reset_all_timers"
    #define DIV_RESET_ALL_PARAMS        0

    /**
     * Updates all timers.
     * 
     * @return {int} - Always returns {RESULT_OK}.
     * 
     * @remarks Call this function one time per game frame.
     */
    void div_frame();
    #define DIV_FRAME_NAME              "frame_timers"
    #define DIV_FRAME_PARAMS            0
#endif
