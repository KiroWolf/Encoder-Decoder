#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringUtils.h"

char Alph1[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char Alph2[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char Numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void mutableToLower(char* text)
{
    /*по 1 чару сравниваю с алфавитом и присваиваю соответствующую
    маленькую букву*/
    for (int i = 0; i < sizeof(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alph1[j])
            {
                text[i] = Alph2[j];
                break;
            }
        }
    }
}

char* immutableToLower(char* text)
{
    /*по 1 чару сравниваю с алфавитом и присваиваю соответствующую
    маленькую букву*/
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < sizeof(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alph1[j])
            {
                result[i] = Alph2[j];
                break;
            }
        }
    }

    return result;
}

void mutableToUpper(char* text)
{
    /*аналогично с toLower, только сравнение со 2 алфавитом*/
    for (int i = 0; i < sizeof(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alph2[j])
            {
                text[i] = Alph1[j];
                break;
            }
        }
    }
}

char* immutableToUpper(char* text)
{
    /*аналогично с toLower, только сравнение со 2 алфавитом*/
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < sizeof(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alph2[j])
            {
                result[i] = Alph1[j];
                break;
            }
        }
    }

    return result;
}

void mutableStrip(char* text)
{
    int count1 = 0;
    int count2 = 0;
    int mode = 0;
    //подсчет пробелов спереди
    for (int i = 0; i < sizeof(text); i++)
    {
        if (text[i] == ' ')
        {
            count1++;
        }
        else
        {
            mode = 1;
            break;
        }
    }
    //подсчет пробелов сзади
    if (mode == 1)
    {
        for (int i = sizeof(text) - 1; i >= 0; i--)
        {
            if (text[i] != ' ')
            {
                mode++;
                if (mode < 3)
                {
                    count2 = 0;
                }
            }
            else
            {
                count2++;
            }
            if (mode == 3)
            {
                break;
            }
        }
    }
    //удаление задних пробелом присваиванием к NULL
    if (count2 > 0)
    {
        for (int i = sizeof(text) - count2 - 1; i < sizeof(text) - 1; i++)
        {
            text[i] = NULL;
        }
    }
    /*удаление передних пробелов смещением элементов и последующее присваиваниее смещенного элемента к NULL*/
    if (count1 > 0)
    {
        for (int i = 0; i < 128 - count1; i++)
        {
            text[i] = text[i + count1];
            text[i + count1] = NULL;
        }
    }
}

char* immutableStrip(char* text)
{
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    int count1 = 0;
    int count2 = 0;
    int mode = 0;
    //подсчет пробелов спереди
    for (int i = 0; i < sizeof(text); i++)
    {
        if (result[i] == ' ')
        {
            count1++;
        }
        else
        {
            mode = 1;
            break;
        }
    }
    //подсчет пробелов сзади
    if (mode == 1)
    {
        for (int i = sizeof(text) - 1; i >= 0; i--)
        {
            if (result[i] != ' ')
            {
                mode++;
                if (mode < 3)
                {
                    count2 = 0;
                }
            }
            else
            {
                count2++;
            }
            if (mode == 3)
            {
                break;
            }
        }
    }
    //удаление задних пробелом присваиванием к NULL
    if (count2 > 0)
    {
        for (int i = sizeof(text) - count2 - 1; i < sizeof(text) - 1; i++)
        {
            result[i] = NULL;
        }
    }
    /*удаление передних пробелов смещением элементов и последующее присваиваниее смещенного элемента к NULL*/
    if (count1 > 0)
    {
        for (int i = 0; i < sizeof(text) - count1; i++)
        {
            result[i] = result[i + count1];
            result[i + count1] = NULL;
        }
    }

    return result;
}

void mutableStripALL(char* text)
{
    //просто удаление всех пробелов
    for (int i = 0; i < sizeof(text); i++)
    {
        if (text[i] == ' ' || text[i] == '\0' || text[i] == '\n')
        {
            text[i] = NULL;
        }
    }
}

char* immutableStripALL(char* text)
{
    //просто удаление всех пробелов
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < sizeof(text); i++)
    {
        if (result[i] == ' ' || result[i] == '\0' || result[i] == '\n')
        {
            result[i] = NULL;
        }
    }

    return result;
}

void mutableFilter(char* text)
{
    /*сравнение по чару со всеми допустимыми символами со всех известных алфавитов
    bool принимает значение 1 если найден соответсвующий элемент в алфавитах*/
    int bool;
    for (int i = 0; i < sizeof(text); i++)
    {
        bool = 0;
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alph1[j] || text[i] == Alph2[j])
            {
                bool = 1;
                break;
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (text[i] == Numbers[j])
            {
                bool = 1;
                break;
            }
        }
        if (text[i] == ' ')
        {
            bool = 1;
        }
        
        //удаление элементов, не соответствующих допустимым
        if (bool == 0)
        {
            text[i] = NULL;
        }
    }
}

char* immutableFilter(char* text)
{
    /*сравнение по чару со всеми допустимыми символами со всех известных алфавитов
    bool принимает значение 1 если найден соответсвующий элемент в алфавитах*/
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    int bool;
    for (int i = 0; i < sizeof(text); i++)
    {
        bool = 0;
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alph1[j] || result[i] == Alph2[j])
            {
                bool = 1;
                break;
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (result[i] == Numbers[j])
            {
                bool = 1;
                break;
            }
        }
        if (result[i] == ' ')
        {
            bool = 1;
        }

        //удаление элементов, не соответствующих допустимым
        if (bool == 0)
        {
            result[i] = NULL;
        }
    }

    return result;
}

int isNumber(char* text)
{
    //чары сверяются с алфавитом Numbers 1 - число, 0 - не число
    int bool;
    for (int i = 0; i < sizeof(text); i++)
    {
        bool = 0;
        for (int j = 0; j < 9; j++)
        {
            if (text[i] == Numbers[j] || text[i] == '\0' || text[i] == '\n')
            {
                bool = 1;
                break;
            }
        }
        
        if (bool == 0)
        {
            return 0;
        }
    }

    return 1;
}

int isLetters(char* text)
{
    //чары сверяются с буквенными алфавитами 1 - буквы, 0 - состоит не только из букв
    int bool;
    for (int i = 0; i < sizeof(text); i++)
    {
        bool = 0;
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alph1[j] || text[i] == Alph2[j] || text[i] == '\0' || text[i] == '\n')
            {
                bool = 1;
                break;
            }
        }

        if (bool == 0)
        {
            return 0;
        }
    }

    return 1;
}
