#include <stdlib.h>
#include <stdio.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 20 min
* progtimereal: ~15 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 3/6
*/

static int i_roman[] =		{ 1000,	900,	500,	400,	100,	90,		50,		40,		10,		9,		5,		4,		1	};
static char *s_roman[] =	{ "M",	"CM",	"D",	"CD",	"C",	"XC",	"L",	"XL",	"X",	"IX",	"V",	"IV",	"I"	};

void DoRomanian(int* value)
{
	for (int i = 0; i < sizeof(i_roman) / sizeof(int); i++)
	{
		if ((*value - i_roman[i]) >= 0)
		{
			*value -= i_roman[i];
			printf("%s", s_roman[i]);
			return;
		}
	}
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

	printf("Romanian: ");
	while (read > 0)
	{
		DoRomanian(&read);
	}

	fseek(stdin, 0, SEEK_END);
	getchar();
	return 0;
}