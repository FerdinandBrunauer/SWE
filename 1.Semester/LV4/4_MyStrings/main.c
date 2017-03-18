#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/**
* file: main.c
*
* date: 2016-12-03
* progtimeest.: < 10 min
* progtimereal: ~15 min
* author: Ferdinand Brunauer
* email: fbrunauer.itsb-b2016@fh-salzburg.ac.at
*
* Salzburg University of Applied Sciences
* Information Technology & Systems Management
* SWE1-ILV/B, exercise 4/4-6
*/

int mystrlen(char src[])
{
	int length = 0;
	while (src[length] != '\0')
	{
		length++;
	}

	return length;
}

void mystrcpy(char dest[], char src[])
{
	int counter = 0;
	while (src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter++;
	}

	dest[counter] = '\0';
}

void mystrcat(char dest[], char src[])
{
	int srcCounter = 0;
	int destOffset = mystrlen(dest);

	while (dest[srcCounter] != '\0')
	{
		dest[destOffset + srcCounter] = src[srcCounter];
		srcCounter++;
	}

	dest[destOffset + srcCounter] = '\0';
}

int main()
{
	char customString1[100] = "Ich bin ein TestString ....";
	char customString2[100] = "Ich bin ein weiterer TestString ....";
	char result[100];

	printf("Length of %s is %d\n", customString1, mystrlen(customString1));
	printf("Length of %s is %d\n", customString2, mystrlen(customString2));

	mystrcpy(result, customString1);
	printf("Length of %s is %d\n", result, mystrlen(result));

	mystrcat(customString1, customString2);
	printf("Length of %s is %d\n", customString1, mystrlen(customString1));

	_getch();
	return 0;
}