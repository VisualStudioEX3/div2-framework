/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_INPUTMAP_KEYCODES_H_
    #define __DIV_INPUTMAP_KEYCODES_H_

    #include "..\shared\_const.h"
    #include "..\shared\_string.h"
    #include "enums.h"

    typedef struct _keycode_t
    {
        int code;
        string name;
        bool* state; // Pointer to DIV keycode input state.
    } keycode_t;

    #define keyb(k)   (bool*)&key[k]
    #define shiftb(s) (bool*)(&shift_status && (SHIFT_KEY_NONE - s) == (SHIFT_KEY_NONE - s))

    const keycode_t KEYCODE_TABLE[] =
    {
        { INPUT_NONE,               STR_INPUT_NONE,             false                            },

        { KEY_ESC,                  STR_KEY_ESC,                keyb(KEY_ESC)                    },
        { KEY_F1,                   STR_KEY_F1,                 keyb(KEY_F1)                     },
        { KEY_F2,                   STR_KEY_F2,                 keyb(KEY_F2)                     },
        { KEY_F3,                   STR_KEY_F3,                 keyb(KEY_F3)                     },
        { KEY_F4,                   STR_KEY_F4,                 keyb(KEY_F4)                     },
        { KEY_F5,                   STR_KEY_F5,                 keyb(KEY_F5)                     },
        { KEY_F6,                   STR_KEY_F6,                 keyb(KEY_F6)                     },
        { KEY_F7,                   STR_KEY_F7,                 keyb(KEY_F7)                     },
        { KEY_F8,                   STR_KEY_F8,                 keyb(KEY_F8)                     },
        { KEY_F9,                   STR_KEY_F9,                 keyb(KEY_F9)                     },
        { KEY_F10,                  STR_KEY_F10,                keyb(KEY_F10)                    },
        { KEY_F11,                  STR_KEY_F11,                keyb(KEY_F11)                    },
        { KEY_F12,                  STR_KEY_F12,                keyb(KEY_F12)                    },
        { KEY_PRN_SCR,              STR_KEY_PRN_SCR,            keyb(KEY_PRN_SCR)                },
        { KEY_SCROLL_LOCK,          STR_KEY_SCROLL_LOCK,        keyb(KEY_SCROLL_LOCK)            },

        { KEY_WAVE,                 STR_KEY_WAVE,               keyb(KEY_WAVE)                   },
        { KEY_1,                    STR_KEY_1,                  keyb(KEY_1)                      },
        { KEY_2,                    STR_KEY_2,                  keyb(KEY_2)                      },
        { KEY_3,                    STR_KEY_3,                  keyb(KEY_3)                      },
        { KEY_4,                    STR_KEY_4,                  keyb(KEY_4)                      },
        { KEY_5,                    STR_KEY_5,                  keyb(KEY_5)                      },
        { KEY_6,                    STR_KEY_6,                  keyb(KEY_6)                      },
        { KEY_7,                    STR_KEY_7,                  keyb(KEY_7)                      },
        { KEY_8,                    STR_KEY_8,                  keyb(KEY_8)                      },
        { KEY_9,                    STR_KEY_9,                  keyb(KEY_9)                      },
        { KEY_0,                    STR_KEY_0,                  keyb(KEY_0)                      },
        { KEY_MINUS,                STR_KEY_MINUS,              keyb(KEY_MINUS)                  },
        { KEY_PLUS,                 STR_KEY_PLUS,               keyb(KEY_PLUS)                   },

        { KEY_BACKSPACE,            STR_KEY_BACKSPACE,          keyb(KEY_BACKSPACE)              },
        { KEY_TAB,                  STR_KEY_TAB,                keyb(KEY_TAB)                    },
        { KEY_Q,                    STR_KEY_Q,                  keyb(KEY_Q)                      },
        { KEY_W,                    STR_KEY_W,                  keyb(KEY_W)                      },
        { KEY_E,                    STR_KEY_E,                  keyb(KEY_E)                      },
        { KEY_R,                    STR_KEY_R,                  keyb(KEY_R)                      },
        { KEY_T,                    STR_KEY_T,                  keyb(KEY_T)                      },
        { KEY_Y,                    STR_KEY_Y,                  keyb(KEY_Y)                      },
        { KEY_U,                    STR_KEY_U,                  keyb(KEY_U)                      },
        { KEY_I,                    STR_KEY_I,                  keyb(KEY_I)                      },
        { KEY_O,                    STR_KEY_O,                  keyb(KEY_O)                      },
        { KEY_P,                    STR_KEY_P,                  keyb(KEY_P)                      },
        { KEY_L_BRACHET,            STR_KEY_L_BRACHET,          keyb(KEY_L_BRACHET)              },
        { KEY_R_BRACHET,            STR_KEY_R_BRACHET,          keyb(KEY_R_BRACHET)              },
        { KEY_ENTER,                STR_KEY_ENTER,              keyb(KEY_ENTER)                  },

        { KEY_CAPS_LOCK,            STR_KEY_CAPS_LOCK,          keyb(KEY_CAPS_LOCK)              },
        { KEY_A,                    STR_KEY_A,                  keyb(KEY_A)                      },
        { KEY_S,                    STR_KEY_S,                  keyb(KEY_S)                      },
        { KEY_D,                    STR_KEY_D,                  keyb(KEY_D)                      },
        { KEY_F,                    STR_KEY_F,                  keyb(KEY_F)                      },
        { KEY_G,                    STR_KEY_G,                  keyb(KEY_G)                      },
        { KEY_H,                    STR_KEY_H,                  keyb(KEY_H)                      },
        { KEY_J,                    STR_KEY_J,                  keyb(KEY_J)                      },
        { KEY_K,                    STR_KEY_K,                  keyb(KEY_K)                      },
        { KEY_L,                    STR_KEY_L,                  keyb(KEY_L)                      },
        { KEY_SEMICOLON,            STR_KEY_SEMICOLON,          keyb(KEY_SEMICOLON)              },
        { KEY_APOSTROPHE,           STR_KEY_APOSTROPHE,         keyb(KEY_APOSTROPHE)             },
        { KEY_BACKSLASH,            STR_KEY_BACKSLASH,          keyb(KEY_BACKSLASH)              },

        { KEY_L_SHIFT,              STR_KEY_L_SHIFT,            keyb(KEY_L_SHIFT)                },
        { KEY_Z,                    STR_KEY_Z,                  keyb(KEY_Z)                      },
        { KEY_X,                    STR_KEY_X,                  keyb(KEY_X)                      },
        { KEY_C,                    STR_KEY_C,                  keyb(KEY_C)                      },
        { KEY_V,                    STR_KEY_V,                  keyb(KEY_V)                      },
        { KEY_B,                    STR_KEY_B,                  keyb(KEY_B)                      },
        { KEY_N,                    STR_KEY_N,                  keyb(KEY_N)                      },
        { KEY_M,                    STR_KEY_M,                  keyb(KEY_M)                      },
        { KEY_COMMA,                STR_KEY_COMMA,              keyb(KEY_COMMA)                  },
        { KEY_POINT,                STR_KEY_POINT,              keyb(KEY_POINT)                  },
        { KEY_SLASH,                STR_KEY_SLASH,              keyb(KEY_SLASH)                  },
        { KEY_R_SHIFT,              STR_KEY_R_SHIFT,            keyb(KEY_R_SHIFT)                },

        { KEY_CONTROL,              STR_KEY_CONTROL,            keyb(KEY_CONTROL)                },
        { KEY_ALT,                  STR_KEY_ALT,                keyb(KEY_ALT)                    },
        { KEY_SPACE,                STR_KEY_SPACE,              keyb(KEY_SPACE)                  },

        { KEY_INS,                  STR_KEY_INS,                keyb(KEY_INS)                    },
        { KEY_HOME,                 STR_KEY_HOME,               keyb(KEY_HOME)                   },
        { KEY_PGUP,                 STR_KEY_PGUP,               keyb(KEY_PGUP)                   },
        { KEY_DEL,                  STR_KEY_DEL,                keyb(KEY_DEL)                    },
        { KEY_END,                  STR_KEY_END,                keyb(KEY_END)                    },
        { KEY_PGDN,                 STR_KEY_PGDN,               keyb(KEY_PGDN)                   },

        { KEY_UP,                   STR_KEY_UP,                 keyb(KEY_UP)                     },
        { KEY_DOWN,                 STR_KEY_DOWN,               keyb(KEY_DOWN)                   },
        { KEY_LEFT,                 STR_KEY_LEFT,               keyb(KEY_LEFT)                   },
        { KEY_RIGHT,                STR_KEY_RIGHT,              keyb(KEY_RIGHT)                  },

        { KEY_NUM_LOCK,             STR_KEY_NUM_LOCK,           keyb(KEY_NUM_LOCK)               },
        { KEY_C_BACKSLASH,          STR_KEY_C_BACKSLASH,        keyb(KEY_C_BACKSLASH)            },
        { KEY_C_ASTERISK,           STR_KEY_C_ASTERISK,         keyb(KEY_C_ASTERISK)             },
        { KEY_C_MINUS,              STR_KEY_C_MINUS,            keyb(KEY_C_MINUS)                },
        { KEY_C_HOME,               STR_KEY_C_HOME,             keyb(KEY_C_HOME)                 },
        { KEY_C_UP,                 STR_KEY_C_UP,               keyb(KEY_C_UP)                   },
        { KEY_C_PGUP,               STR_KEY_C_PGUP,             keyb(KEY_C_PGUP)                 },
        { KEY_C_LEFT,               STR_KEY_C_LEFT,             keyb(KEY_C_LEFT)                 },
        { KEY_C_CENTER,             STR_KEY_C_CENTER,           keyb(KEY_C_CENTER)               },
        { KEY_C_RIGHT,              STR_KEY_C_RIGHT,            keyb(KEY_C_RIGHT)                },
        { KEY_C_END,                STR_KEY_C_END,              keyb(KEY_C_END)                  },
        { KEY_C_DOWN,               STR_KEY_C_DOWN,             keyb(KEY_C_DOWN)                 },
        { KEY_C_PGDN,               STR_KEY_C_PGDN,             keyb(KEY_C_PGDN)                 },
        { KEY_C_INS,                STR_KEY_C_INS,              keyb(KEY_C_INS)                  },
        { KEY_C_DEL,                STR_KEY_C_DEL,              keyb(KEY_C_DEL)                  },
        { KEY_C_PLUS,               STR_KEY_C_PLUS,             keyb(KEY_C_PLUS)                 },
        { KEY_C_ENTER,              STR_KEY_C_ENTER,            keyb(KEY_C_ENTER)                },

        { MOUSE_LEFT,               STR_MOUSE_LEFT,             &MOUSE->left                     },
        { MOUSE_RIGHT,              STR_MOUSE_RIGHT,            &MOUSE->right                    },
        { MOUSE_MIDDLE,             STR_MOUSE_MIDDLE,           &MOUSE->middle                   },

        { JOY_LEFT,                 STR_JOY_LEFT,               &JOY->left                       },
        { JOY_UP,                   STR_JOY_UP,                 &JOY->up                         },
        { JOY_RIGHT,                STR_JOY_RIGHT,              &JOY->right                      },
        { JOY_DOWN,                 STR_JOY_DOWN,               &JOY->down                       },

        { JOY_BUTTON1,              STR_JOY_BUTTON1,            &JOY->button1                    },
        { JOY_BUTTON2,              STR_JOY_BUTTON2,            &JOY->button2                    },
        { JOY_BUTTON3,              STR_JOY_BUTTON3,            &JOY->button3                    },
        { JOY_BUTTON4,              STR_JOY_BUTTON4,            &JOY->button4                    },

        { SHIFT_KEY_NONE,           STR_SHIFT_KEY_NONE,         (bool*)true                      },
        { SHIFT_KEY_RIGHT_SHIFT,    STR_SHIFT_KEY_RIGHT_SHIFT,  shiftb(SHIFT_KEY_RIGHT_SHIFT)    },
        { SHIFT_KEY_LEFT_SHIFT,     STR_SHIFT_KEY_LEFT_SHIFT,   shiftb(SHIFT_KEY_LEFT_SHIFT)     },
        { SHIFT_KEY_CONTROL,        STR_SHIFT_KEY_CONTROL,      shiftb(SHIFT_KEY_CONTROL)        },
        { SHIFT_KEY_ALT,            STR_SHIFT_KEY_ALT,          shiftb(SHIFT_KEY_ALT)            },
    };

    const keycode_t* getKeycode(int code);
    const keycode_t* getKeycodeByName(const string name);
    bool parseKeycode(string dest, int code);
    int keycodeToName(const string name);
#endif
