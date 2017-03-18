#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/**
* file: main.c
*
* date: 2016-12-03
* progtimeest.: < 5 min
* progtimereal: ~5 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 4/3
*/

int verdoppeln(int z)
{
	return z * 2;
}

int main()
{
	for (int i = 0; i < 25; i++)
	{
		printf("Das doppelte der Zahl %d ist %d\n", i, verdoppeln(i));
	}

	_getch();

	return 0;
}