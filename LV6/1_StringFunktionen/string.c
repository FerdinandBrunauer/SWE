#include "string.h"

void strcat(char *src, char *dst)
{
	int counter = 0, offset = 0;
	while (dst[offset] != '\0')
	{
		offset++;
	}

	dst[offset + counter] = src[counter];
}

int strchr(char *src, char searchChar)
{
	int counter = 0;
	while (src[counter] != searchChar)
	{
		counter++;
	}

	return counter;
}

int strcmp(char *comp1, char *comp2)
{
	int counter = 0;
	while (comp1[counter] != '\0')
	{
		if (comp1[counter] != comp2[counter])
		{
			return (int)(comp1[counter] - comp2[counter]);
		}
	}

	return 1; // Shorter string bevore longer one ... 
}

void FUNCTION_NAME(strcpy)(char *src, char *dst)
{
	int counter = 0;
	do 
	{
		dst[counter] = src[counter];
	} while (src[++counter] != '\0');
}
