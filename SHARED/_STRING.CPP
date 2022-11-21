/* ----------------------------------------------------------------------------
 * String functions for all DIV DLLs.
 * (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
 * DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
 * ---------------------------------------------------------------------------- */
 
#include "_string.h"

static bool isValidString(const string str)
{
    return str || strlen(str) > 0;
}

static void strcase(string str, const int mode)
{
    if (isValidString(str))
    {
        size_t len = strlen(str);
        
        for(int i = 0; i < len; i++) 
            str[i] = mode ? tolower(str[i]) : toupper(str[i]);
    }
}

string strmalloc(const size_t size)
{
    size_t len = size + 1;
    string ptr = (string)div_malloc(len);
	
    memset(ptr, '\0', len);
	
    return ptr;
}
 
size_t strltrim(string str)
{
    size_t ret = RESULT_ERROR;
    
    if (isValidString(str))
    {
        size_t len = strlen(str);

        for (int i = 0; i < len; i++)
            if (str[i] != ' ')
            {
                string value = (string)&str[i];
                
                strcpy(str, value);
                
                break;
            }
        
        ret = strlen(str);
    }

    return ret;
}

size_t strrtrim(string str)
{
    size_t ret = RESULT_ERROR;
    
    if (isValidString(str))
    {        
        size_t len = strlen(str);

        for (int i = len - 1; i >= 0; i--)
            if (str[i] == ' ')
                str[i] = '\0';
            else
                break;
        
        ret = strlen(str);
    }

    return ret;
}

size_t strtrim(string str)
{
    strltrim(str);
    
    return strrtrim(str);
}

void strreplace(string str, const char oldChar, const char newChar)
{
    if (isValidString(str))
    {
        size_t len = strlen(str);

        for (int i = 0; i < len; i++)
            if (str[i] == oldChar) str[i] = newChar;
    }
}

bool strempty(const string str)
{
    bool ret = false;

    if (isValidString(str))
	{
        size_t len = strlen(str);
	
        for (int i = 0; i < len; i++)
            if (str[i] != ' ')
            {    
                ret = false;

                break;
            }
        
        ret = true;
    }

    return ret;
}

int batoi(const string str)
{
    int ret = RESULT_ERROR;

    if (isValidString(str))
    {
        string copy = div_strdup(str);
    
        strlwr(copy);
        strtrim(copy);

        ret = strequal(copy, STRING_TRUE);
        
        div_free(copy);
    }

    return ret;    
}

string div_strdup(const string str)
{
    string ret = NULL;

    if (isValidString(str))
    {
        size_t len = strlen(str);
        string copy = strmalloc(len);
    
        strcpy(copy, str);
    
        ret = copy;
    }

    return ret;
}
