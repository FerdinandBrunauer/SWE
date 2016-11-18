#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 15 min
* progtimereal: ~20 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/2
*/

#define NUMBERS 10

double DoubleArraySum(double field[], unsigned int size)
{
	double result = 0;
	for (unsigned int i = 0; i < size; ++i)
	{
		result += field[i];
	}

	return result;
}

double DoubleArrayAverage(double field[], unsigned int size)
{
		return DoubleArraySum(field, size) / size;
}

double DoubleArrayMin(double field[], unsigned int size)
{
	double result = field[0];
	for (unsigned int i = 1; i < size; ++i)
	{
		if (field[i] < result)
		{
			result = field[i];
		}
	}

	return result;
}

unsigned int DoubleArrayCountSmallerThan(double field[], unsigned int size, double value)
{
	unsigned int sum = 0;

	for (unsigned int i = 0; i < size; i++)
	{
		if (field[i] < value)
		{
			sum += 1;
		}
	}

	return sum;
}

int main()
{
	double numbers[NUMBERS];
	printf("Please enter %d numbers:\n", NUMBERS);
	double read;
	for (int i = 0; i < NUMBERS; i++)
	{
		if (scanf_s("%lf", &read) < 1) 
		{
			printf("Invalid input! Aborted");
			fseek(stdin, 0, SEEK_END);
			getchar();
			return -1;
		}

		numbers[i] = read;
	}

	printf("Smallest: %lf\n", DoubleArrayMin(numbers, NUMBERS));
	printf("Average: %lf\n", DoubleArrayAverage(numbers, NUMBERS));
	printf("Values smaller than Average: %d\n", DoubleArrayCountSmallerThan(numbers, NUMBERS, DoubleArrayAverage(numbers, NUMBERS)));

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}