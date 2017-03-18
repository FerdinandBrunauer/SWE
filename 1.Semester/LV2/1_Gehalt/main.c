#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 5 min
* progtimereal: < 5 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 2/1
*/

int main()
{
	printf("Enter Gehalt vorher: ");
	double gehalt;
	if (scanf_s("%lf", &gehalt) > 0 && gehalt > 0)
	{
		if (gehalt > 1000)
		{
			gehalt *= 1.0085; // 0,85%
		}
		else
		{
			gehalt *= 1.0209; // 2,09%
		}

		printf("Nachher: %lf", gehalt);

		fseek(stdin, 0, SEEK_END);
		getchar();
		return 0;
	}

	printf("Failed! Invalid input");
	fseek(stdin, 0, SEEK_END);
	getchar();
	return -1;
}