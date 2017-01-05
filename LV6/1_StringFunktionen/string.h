#pragma once
#include <stdlib.h>

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
void FUNCTION_NAME(strcat)(char *src, char *dst);

/*
 * \brief: Searches the char \see:searchChar in a given string and returns the position
 */
int strchr(char *src, char searchChar);

/*
 * \brief: Compares two given strings. Returns <0 if dst is bevore src, 0 if equal, >0 if src is bevore
 */
int strcmp(char *comp1, char *comp2);

/*
* \brief: Copy the src string to dst string
*/
void FUNCTION_NAME(strcpy)(char *src, char *dst);

/*
 * \brief: Finds the first occurence
 /
void strcspn()« – einen Teilstring ermitteln
6. »strlen()« – Länge eines Strings ermitteln
7. »strncat()« – String mit n Zeichen aneinanderhängen
8. »strncmp()« – n Zeichen von zwei Strings miteinander vergleichen
9. »strncpy()« – String mit n Zeichen kopieren
10. »strpbrk()« – nach dem Auftreten bestimmter Zeichen suchen
11. »strrchr()« – das letzte Auftreten eines bestimmten Zeichens im String suchen
12. »strspn()« – das erste Auftreten eines Zeichens, das nicht vorkommt
13. »strstr()« – einen String nach dem Auftreten eines Teilstrings durchsuchen
14. »strtok()« – einen String anhand bestimmter Zeichen zerlegen*/