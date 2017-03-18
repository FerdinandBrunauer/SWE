#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 10 min
* progtimereal: ~5 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/1
*/

void printCharNTimes(char c, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		printf("%c", c);
	}
}

int main()
{
	int numRows;
	printf("Number of rows: ");
	if (scanf_s("%d", &numRows) < 1)
	{
		printf("Invalid input!");
		fseek(stdin, 0, SEEK_END);
		getchar();
		return -1;
	}

	for (int row = 0; row < numRows; row++)
	{
		printCharNTimes(' ', numRows - 1 - row);
		printCharNTimes('*', (2 * row) + 1);
		printf("\n");
	}

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}