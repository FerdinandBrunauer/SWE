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
* SWE1-ILV/B, exercise 3/4
*/

int main()
{
	int read;
	printf("Please enter a number: ");
	if (scanf_s("%d", &read) < 1)
	{
		printf("Invalid Input!");
		fseek(stdin, 0, SEEK_END);
		getchar();
		return -1;
	}

	printf("Hex: %x", read);
	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}