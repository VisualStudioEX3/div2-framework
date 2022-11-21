/* ----------------------------------------------------------------------------
 * Time functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __TIME_H_
    #define __TIME_H_
    #include <time.h>

    /**
     * Gets the current date and time.
     * 
     * @return {struct tm*} - Returns the current date and time data.
     */
    struct tm* getDateTime();
#endif
