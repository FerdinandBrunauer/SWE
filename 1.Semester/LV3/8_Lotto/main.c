#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
* SWE1-ILV/B, exercise 3/8
*/

int main()
{
	srand(time((time_t)NULL)); // Set random seed

	for (int i = 0; i < 100; i++)
	{
		printf("Tipp %d: %d\n", i, rand() % (45 - 1) + 1); // rand % (max - min) + min
	}

	getchar();
	return 0;
}