#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/**
* file: main.c
*
* date: 2016-12-03
* progtimeest.: < 10 min
* progtimereal: ~10 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 4/1
*/

void printMatrix(int *matrix, int rows, int coloums)
{
	for (int row = 0; row < rows; row++)
	{
		printf("(\t");
		for (int coloum = 0; coloum < coloums; coloum++)
		{
			printf(coloum == (coloums - 1) ? "%d\t" : "%d, \t", matrix[(row * coloums) + coloum]);
		}
		printf(")\n");
	}
}

int main()
{
	int matrix[3][3] = { { 1, 3, -4 }, { 1, 1, -2 }, { -1, -2, 5 } };
	printMatrix(matrix, 3, 3);

	_getch();
	return 0;
}