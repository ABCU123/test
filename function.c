#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <string.h>
#include<assert.h>
int is_in(char* wenben, char* search_word)
{
	int i = 0, j = 0, flag = -1;
	while (i < strlen(wenben) && j < strlen(search_word))
	{
		if (wenben[i] == search_word[j])
		{i++;
			j++;
		}
		else
		{
			i = i - j + 1;j = 0;}if (j == strlen(search_word))
		{ flag = 1;	break;
		}
	}
	return flag;
}
int find_string(char* strs, char* str)
{
	int len = strlen(strs);
	int i = 1;
	while (i < len + 1) {
		if (strcmp(strs, str) == 0) { 	break;
		}
		i++;
		strs++;
	}
	if (i == len + 1) {
		return -1;
	}
	return i;
}
char* GetSubstring(const char* strSource, const unsigned int uStartPos, const unsigned int uEndPos)
{
	unsigned int uLen = strlen(strSource);
	if (uLen == 0)
	{
		return (char*)"";
	}
	char* strTemp = (char*)malloc(uLen + 1);
	memset(strTemp, 0, uLen + 1);
	strcpy(strTemp, strSource);

	if (uStartPos > uLen)
	{
		free(strTemp);
		return (char*)"";
	}

	uLen = uEndPos - uStartPos;
	char* strSub = (char*)malloc(uLen + 1);
	memset(strSub, 0, uLen + 1);

	unsigned int i;
	for (i = 0; i <= uLen; i++)
	{
		strSub[i] = strTemp[uStartPos + i];
	}
	strSub[i] = '\0';
	free(strTemp);
	return strSub;
}
