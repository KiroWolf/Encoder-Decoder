#include <stdlib.h>
#include <assert.h>
#include "str.h"

static const int Difference = ('a' - 'A');

int slen(const char* str) {
    size_t size = 0;
    while (str[size] != '\0') {
        ++size;
    }
    return size;
}

void strCopy(const char* str, char** newStr) {
    const size_t size = slen(str);
    *newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        (*newStr)[i] = str[i];
    }
    (*newStr)[size] = '\0';
}

int strCmp(const char* first, const char* second) {
    size_t firstSize = slen(first);
    size_t secondSize = slen(second);
    if (firstSize != secondSize) {
        return 0;
    }

    for (size_t i = 0; i < firstSize; ++i) {
        if (first[i] != second[i]) {
            return 0;
        }
    }

    return 1;
}

int stringToInt(const char* str) {
    int result = 0;
    size_t size = slen(str);
    
    assert(isNumber(str));

    size_t i = 0;
    char sign = 0;
    if (size > 0 && str[0] == '-') {
        sign = 1;
        i = 1;
    }
    for (; i < size; ++i) {
        result = result * 10 + (str[i] - '0');
    }
    if (sign == 1) {
        result = (-1) * result;
    }

    return result;
}

char* getStrCopy(const char* str) {
    const size_t size = slen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        newStr[i] = str[i];
    }
    newStr[size] = '\0';

    return newStr;
}

char* findSubstr(const char* str, const char* substr, 
                enum CaseSensitive sensitive)
{
    char* tStr = getStrCopy(str);
    char* tSubstr = getStrCopy(substr);

    if (sensitive == Insensitive) {
        free(tStr);
        free(tSubstr);
        tStr = immutableToLower(str);
        tSubstr = immutableToLower(substr);
    }

    const size_t sizeStr = slen(tStr);
    const size_t sizeSubstr = slen(tSubstr);
    size_t k = 0;

    for (size_t i = 0; i < sizeStr - sizeSubstr + 1; ++i) {
        if (tStr[i] == tSubstr[k]) {
            ++k;
            for (size_t j = i + 1; j < i + sizeSubstr; ++j) {
                if (tStr[j] != tSubstr[k]) {
                    break;
                }
                ++k;
            }
            if (k == sizeSubstr) {
                return ((char*) str + i);
            }
            k = 0;
        }
    }

    free(tStr);
    free(tSubstr);

    return ((char*) str + sizeStr);
}


void mutableToUpper(char* str) {
    for (size_t i = 0; i < slen(str); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= Difference;
        }
    }
}

void mutableToLower(char* str) {
    for (size_t i = 0; i < slen(str); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += Difference;
        }
    }
}

char* immutableToUpper(const char* str) {
    const size_t size = slen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            newStr[i] = str[i] - Difference;
        }
        else {
            newStr[i] = str[i];
        }
    }
    newStr[size] = '\0';

    return newStr;
}

char* immutableToLower(const char* str) {
    const size_t size = slen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            newStr[i] = str[i] + Difference;
        }
        else {
            newStr[i] = str[i];
        }
    }
    newStr[size] = '\0';

    return newStr;
}


void mutableStrip(char* str) {
    const size_t size = slen(str);
    int startSpaces = 0;
    int endSpaces = 0;

    for (size_t i = 0; i < size; ++i) {
        if (str[i] == ' ') {
            ++startSpaces;
        }
        else {
            break;
        }
    }
    for (size_t i = size - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            ++endSpaces;
        }
        else {
            break;
        }
    }

    const size_t strNormalSize = size - startSpaces - endSpaces;
    for (int i = 0; i < strNormalSize; ++i) {
        str[i] = str[startSpaces + i];
    }
    str[strNormalSize] = '\0';
}

char* immutableStrip(const char* str) {
    const size_t size = slen(str);
    int startSpaces = 0;
    int endSpaces = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == ' ') {
            ++startSpaces;
        }
        else {
            break;
        }
    }
    for (int i = size - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            ++endSpaces;
        }
        else {
            break;
        }
    }

    const int strNormalSize = size - startSpaces - endSpaces;
    char* newStr = (char*) malloc(sizeof(char) * (strNormalSize + 1));
    for (int i = 0; i < strNormalSize; ++i) {
        newStr[i] = str[startSpaces + i];
    }
    newStr[strNormalSize] = '\0';

    return newStr;
}


void mutableFilter(char* str) {
    const size_t size = slen(str);
    size_t k = 0;
    for (size_t i = 0; i < size; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == ' '))
        {
            str[k] = str[i];    
            ++k;
        }
    }
    str[k] = '\0';
}

char* immutableFilter(const char* str) {
    const size_t size = slen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    size_t k = 0;

    for (size_t i = 0; i < size; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == ' '))
        {
            newStr[k] = str[i];    
            ++k;
        }
    }
    newStr[k] = '\0';

    return newStr;
}


int isNumber(const char* str) {
    const size_t size = slen(str);
    
    for (size_t i = 0; i < size; ++i) {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-')) {
            return 0;
        }
    }

    return 1;
}
        
int isLetters(const char* str) {
    const size_t size = slen(str);

    for (size_t i = 0; i < size; ++i) {
        if (!((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')))
        {
            return 0;
        }
    }
    
    return 1;
}


