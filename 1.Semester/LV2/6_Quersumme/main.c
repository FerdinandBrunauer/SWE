#define _CRT_SECURE_NO_WARNINGS

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

	if (scanf("%20s", number) != 1)
	{
		printf("Invalid input!");
			fseek(stdin, 0, SEEK_END);
			getchar();
			return -1;
	}

	unsigned long long sum = 0;
	for (int i = 0; i < MAX_LENGTH && number[i] != '\0'; i++)
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