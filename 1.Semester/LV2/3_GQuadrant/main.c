#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 15 min
* progtimereal: ~17 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 2/3
*/

#define PRINT_COORDINATE_CHECK(IF,X,Y,TEXT) if (IF) printf("Der Punkt (%d,%d) %s\n", X, Y, TEXT);

int main()
{
	printf("Please insert x and y coordiante in following format: x,y: ");
	int x, y;
	if (scanf_s("%d,%d", &x, &y) < 2)
	{
		printf("Invalid input!");
		fseek(stdin, 0, SEEK_END);
		getchar();
		return -1;
	}

	PRINT_COORDINATE_CHECK(x == 0 && y == 0, x, y, "ist der Ursprung")
	PRINT_COORDINATE_CHECK(x == 0 && y != 0, x, y, "liegt auf der Y-Achse")
	PRINT_COORDINATE_CHECK(x != 0 && y == 0, x, y, "liegt auf der X-Achse")
	PRINT_COORDINATE_CHECK(x > 0  && y >  0, x, y, "liegt im 1. Quadranten")
	PRINT_COORDINATE_CHECK(x < 0  && y >  0, x, y, "liegt im 2. Quadranten")
	PRINT_COORDINATE_CHECK(x < 0  && y <  0, x, y, "liegt im 3. Quadranten")
	PRINT_COORDINATE_CHECK(x > 0  && y <  0, x, y, "liegt im 4. Quadranten")

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}