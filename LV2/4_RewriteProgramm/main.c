#include <stdlib.h>
#include <stdio.h>

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
* SWE1-ILV/B, exercise 2/1
*/

int main()
{
	int line = 0;
	int ch;
	printf("Line %d: ", ++line);
	while ((ch = fgetc(stdin)) != EOF)
	{
		if (ch == '\n')
		{
			printf("\nLine %d: ", ++line);
		}
		else
		{
			fputc(ch, stdout);
		}
	}

	return 0;
}