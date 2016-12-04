#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 15 min
* progtimereal: ~17 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/3
*/

#define SECRET "1610555047"
#define SECRET_AT_POSITION(NUMBER) SECRET[NUMBER % strlen(SECRET)]

int main()
{
	char ch;
	unsigned long long number = 0;
	while ((ch = fgetc(stdin)) != EOF)
	{
		fputc(ch ^= SECRET_AT_POSITION(number++), stdout);
	}
}