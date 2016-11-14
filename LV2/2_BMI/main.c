#include <stdio.h>
#include <stdlib.h>

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
* SWE1-ILV/B, exercise 2/2
*/

typedef enum Sex
{
	Male,
	Female
} Sex;

typedef struct Classification
{
	Sex sex;
	int from;
	int to;
	char *classification;
} Classification;

volatile struct Classification classification[] =
{
	// SEX		FROM		TO		CLASSIFICATION
	{ Male,		-1,			20,		"Untergewicht" },
	{ Male,		20,			25,		"Normalgewicht" },
	{ Male,		25,			30,		"Übergewicht" },
	{ Male,		30,			40,		"Adipositas" },
	{ Male,		40,			-1,		"Massive Adipositas" },

	{ Female,	-1,			19	,	"Untergewicht" },
	{ Female,	19,			24,		"Normalgewicht" },
	{ Female,	24,			30,		"Übergewicht" },
	{ Female,	31,			40,		"Adipositas" },
	{ Female,	40,			-1,		"Massive Adipositas" }
};

char* GetClassification(Sex sex, double bmi)
{
	int size = sizeof(classification) / sizeof(classification[0]);
	for (int i = 0; i < size; ++i)
	{
		if (classification[i].sex != sex)
		{
			continue;
		}

		if (classification[i].from < 0 && bmi < classification[i].to)
		{
			return classification[i].classification;
		}

		if (classification[i].to < 0 && bmi > classification[i].from)
		{
			return classification[i].classification;
		}

		if (classification[i].from < bmi && classification[i].to > bmi)
		{
			return classification[i].classification;
		}
	}

	return "Can not classificate!";
}

#define PRINT_AND_EXIT_WRONG_INPUT		\
	printf("Invalid input!");			\
	fseek(stdin, 0, SEEK_END);			\
	getchar();							\
	return -1;							\

#define SAFE_SCAN(FORMAT, VARIABLE)		\
if (scanf_s(FORMAT, VARIABLE) < 1)		\
{										\
	PRINT_AND_EXIT_WRONG_INPUT			\
}										\

int main()
{
	double weight, size;
	Sex sex;

	printf("Sex [m/f]: ");
	char sexChar;
	SAFE_SCAN("%c", &sexChar)
	if (sexChar > 90)
	{
		sexChar -= 32; // Convert lower to capital letter (if it is)
	}

	if (sexChar == 'M')
	{
		sex = Male;
	}
	else if (sexChar == 'F')
	{
		sex = Female;
	}
	else
	{
		PRINT_AND_EXIT_WRONG_INPUT
	}

	printf("Weight [0-1000kg]: ");
	SAFE_SCAN("%lf", &weight)
	if (weight < 0 || weight > 1000)
	{
		PRINT_AND_EXIT_WRONG_INPUT
	}

	printf("Size [0-400cm]: ");
	SAFE_SCAN("%lf", &size)
	if (size < 0 || size > 400)
	{
		PRINT_AND_EXIT_WRONG_INPUT
	}
	size /= 100; // cm to m

	double bmi = weight / (size * size);
	printf("Bmi: %lf\n", bmi);
	printf("Classification: %s", GetClassification(sex, bmi));
	fseek(stdin, 0, SEEK_END);
	getchar();

	return 0;
}