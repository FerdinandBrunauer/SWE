#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 15 min
* progtimereal: ~10 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 2/6
*/

#define MAX_LENGTH 20

int main()
{
	printf("Please enter a long number: ");
	char number[MAX_LENGTH];
	fgets(number, sizeof(char), stdin);

	unsigned long long sum = 0;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (number[i] >= 48 && number[i] <= 57)
		{
			sum += ((int)number[i]) - 48;
		}
		else
		{
			printf("Invalid input");
			fseek(stdin, 0, SEEK_END);
			getchar();
			return -1;
		}
	}

	printf("Result: %lld", sum);
	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}