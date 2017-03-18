#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * \brief: Returns a 16-Bit big short array of a random binary 16 bit integer.
 */
short *RandBin()
{
	const short count = 16;

	int randomInt = rand();
	while (randomInt < 0)
	{
		randomInt = rand();
	}

	int divider = 0b1;
	short *result = malloc(count * sizeof(short));
	for (int i = 0; i < count; i++, divider <<= 1)
	{
		result[count - i - 1] = (randomInt & divider) == divider ? 1 : 0;
	}

	return result;
}

int main()
{
	// Init random
	srand(time(NULL));

	short *binary = RandBin();
	printf("Random binary number: ");
	for (int i = 0; i < 16; i++)
	{
		printf("%d", binary[i]);
	}
	printf("\n");

	free(binary);

	getch();
	return;
}