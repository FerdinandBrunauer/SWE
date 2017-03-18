#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 5 min
* progtimereal: ~5 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 2/7
*/

int main()
{
	// 4 ways to print the numbers 1 - 5

	printf("** WHILE **\n");
	int i = 1;
	while (i <= 5)
	{
		printf("%d\n", i);
		i++;
	}

	printf("\n** FOR **\n");
	for (i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
	}

	printf("\n** DO WHILE **\n");
	i = 0;
	do
	{
		i++;
		printf("%d\n", i);
	} while (i <= 4);

	printf("\n** QUADRAT **\n");
	int x, y, size;
	size = 3;
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	getchar();
	return 0;
}