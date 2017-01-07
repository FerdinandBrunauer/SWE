#pragma once
#include <stdlib.h>

// In this project i defined the needed define in the command line arguments but
// it should also be no problem to define it here. When you do not define
// this preprocessor directive, u can replace the original string.h with this implementation
// Command line argument (gcc, build): -D STRING_FUNCTION_PREFIX=my
#if defined STRING_FUNCTION_PREFIX
#define FUNCTION_PASTER(ARG1,ARG2) ARG1 ## ARG2
#define FUNCTION_EVALUATER(ARG1,ARG2) FUNCTION_PASTER(ARG1, ARG2)
#define FUNCTION_NAME(FUNCTION) FUNCTION_EVALUATER(STRING_FUNCTION_PREFIX, FUNCTION)
#else
#define FUNCTION_NAME(FUNCTION) FUNCTION
#endif

/*
 * \brief: Adds the string from src to the destination string
 */
void FUNCTION_NAME(strcat)(char *dst, char *src);

/*
 * \brief: Searches the char \see:searchChar in a given string and returns the position
 */
char* FUNCTION_NAME(strchr)(const char *src, int search);

/*
 * \brief: Compares two given strings. Returns <0 if dst is bevore src, 0 if equal, >0 if src is bevore
 */
int FUNCTION_NAME(strcmp)(const char *comp1, const char *comp2);

/*
 * \brief: Copy the src string to dst string
 */
void FUNCTION_NAME(strcpy)(char *dst, char *src);

/*
 * \brief: Finds the position of the first occurence of search
 */
int FUNCTION_NAME(strcspn)(char *src, char *search);

/*
 * \brief: Returns the length of the given string
 */
int FUNCTION_NAME(strlen)(const char *src);

/*
 * \brief: Adds max num chars from src to dst
 */
void FUNCTION_NAME(strncat)(char *dst, const char *src, int num);

/*
 * \brief: Compares num chars from two strings
 */
int FUNCTION_NAME(strncmp)(const char *str1, const char *str2, int num);

/*
 * \brief: Copy num chars from src beyond dst
 */
void FUNCTION_NAME(strncpy)(char *dst, const char *src, int num);

/*
 * \brief: Returns the given string beginning with the first occurence of search
 */
char* FUNCTION_NAME(strpbrk)(const char *src, char *search);

/*
 * \brief: Returns the last occurence of search in src
 */
char* FUNCTION_NAME(strrchr)(const char *src, char search);

/*
 * \brief: Returns the length until a search char does not occur
 */
int FUNCTION_NAME(strspn)(const char *src, const char *search);

/*
 * \brief: Returns the src string, beginning by the first occurence of search
 */
char* FUNCTION_NAME(strstr)(const char *src, const char *search);

/*
 * \brief: Splits the given string into multiple substrings using the given delimeters.
 * When the given string is NULL, the last string is taken
 */
char* FUNCTION_NAME(strtok)(char *src, const char *deltimeters);