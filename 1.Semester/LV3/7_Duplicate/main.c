#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 20 min
* progtimereal: ~15 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/7
*/

int main()
{
	int numbers;
	printf("Please enter a number: ");
	if (scanf_s("%d", &numbers) < 1)
	{
		printf("Invalid Input!");
		fseek(stdin, 0, SEEK_END);
		getchar();
		return -1;
	}

	bool *invalidEntries = malloc(sizeof(bool) * numbers);
	int *readNumbers = malloc(sizeof(int) * numbers);
	int read;
	for (int i = 0; i < numbers; i++)
	{
		invalidEntries[i] = false; // Default

		printf("Number %d: ", i + 1);
		if (scanf_s("%d", &read) < 1)
		{
			printf("Invalid Input! Again.");
			i--;
			continue;
		}

		readNumbers[i] = read;
	}

	for (int i = 0; i < numbers; i++)
	{
		if (invalidEntries[i]) // already invalid -> marked all duplicates
		{
			continue;
		}

		for (int j = i + 1; j < numbers; j++)
		{
			if (readNumbers[i] == readNumbers[j])
			{
				invalidEntries[j] = true;
			}
		}
	}

	printf("\n**Output**\n");
	int offset = 0;
	for (int i = 0; i < numbers; i++)
	{
		if (invalidEntries[i])
		{
			offset++;
			continue;
		}

		printf("Number %d: %d\n", i - offset + 1, readNumbers[i]);
	}

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}