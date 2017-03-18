#pragma once
#include <stdio.h>
#include "Messwert.h"

typedef struct Messung
{
	double latitude;
	double longitude;
	char *filename;
	int rows;
	Messwert *messwerte;
} Messung;

Messung* LoadFromFile(char *file);