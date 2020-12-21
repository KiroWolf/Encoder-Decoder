#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "StringUtils.h"

int main(int argc, char** argv)
{
	char method[10] = {""};
	char text[128] = {""};
	char key[32] = {""};

	if (argc == 1)
	{
		printf("input method of encrypt, text and key to encode: \n");
		scanf("%s %s %s", method, text, key);
	}
	else if (argc == 4)
	{
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		strcpy(key, argv[3]);
	}
	else
	{
		printf("invalid number of arguments. please try again\n");
		return -1;
	}

	mutableToLower(method);
	mutableFilter(method);
	mutableStrip(method);
	if ((method[0] != 'x' || method[1] != 'o' || method[2] != 'r') 
		&& (method[0] != 'c' || method[1] != 'a' || method[2] != 'e'))
	{
		printf("invalid method: %s. please try again\n", method);
		return -1;
	}

	mutableFilter(text);
	mutableStrip(text);

	if (method[0] == 'x')
	{
		mutableXorCoder(text, key);
	}
	else
	{
		mutableStripALL(key);
		int bool = isNumber(key);
		if (bool == 1)
		{
			int offset = atoi(key);
			mutableCaesarEncoder(text, offset);
		}
		else
		{
			printf("invalid offset. please try again\n");
			return -1;
		}
	}

	printf("encoded text: \n");
	puts(text);

	return 0;
}
