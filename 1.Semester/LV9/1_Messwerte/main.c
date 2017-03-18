#include <stdlib.h>
#include <stdio.h>

#include "Messung.h"
#include "Messwert.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Please provide the File as first argument!\n");
		getch();
		return -1;
	}

	Messung *messung = LoadFromFile(argv[1]);
	printf(
		"Loaded %d Messungen from File %c at Location %lf, %lf.",
		messung->rows,
		messung->filename,
		messung->longitude,
		messung->latitude
	);

	// TODO add functions for average and so on

	getch();
	return 0;
}