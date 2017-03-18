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
* SWE1-ILV/B, exercise 2/5
*/

int main()
{
	printf("Please input base and exponent in format base,exponent: ");
	int base, exponent;
	if (scanf_s("%d,%d", &base, &exponent) < 2 || base < 0 || exponent < 0)
	{
		printf("Invalid input");
		fseek(stdin, 0, SEEK_END);
		getchar();
		return -1;
	}

	unsigned long long number = base;
	for (int i = 1; i < exponent; i++)
	{
		number *= base;
	}

	printf("Result: %llu", number);
	fseek(stdin, 0, SEEK_END);
	getchar();

	return 0;
}