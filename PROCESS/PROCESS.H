/* ----------------------------------------------------------------------------
 * PROCESS.DLL - Functions to operate with processes in DIV Games Studio 2.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_PROCESS_H_
    #define __DIV_PROCESS_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_math.h"
    #include "..\shared\_rect.h"

    #define PROCESS_STATUS_NOT_EXISTS 	0
    #define PROCESS_STATUS_ALIVE		2
    #define PROCESS_STATUS_ASLEEP 		3
    #define PROCESS_STATUS_FROZEN 		4

    #define DIV_Process                 process

    static DIV_Process* findProcess(const int id);
    static int getStatus(const int id);

    /** 
     * Get the type of the process.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {int} - Returns the process type or 0 if process id is invalid or process doesn't exists.
     */
    void div_typeof();
    #define DIV_TYPE_OF_NAME        "typeof"
    #define DIV_TYPE_OF_PARAMS      1

    /** 
     * Get process status.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {int} - Returns the process status: 
     *                 0 - Inexistent.
     *                 1 - Received s_kill signal.
     *                 2 - Is alive or awake (s_wakeup)
     *                 3 - Is asleep (s_sleep)
     *                 4 - Is frozen (s_freeze)
     */
    void div_getStatus();
    #define DIV_GET_STATUS_NAME     "get_status"
    #define DIV_GET_STATUS_PARAMS   1

    /** 
     * Is the process exists?.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {bool} - Returns {true} if the process exists, {false} otherwise.
     */
    void div_exists();
    #define DIV_EXISTS_NAME         "exists"
    #define DIV_EXISTS_PARAMS       1

    /** 
     * Is the process alive?.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {bool} - Returns {true} if the process exists, {false} otherwise.
     */
    void div_isAlive();
    #define DIV_IS_ALIVE_NAME       "is_alive"
    #define DIV_IS_ALIVE_PARAMS     1

    /** 
     * Is the process asleep?.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {bool} - Returns {true} if the process exists, {false} otherwise.
     */
    void div_isAsleep();
    #define DIV_IS_ASLEEP_NAME      "is_asleep"
    #define DIV_IS_ASLEEP_PARAMS    1

    /** 
     * Is the process fronzen?.
     *
     * @param {int} processId - Process identifier.
     *
     * @return {bool} - Returns {true} if the process exists, {false} otherwise.
     */
    void div_isFrozen();
    #define DIV_IS_FROZEN_NAME      "is_frozen"
    #define DIV_IS_FROZEN_PARAMS    1

    /** 
     * Gets the process bounds rect.
     *
     * @param {int} processId - Process identifier.
     * @param {rect_t*} rect - Pointer to a rectangle struct.
     *
     * @return {bool} - Returns {true} if the process exists, {false} otherwise.
     */
    void div_getBounds();
    #define DIV_GET_BOUNDS_NAME     "get_process_bounds"
    #define DIV_GET_BOUNDS_PARAMS   2
#endif
