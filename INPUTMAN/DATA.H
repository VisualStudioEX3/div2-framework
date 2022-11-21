/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_INPUTMAP_DATA_H_
    #define __DIV_INPUTMAP_DATA_H_

    #include "..\shared\_const.h"
    #include "..\shared\_div2lib.h"
    #include "..\shared\_string.h"
    #include "..\shared\_list.h"
    #include "map.h"

    void initialize(int capacity);
    void terminate();
    int getInputMapsCapacity();
    int getInputMapsCount();
    input_map_t* addInputMap(const string name, int capacity);
    void clearInputMap(input_map_t* map);
    void clearAllInputMaps();
    input_map_t* getInputMap(const string name);
#endif
