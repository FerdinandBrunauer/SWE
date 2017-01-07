#include "string.h"

void FUNCTION_NAME(strcat)(char *dst, char *src)
{
	int counter = 0, offset = 0;
	while (dst[offset] != '\0')
	{
		offset++;
	}

	while (src[counter] != '\0')
	{
		dst[offset + counter] = src[counter];
		counter++;
	}

	dst[offset + counter] = '\0';
}

char* FUNCTION_NAME(strchr)(const char *src, int search)
{
	while (*src != (char)search)
	{
		src++;
	}

	return src;
}

int FUNCTION_NAME(strcmp)(const char *comp1, const char *comp2)
{
	int counter = 0;
	while (comp1[counter] != '\0')
	{
		if (comp1[counter] != comp2[counter])
		{
			int difference = (comp1[counter] - comp2[counter]);
			return difference < 0 ? -1 : 1;
		}

		counter++;
	}

	if (comp1[counter] == '\0')
	{
		return 0;
	}

	return 1; // Shorter string bevore longer one ...
}

void FUNCTION_NAME(strcpy)(char *dst, char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}

int FUNCTION_NAME(strcspn)(char *src, char *search)
{
	int counter = 0;

	while (src[counter] != '\0')
	{
		int innerCounter = 0;
		while (search[innerCounter] != '\0')
		{
			if (src[counter] == search[innerCounter])
			{
				return counter;
			}

			innerCounter++;
		}

		counter++;
	}

	return counter;
}

int FUNCTION_NAME(strlen)(const char *src)
{
	int counter = 0;

	while (src[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

void FUNCTION_NAME(strncat)(char *dst, const char *src, int num)
{
	int counter = 0, offset = 0;
	while (dst[offset] != '\0')
	{
		offset++;
	}

	while (src[counter] != '\0' && num > 0)
	{
		dst[offset + counter] = src[counter];
		counter++;
		num--;
	}

	dst[offset + counter] = '\0';

	return 0;
}

int FUNCTION_NAME(strncmp)(const char *str1, const char *str2, int num)
{
	for (int i = 0; (i < num) && (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		if (str1[i] != str2[i])
		{
			int difference = (str1[i] - str2[i]);
			return difference < 0 ? -1 : 1;
		}
	}

	// Maybe there should be a difference between 1 and -1
	if ((str1[num - 1] == '\0') || (str2[num - 1] == '\0'))
	{
		return 1;
	}

	return 0;
}

void FUNCTION_NAME(strncpy)(char *dst, const char *src, int num)
{
	for (int i = 0; i < num; i++)
	{
		dst[i] = src[i];
	}
}

char* FUNCTION_NAME(strpbrk)(const char *src, char *search)
{
	int searchLength = FUNCTION_NAME(strlen)(search);

	while (*src != '\0')
	{
		int found = 0;
		for (int i = 0; i < searchLength; i++)
		{
			found += *src == search[i] ? 1 : 0;
		}

		if (found > 0)
		{
			return src;
		}

		src++;
	}

	return src;
}

char* FUNCTION_NAME(strrchr)(const char *src, char search)
{
	int length = FUNCTION_NAME(strlen)(src) - 1;
	int i;
	for (i = 0; i < length; i++)
	{
		if (src[length - i] == search)
		{
			break;
		}
	}

	for (int counter = length - i; counter > 0; counter--)
	{
		src++;
	}

	return src;
}

int FUNCTION_NAME(strspn)(const char *src, const char *search)
{
	int counter = 0;
	while (src[counter] != '\0')
	{
		int found = 0, innerCounter = 0;
		while (search[innerCounter] != '\0' && found < 1)
		{
			found += src[counter] == search[innerCounter] ? 1 : 0;
			innerCounter++;
		}

		if (found < 1)
		{
			return counter;
		}

		counter++;
	}

	return counter;
}

char* FUNCTION_NAME(strstr)(const char *src, const char *search)
{
	int searchLength = FUNCTION_NAME(strlen)(search);

	while (*src != '\0')
	{
		int counter = 0;
		while (src[counter] == search[counter])
		{
			counter++;
		}

		if (counter == searchLength)
		{
			return src;
		}

		src++;
	}

	return NULL;
}

char* FUNCTION_NAME(strtok)(char *src, const char *delimeters)
{
	static char *buffer;
	int delimeterLength = FUNCTION_NAME(strlen)(delimeters);

	if (src != NULL)
	{
		buffer = src;
	}

	while (*buffer != '\0')
	{
		int foundDelimeters = 0;
		for (int i = 0; i < delimeterLength && foundDelimeters < 1; i++)
		{
			foundDelimeters += *buffer == delimeters[i] ? 1 : 0;
		}

		if (foundDelimeters > 0)
		{
			buffer++;
			continue;
		}

		break;
	}

	// Return string
	char *temp = malloc(FUNCTION_NAME(strlen)(buffer) * sizeof(char));
	int tempCounter = 0;
	while (*buffer != '\0')
	{
		int foundDelimeters = 0;
		for (int i = 0; i < delimeterLength && foundDelimeters < 1; i++)
		{
			foundDelimeters += *buffer == delimeters[i] ? 1 : 0;
		}

		if (foundDelimeters > 0)
		{
			temp[tempCounter++] = '\0';
			return temp;
		}

		temp[tempCounter++] = *buffer++;
	}

	return NULL;
}
