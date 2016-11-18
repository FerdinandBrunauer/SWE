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
* SWE1-ILV/B, exercise 3/5
*/

char *IntToBinary(int value)
{
	int bits = sizeof(int) * 8;
	char* binary = malloc(bits + 1);
	binary[bits] = '\0';

	int divider = 0b0001;
	for (int position = bits - 1; position >= 0; position--, divider <<= 1)
	{
		binary[position] = (value & divider) == divider ? '1' : '0';
	}

	return binary;
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

	printf("Binary: %s", IntToBinary(read));

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}