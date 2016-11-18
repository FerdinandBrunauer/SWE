#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 30 min
* progtimereal: ~30 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/6
*/

#define MAX_ROMANIAN_LENGTH 30

char *IntToRomanian(int value)
{
	char* romanian = malloc(sizeof(char) * MAX_ROMANIAN_LENGTH);
	for (int i = 0; i < MAX_ROMANIAN_LENGTH; i++)
	{
		romanian[i] = ' ';
	}

	return romanian;
}

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

	printf("Romanian: %s", IntToRomanian(read));

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}