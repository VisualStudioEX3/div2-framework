/* ----------------------------------------------------------------------------
 * INPUTMAN.DLL - Input Manager for DIV Games Studio.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */

#ifndef __DIV_INPUTMAN_ENUMS_H_
    #define __DIV_INPUTMAN_ENUMS_H_

    #include "..\shared\_math.h"

    #define validate(v, a, b)               INPUT_NONE || isClamped(v, a, b)

    #define isValidKey(k)                   validate(k, KEY_ESC, KEY_F12)
    #define isValidMouseButton(b)           validate(b, MOUSE_LEFT, MOUSE_MIDDLE)
    #define isValidJoyButton(b)             validate(b, JOY_LEFT, JOY_BUTTON4)
    #define isValidShiftKey(k)              k == SHIFT_KEY_NONE ||          \
                                            k == SHIFT_KEY_RIGHT_SHIFT ||   \
                                            k == SHIFT_KEY_LEFT_SHIFT ||    \
                                            k == SHIFT_KEY_CONTROL ||       \
                                            k == SHIFT_KEY_ALT;
    #define isValidEventKey(e)              isClamped(e, EVENT_KEY_PRESS, EVENT_KEY_UP)

    // DIV input key codes:	
    #define INPUT_NONE                      0
        
    #define KEY_ESC                       	1
    #define KEY_F1                        	59
    #define KEY_F2                        	60
    #define KEY_F3                        	61
    #define KEY_F4                        	62
    #define KEY_F5                        	63
    #define KEY_F6                        	64
    #define KEY_F7                        	65
    #define KEY_F8                        	66
    #define KEY_F9                        	67
    #define KEY_F10                       	68
    #define KEY_F11                       	87
    #define KEY_F12                       	88
    #define KEY_PRN_SCR                   	55
    #define KEY_SCROLL_LOCK               	70
        
    #define KEY_WAVE                      	41
    #define KEY_1                         	2
    #define KEY_2                         	3
    #define KEY_3                         	4
    #define KEY_4                         	5
    #define KEY_5                         	6
    #define KEY_6                         	7
    #define KEY_7                         	8
    #define KEY_8                         	9
    #define KEY_9                         	10
    #define KEY_0                         	11
    #define KEY_MINUS                     	12
    #define KEY_PLUS                      	13
        
    #define KEY_BACKSPACE                 	14
    #define KEY_TAB                       	15
    #define KEY_Q                         	16
    #define KEY_W                         	17
    #define KEY_E                         	18
    #define KEY_R                         	19
    #define KEY_T                         	20
    #define KEY_Y                         	21
    #define KEY_U                         	22
    #define KEY_I                         	23
    #define KEY_O                         	24
    #define KEY_P                         	25
    #define KEY_L_BRACHET                 	26
    #define KEY_R_BRACHET                 	27
    #define KEY_ENTER                     	28
        
    #define KEY_CAPS_LOCK                 	58
    #define KEY_A                         	30
    #define KEY_S                         	31
    #define KEY_D                         	32
    #define KEY_F                         	33
    #define KEY_G                         	34
    #define KEY_H                         	35
    #define KEY_J                         	36
    #define KEY_K                         	37
    #define KEY_L                         	38
    #define KEY_SEMICOLON                 	39
    #define KEY_APOSTROPHE                	40
    #define KEY_BACKSLASH                 	43
        
    #define KEY_L_SHIFT                   	42
    #define KEY_Z                         	44
    #define KEY_X                         	45
    #define KEY_C                         	46
    #define KEY_V                         	47
    #define KEY_B                         	48
    #define KEY_N                         	49
    #define KEY_M                         	50
    #define KEY_COMMA                     	51
    #define KEY_POINT                     	51
    #define KEY_SLASH                     	51
    #define KEY_R_SHIFT                   	54
        
    #define KEY_CONTROL                   	29
    #define KEY_ALT                       	56
    #define KEY_SPACE                     	57
        
    #define KEY_INS                       	82
    #define KEY_HOME                      	71
    #define KEY_PGUP                      	73
    #define KEY_DEL                       	83
    #define KEY_END                       	79
    #define KEY_PGDN                      	81
        
    #define KEY_UP                        	72
    #define KEY_DOWN                      	80
    #define KEY_LEFT                      	75
    #define KEY_RIGHT                     	77
        
    #define KEY_NUM_LOCK                  	69
    #define KEY_C_BACKSLASH               	53
    #define KEY_C_ASTERISK                	55
    #define KEY_C_MINUS                   	74
    #define KEY_C_HOME                    	71
    #define KEY_C_UP                      	72
    #define KEY_C_PGUP                    	73
    #define KEY_C_LEFT                    	75
    #define KEY_C_CENTER                  	76
    #define KEY_C_RIGHT                   	77
    #define KEY_C_END                     	79
    #define KEY_C_DOWN                    	80
    #define KEY_C_PGDN                    	81
    #define KEY_C_INS                     	82
    #define KEY_C_DEL                     	83
    #define KEY_C_PLUS                    	78
    #define KEY_C_ENTER                   	28

    // Mouse button constants:
    #define MOUSE_LEFT                      100
    #define MOUSE_RIGHT                     101
    #define MOUSE_MIDDLE                    102
        
    // Joystick button constants:	
    #define JOY_LEFT                      	200
    #define JOY_UP                        	201
    #define JOY_RIGHT                     	202
    #define JOY_DOWN                      	203
    #define JOY_BUTTON1                   	204
    #define JOY_BUTTON2                   	205
    #define JOY_BUTTON3                   	206
    #define JOY_BUTTON4                   	207

    // Suported shift key constants:
    #define SHIFT_KEY_NONE                  300
    #define SHIFT_KEY_RIGHT_SHIFT           301
    #define SHIFT_KEY_LEFT_SHIFT            302
    #define SHIFT_KEY_CONTROL               304
    #define SHIFT_KEY_ALT                   308

    // Input action events:
    #define EVENT_KEY_PRESS                 0
    #define EVENT_KEY_DOWN                  1
    #define EVENT_KEY_UP                    2

    // ----------------------------------------------------------------------------
    // Parsed constant values
    // ----------------------------------------------------------------------------

    // Parsed key values:
    #define STR_INPUT_NONE          		"NONE"
                
    #define STR_KEY_ESC           			"KEY_ESC"
    #define STR_KEY_F1            			"KEY_F1"
    #define STR_KEY_F2            			"KEY_F2"
    #define STR_KEY_F3            			"KEY_F3"
    #define STR_KEY_F4            			"KEY_F4"
    #define STR_KEY_F5            			"KEY_F5"
    #define STR_KEY_F6            			"KEY_F6"
    #define STR_KEY_F7            			"KEY_F7"
    #define STR_KEY_F8            			"KEY_F8"
    #define STR_KEY_F9            			"KEY_F9"
    #define STR_KEY_F10           			"KEY_F10"
    #define STR_KEY_F11           			"KEY_F11"
    #define STR_KEY_F12           			"KEY_F12"
    #define STR_KEY_PRN_SCR       			"KEY_PRN_SCR"
    #define STR_KEY_SCROLL_LOCK   			"KEY_SCROLL_LOCK"
                
    #define STR_KEY_WAVE          			"KEY_WAVE"
    #define STR_KEY_1             			"KEY_1"
    #define STR_KEY_2             			"KEY_2"
    #define STR_KEY_3             			"KEY_3"
    #define STR_KEY_4             			"KEY_4"
    #define STR_KEY_5             			"KEY_5"
    #define STR_KEY_6             			"KEY_6"
    #define STR_KEY_7             			"KEY_7"
    #define STR_KEY_8             			"KEY_8"
    #define STR_KEY_9             			"KEY_9"
    #define STR_KEY_0             			"KEY_0"
    #define STR_KEY_MINUS         			"KEY_MINUS"
    #define STR_KEY_PLUS          			"KEY_PLUS"
                
    #define STR_KEY_BACKSPACE     			"KEY_BACKSPACE"
    #define STR_KEY_TAB           			"KEY_TAB"
    #define STR_KEY_Q             			"KEY_Q"
    #define STR_KEY_W             			"KEY_W"
    #define STR_KEY_E             			"KEY_E"
    #define STR_KEY_R             			"KEY_R"
    #define STR_KEY_T             			"KEY_T"
    #define STR_KEY_Y             			"KEY_Y"
    #define STR_KEY_U             			"KEY_U"
    #define STR_KEY_I             			"KEY_I"
    #define STR_KEY_O             			"KEY_O"
    #define STR_KEY_P             			"KEY_P"
    #define STR_KEY_L_BRACHET     			"KEY_L_BRACHET"
    #define STR_KEY_R_BRACHET     			"KEY_R_BRACHET"
    #define STR_KEY_ENTER         			"KEY_ENTER"
                
    #define STR_KEY_CAPS_LOCK     			"KEY_CAPS_LOCK"
    #define STR_KEY_A             			"KEY_A"
    #define STR_KEY_S             			"KEY_S"
    #define STR_KEY_D             			"KEY_D"
    #define STR_KEY_F             			"KEY_F"
    #define STR_KEY_G             			"KEY_G"
    #define STR_KEY_H             			"KEY_H"
    #define STR_KEY_J             			"KEY_J"
    #define STR_KEY_K             			"KEY_K"
    #define STR_KEY_L             			"KEY_L"
    #define STR_KEY_SEMICOLON     			"KEY_SEMICOLON"
    #define STR_KEY_APOSTROPHE    			"KEY_APOSTROPHE"
    #define STR_KEY_BACKSLASH     			"KEY_BACKSLASH"
                
    #define STR_KEY_L_SHIFT       			"KEY_L_SHIFT"
    #define STR_KEY_Z             			"KEY_Z"
    #define STR_KEY_X             			"KEY_X"
    #define STR_KEY_C             			"KEY_C"
    #define STR_KEY_V             			"KEY_V"
    #define STR_KEY_B             			"KEY_B"
    #define STR_KEY_N             			"KEY_N"
    #define STR_KEY_M             			"KEY_M"
    #define STR_KEY_COMMA         			"KEY_COMMA"
    #define STR_KEY_POINT         			"KEY_POINT"
    #define STR_KEY_SLASH         			"KEY_SLASH"
    #define STR_KEY_R_SHIFT       			"KEY_R_SHIFT"
                
    #define STR_KEY_CONTROL       			"KEY_CONTROL"
    #define STR_KEY_ALT           			"KEY_ALT"
    #define STR_KEY_SPACE         			"KEY_SPACE"
                
    #define STR_KEY_INS           			"KEY_INS"
    #define STR_KEY_HOME          			"KEY_HOME"
    #define STR_KEY_PGUP          			"KEY_PGUP"
    #define STR_KEY_DEL           			"KEY_DEL"
    #define STR_KEY_END           			"KEY_END"
    #define STR_KEY_PGDN          			"KEY_PGDN"
                
    #define STR_KEY_UP            			"KEY_UP"
    #define STR_KEY_DOWN          			"KEY_DOWN"
    #define STR_KEY_LEFT          			"KEY_LEFT"
    #define STR_KEY_RIGHT         			"KEY_RIGHT"
                
    #define STR_KEY_NUM_LOCK      			"KEY_NUM_LOCK"
    #define STR_KEY_C_BACKSLASH   			"KEY_C_BACKSLASH"
    #define STR_KEY_C_ASTERISK    			"KEY_C_ASTERISK"
    #define STR_KEY_C_MINUS       			"KEY_C_MINUS"
    #define STR_KEY_C_HOME        			"KEY_C_HOME"
    #define STR_KEY_C_UP          			"KEY_C_UP"
    #define STR_KEY_C_PGUP        			"KEY_C_PGUP"
    #define STR_KEY_C_LEFT        			"KEY_C_LEFT"
    #define STR_KEY_C_CENTER      			"KEY_C_CENTER"
    #define STR_KEY_C_RIGHT       			"KEY_C_RIGHT"
    #define STR_KEY_C_END         			"KEY_C_END"
    #define STR_KEY_C_DOWN        			"KEY_C_DOWN"
    #define STR_KEY_C_PGDN        			"KEY_C_PGDN"
    #define STR_KEY_C_INS         			"KEY_C_INS"
    #define STR_KEY_C_DEL         			"KEY_C_DEL"
    #define STR_KEY_C_PLUS        			"KEY_C_PLUS"
    #define STR_KEY_C_ENTER       			"KEY_C_ENTER"

    // Parsed mouse button values:
    #define STR_MOUSE_LEFT                  "MOUSE_LEFT"
    #define STR_MOUSE_RIGHT                 "MOUSE_RIGHT"
    #define STR_MOUSE_MIDDLE                "MOUSE_MIDDLE"

    // Parsed joystick button values:
    #define STR_JOY_LEFT          			"JOY_LEFT"
    #define STR_JOY_UP            			"JOY_UP"
    #define STR_JOY_RIGHT         			"JOY_RIGHT"
    #define STR_JOY_DOWN          			"JOY_DOWN"
    #define STR_JOY_BUTTON1       			"JOY_BUTTON1"
    #define STR_JOY_BUTTON2       			"JOY_BUTTON2"
    #define STR_JOY_BUTTON3       			"JOY_BUTTON3"
    #define STR_JOY_BUTTON4       			"JOY_BUTTON4"

    // Parsed suported shift key constants:
    #define STR_SHIFT_KEY_NONE              "SHIFT_KEY_NONE"
    #define STR_SHIFT_KEY_RIGHT_SHIFT       "SHIFT_KEY_RIGHT_SHIFT"
    #define STR_SHIFT_KEY_LEFT_SHIFT        "SHIFT_KEY_LEFT_SHIFT"
    #define STR_SHIFT_KEY_CONTROL           "SHIFT_KEY_CONTROL"
    #define STR_SHIFT_KEY_ALT               "SHIFT_KEY_ALT"

    // Parsed input action events:
    #define STR_EVENT_KEY_PRESS             "EVENT_KEY_PRESS"
    #define STR_EVENT_KEY_DOWN              "EVENT_KEY_DOWN"
    #define STR_EVENT_KEY_UP                "EVENT_KEY_UP"
#endif
