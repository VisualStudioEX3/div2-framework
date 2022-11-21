/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#include <stdarg.h>
#include "keycodes.h"

typedef bool (*compare_callback)(const keycode_t*, void*);

static const keycode_t* getKeycodeInternal(compare_callback compareFunction, void* compareKey)
{
    const keycode_t* keycode;

    for (int i = 0; i < arrayLen(KEYCODE_TABLE); i++)
    {
        keycode = &KEYCODE_TABLE[i];

        if (compareFunction(keycode, compareKey))
            return keycode;
    }

    return NULL;
}

static bool compareByCodeCallback(const keycode_t* keycode, void* compareKey)
{
    return keycode->code == *((int*)compareKey);
}

static bool compareByNameCallback(const keycode_t* keycode, void* compareKey)
{
    return strequal(keycode->name, (string)compareKey);
}

const keycode_t* getKeycode(int code)
{
    return getKeycodeInternal(compareByCodeCallback, &code);
}

const keycode_t* getKeycodeByName(const string name)
{
    return getKeycodeInternal(compareByNameCallback, name);
}

bool parseKeycode(string dest, int code)
{
    const keycode_t* keycode = getKeycode(code);

    if (keycode && dest)
        strcpy(dest, keycode->name);

    return keycode && dest;
}

int keycodeToName(const string name)
{
    const keycode_t* keycode = getKeycodeByName(name);

    return keycode ? keycode->code : RESULT_ERROR;
}
