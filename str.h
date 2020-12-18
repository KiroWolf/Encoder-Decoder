#ifndef STR
#define STR

enum CaseSensitive {
    Sensitive,
    Insensitive
};

int slen(const char* str);
void strCopy(const char* str, char** newStr);
int strCmp(const char* first, const char* second);
int stringToInt(const char* str);
char* getStrCopy(const char* str);
char* findSubstr(const char* str, const char* substr, enum CaseSensitive sensitive);

void mutableToUpper(char* str);
char* immutableToUpper(const char* str);

char* immutableToLower(const char* str);
void mutableToLower(char* str);

void mutableStrip(char* str);
char* immutableStrip(const char* str);

void mutableRemoveSpaces(char* str);
char* immutableRemoveSpaces(const char* str);

void mutableFilter(char* str);
char* immutableFilter(const char* str);

int isNumber(const char* str);
int isLetters(const char* str);

#endif
