#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

char Alphf[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char Alphs[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

char* immutableCaesarEncoder(char* text, int offset)
{
    //������� �������� �� ��������
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alphf[j % 27])
            {
                result[i] = Alphf[(j + offset) % 27];
                break;
            }

            if (result[i] == Alphs[j % 27])
            {
                result[i] = Alphs[(j + offset) % 27];
                break;
            }
        }
    }

    return result;
}

void mutableCaesarEncoder(char* text, int offset)
{
    //������� �������� �� ��������
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alphf[j % 27])
            {
                text[i] = Alphf[(j + offset) % 27];
                break;
            }

            if (text[i] == Alphs[j % 27])
            {
                text[i] = Alphs[(j + offset) % 27];
                break;
            }
        }
    }
}

char* immutableCaesarDecoder(char* text, int offset)
{
    //������� �������� �� ��������
    //char* result = (char*)calloc(sizeof(text), sizeof(text));
    //memcpy(result, text, sizeof(text));
    char* result;
    strcpy(result, text);
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i] == Alphf[j % 27])
            {
                result[i] = Alphf[(j - offset) % 27];
                break;
            }

            if (result[i] == Alphs[j % 27])
            {
                result[i] = Alphs[(j - offset) % 27];
                break;
            }
        }
    }

    return result;
}

void mutableCaesarDecoder(char* text, int offset)
{
    //������� �������� �� ��������
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == Alphf[j % 27])
            {
                text[i] = Alphf[(j - offset) % 27];
                break;
            }

            if (text[i] == Alphs[j % 27])
            {
                text[i] = Alphs[(j - offset) % 27];
                break;
            }
        }
    }
}

char* immutableXorCoder(char* text, char* key)
{
    //����������/������������ ����������� ���
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
    //����������/������������ ����������� ���
    int keySize = sizeof(key);
    for (int i = 0; i < 128; i++)
    {
        text[i] = text[i] ^ key[i % keySize + 1];
    }
}