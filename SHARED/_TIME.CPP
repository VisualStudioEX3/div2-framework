/* ----------------------------------------------------------------------------
 * Time functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#include "_time.h"
 
struct tm* getDateTime()
{
    tm* dateTime;
    time_t now;
	
    time(&now);
	
    dateTime = localtime(&now);
    dateTime->tm_year += 1900; // Fix year value.
    dateTime->tm_mon++; // Fix month value.

    return dateTime;
}
