#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

char Alphf[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char Alphs[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

char* immutableCaesarEncoder(char* text, int offset)
{
    //простое смещение по алфавиту
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alphf[j % 26])
            {
                result[i] = Alphf[(j + offset) % 26];
                break;
            }

            if (result[i] == Alphs[j % 26])
            {
                result[i] = Alphs[(j + offset) % 26];
                break;
            }
        }
    }

    return result;
}

void mutableCaesarEncoder(char* text, int offset)
{
    //простое смещение по алфавиту
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alphf[j % 26])
            {
                text[i] = Alphf[(j + offset) % 26];
                break;
            }

            if (text[i] == Alphs[j % 26])
            {
                text[i] = Alphs[(j + offset) % 26];
                break;
            }
        }
    }
}

char* immutableCaesarDecoder(char* text, int offset)
{
    //простое смещение по алфавиту
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    int buff;
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            buff = (j - offset) % 26;
            if (buff < 0)
            {
                buff = 26 + buff;
            }

            if (result[i] == Alphf[j % 26])
            {
                result[i] = Alphf[buff];
                break;
            }
            if (result[i] == Alphs[j % 26])
            {
                result[i] = Alphs[buff];
                break;
            }
        }
    }

    return result;
}

void mutableCaesarDecoder(char* text, int offset)
{
    //простое смещение по алфавиту
    int buff;
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            buff = (j - offset) % 26;
            if (buff < 0)
            {
                buff = 26 + buff;
            }

            if (text[i] == Alphf[j % 26])
            {
                text[i] = Alphf[buff];
                break;
            }
            if (text[i] == Alphs[j % 26])
            {
                text[i] = Alphs[buff];
                break;
            }
        }
    }
}

char* immutableXorCoder(char* text, char* key)
{
    //шифрование/дешифрование исключающим ИЛИ
    int keySize = sizeof(key);
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < 128; i++)
    {
        result[i] = result[i] ^ key[i % keySize + 1];
    }

    return result;
}

void mutableXorCoder(char* text, char* key)
{
    //шифрование/дешифрование исключающим ИЛИ
    int keySize = sizeof(key);
    for (int i = 0; i < 128; i++)
    {
        text[i] = text[i] ^ key[i % keySize + 1];
    }
}
