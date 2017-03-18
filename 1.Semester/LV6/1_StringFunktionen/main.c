#define _CRT_SECURE_NO_WARNINGS // Disable warning when using "unsafe" string functions
#include "string.h"	// My string functions
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>	// Original string functions

#define ARRAY_SIZE 50
#define HALLO "HALLO"
#define WELT "WELT"

void printCompareState(int result, char *functionName)
{
	if (result == 0)
	{
		printf("%s works perfectly!\n", functionName);
	}
	else
	{
		printf("%s failed the test!\n", functionName);
	}
}

void printSuccessState(bool result, char *functionName)
{
	printCompareState(result ? 0 : 1, functionName);
}

void testStrcat()
{
	char src1[ARRAY_SIZE], src2[ARRAY_SIZE], dst1[ARRAY_SIZE], dst2[ARRAY_SIZE];
	strcpy(src1, WELT);
	strcpy(dst1, HALLO);
	strcpy(src2, WELT);
	strcpy(dst2, HALLO);

	strcat(dst1, src1);
	mystrcat(dst2, src2);

	printCompareState(strcmp(dst1, dst2), "strcat");
}

void testStrchr()
{
	char string[] = "Ein Teststring mit Worten";

	int result = strcmp(strchr(string, (int)'W'), mystrchr(string, (int)'W'))
		+ strcmp(strchr(string, (int)'T'), mystrchr(string, (int)'T'));
	printCompareState(result, "strchr");
}

void testStrcmp()
{
	bool result = true;

	const char string1[] = HALLO;
	const char string2[] = WELT;
	const char string3[] = HALLO;

	result &= strcmp(string1, string2) == mystrcmp(string1, string2);
	result &= strcmp(string1, string3) == mystrcmp(string1, string3);

	printSuccessState(result, "strcmp");
}

void testStrcpy()
{
	char src1[ARRAY_SIZE], src2[ARRAY_SIZE], dst1[ARRAY_SIZE], dst2[ARRAY_SIZE];
	strcpy(src1, HALLO);
	strcpy(dst1, WELT);
	mystrcpy(src2, HALLO);
	mystrcpy(dst2, WELT);

	bool result = true;
	result &= strcmp(src1, src2) == 0 ? true : false;
	result &= strcmp(dst1, dst2) == 0 ? true : false;

	printSuccessState(result, "strcpy");
}

void testStrcspn()
{
	char s1[] = "Das ist ein Text";
	char s2[] = "tbc";

	printSuccessState(strcspn(s1, s2) == mystrcspn(s1, s2), "strcpsn");
}

void testStrlen()
{
	char string[] = "Ein Teststring mit Worten";
	printSuccessState(strlen(string) == mystrlen(string), "strlen");
}

void testStrncat()
{
	char src1[ARRAY_SIZE], src2[ARRAY_SIZE], dst1[ARRAY_SIZE], dst2[ARRAY_SIZE];
	strcpy(src1, WELT);
	strcpy(dst1, HALLO);
	strcpy(src2, WELT);
	strcpy(dst2, HALLO);

	strncat(dst1, src1, 2);
	mystrncat(dst2, src2, 2);

	printCompareState(strcmp(dst1, dst2), "strncat");
}

void testStrncmp()
{
	bool result = true;

	const char string1[] = HALLO;
	const char string2[] = WELT;
	const char string3[] = HALLO;

	result &= strncmp(string1, string2, 2) == mystrncmp(string1, string2, 2);
	result &= strncmp(string1, string3, 2) == mystrncmp(string1, string3, 2);

	printSuccessState(result, "strncmp");
}

void testStrncpy()
{
	char src1[ARRAY_SIZE], src2[ARRAY_SIZE], dst1[ARRAY_SIZE], dst2[ARRAY_SIZE];
	strncpy(src1, HALLO, 2);
	strncpy(dst1, WELT, 2);
	mystrncpy(src2, HALLO, 2);
	mystrncpy(dst2, WELT, 2);

	bool result = true;
	result &= strncmp(src1, src2, 2) == 0 ? true : false;
	result &= strncmp(dst1, dst2, 2) == 0 ? true : false;

	printSuccessState(result, "strncpy");
}

void testStrpbrk()
{
	char string[] = "Schwein gehabt!";
	char search[] = "aeiou";
	printCompareState(strcmp(strpbrk(string, search), mystrpbrk(string, search)), "strpbrk");
}

void testStrrchr()
{
	const char string[] = "Ein Teststring mit Worten";

	int result = mystrcmp(strrchr(string, (int)'W'), mystrrchr(string, 'W'))
		+ mystrcmp(strrchr(string, (int)'T'), mystrrchr(string, 'T'));
	printCompareState(result, "strrchr");
}

void testStrspn()
{
	char strtext[] = "129th";
	char cset[] = "1234567890";

	int number = strspn(strtext, cset);

	printSuccessState(strspn(strtext, cset) == mystrspn(strtext, cset), "strspn");
}

void testStrstr()
{
	char string[] = "This is a simple string";
	printCompareState(strcmp(strstr(string, "simple"), mystrstr(string, "simple")), "strstr");
}

void testStrtok()
{
	const char *delimeters = " ,.-";
	const char orgString[] = "- This, a sample string.";
	const char ownString[] = "- This, a sample string.";
	int orgCounter = 0;
	char *orgResults[ARRAY_SIZE];
	int ownCounter = 0;
	char *ownResults[ARRAY_SIZE];

	char *buffer = strtok(orgString, delimeters);
	while (buffer != NULL)
	{
		orgResults[orgCounter++] = buffer;
		buffer = strtok(NULL, delimeters);
	}

	buffer = mystrtok(ownString, delimeters);
	while (buffer != NULL)
	{
		ownResults[ownCounter++] = buffer;
		buffer = mystrtok(NULL, delimeters);
	}

	bool result = true;
	result &= orgCounter == ownCounter;
	while (result && orgCounter-- > 0 && ownCounter-- > 0)
	{
		result &= strcmp(orgResults[orgCounter], ownResults[ownCounter]) == 0 ? true : false;
	}

	printSuccessState(result, "strtok");
}

int main()
{
	testStrcat();
	testStrchr();
	testStrcmp();
	testStrcpy();
	testStrcspn();
	testStrlen();
	testStrncat();
	testStrncmp();
	testStrncpy();
	testStrpbrk();
	testStrrchr();
	testStrspn();
	testStrstr();
	testStrtok();

	getch();
	return 0;
}