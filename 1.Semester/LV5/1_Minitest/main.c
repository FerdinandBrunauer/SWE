#include <stdio.h>
#include <stdlib.h>

#define DIM 4
int b[DIM][DIM] = { 0 };

void main()
{
	int i, j;
	for (i = 0; i < DIM; i++)
		for (j = i; j < DIM; j++)
			b[i][j] = i + 1;

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			printf("%i   ", b[j][i]);
		}

		printf("\n");
	}

	getch();
	return(0);
}