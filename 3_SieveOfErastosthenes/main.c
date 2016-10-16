#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 1sec
* progtimereal: < 1  sec
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3
*/

#define RETURN_CODE_INVALID_INPUT -1
#define RETURN_CODE_SUCCESS 0;

// Const to define the FieldSize
#define FIELD_SIZE 1000

int main()
{
	bool array[FIELD_SIZE];
	int i;
	for (i = 0; i < FIELD_SIZE; ++i)
	{
		array[i] = true;
	}

	int square = (int)sqrt(FIELD_SIZE);
	int j;
	for (i = 2; i < square; ++i)
	{
		if (array[i] == false)
		{
			continue;
		}

		// Found new prime!

		for (j = i * i; j < FIELD_SIZE; j += i)
		{
			array[j] = false;
		}
	}

	printf("Primes: ");
	bool first = true;
	for (i = 1; i < FIELD_SIZE; i++)
	{
		if (array[i] == false)
		{
			// No prime :(
			continue;
		}

		if (first)
		{
			printf("%d", i);
			first = !first;
		}
		else
		{
			printf(", %d", i);
		}
	}

	printf("\nFinished ...");
	getchar();
	return 0;
}