#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define STRING_FUNCTION_PREFIX my
#include "string.h"

#define HALLO_WELT "Hallo Welt!"
#define COMPARE(CHR1, CHR2, FUNCTION)							\
if (stringCompare(CHR1, CHR2))									\
{																\
	printf("Function %s is working!", FUNCTION);				\
}																\
else															\
{																\
	printf("Function %s is not working properly", FUNCTION);	\
}

bool stringCompare(char *chr1, char *chr2)
{
	int i = 0;
	while (chr1[i] != '\0' && chr2 != '\0')
	{
		if (chr1[i] != chr2[i])
		{
			return true;
		}

		i++;
	}

	return false;
}

int main()
{
	char text[20];
	strcpy(HALLO_WELT, text);
	COMPARE(text, HALLO_WELT, "strcpy")

	getch();
	return 0;
}