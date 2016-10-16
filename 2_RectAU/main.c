#include <stdio.h>
#include <stdlib.h>

/**
* file: main.c
*
* date: 2016-10-10
* progtimeest.: < 1sec
* progtimereal: < 1  sec
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 2
*/

#define RETURN_CODE_INVALID_INPUT -1
#define RETURN_CODE_SUCCESS 0;

/*
* \return 0 = Succes, -1 = Failure
*/
int ReadUnsignedInt(const char *variableName, unsigned int *variable)
{
	printf("%s: ", variableName);
	int temp;
	if (scanf_s("%d", &temp) > 0)
	{
		if (temp > 0)
		{
			*variable = temp; // write the value to the address of the pointer
			return 0;
		}

		return -1;
	}

	return -1;
}

int main()
{
	printf("Please input dimensions of a Rectangle ...\n");

	unsigned int length, width;
	int error = 0x0; // Combine the error codes
	error |= ReadUnsignedInt("Length", &length);
	error |= ReadUnsignedInt("Width", &width);

	// We have to flush the input stream because otherwise the getchar methods below won't work
	fseek(stdin, 0, SEEK_END);

	if (error < 0)
	{
		printf("Invalid input ...");
		getchar();
		return RETURN_CODE_INVALID_INPUT;
	}

	printf("\nArea: %d\n", length * width);
	printf("Scope: %d", (length + width) * 2);

	getchar();
	printf("\nFinished ...");

	return RETURN_CODE_SUCCESS;
}