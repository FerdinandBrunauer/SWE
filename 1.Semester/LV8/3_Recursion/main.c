#include <stdlib.h>
#include <stdio.h>

unsigned long rFac(int value)
{
	if (value > 0)
	{
		return value * rFac(value - 1);
	}

	return 1;
}

unsigned long iFac(int value)
{
	unsigned long temp = 1;
	for (int i = 1; i <= value; i++)
	{
		temp *= i;
	}

	return temp;
}

void iCountDown(int value)
{
	for (int i = value; i >= 0; i--)
	{
		printf(i == 0 ? "%d\n" : "%d, ", i);
	}
}

void rCountDown(int value)
{
	printf(value == 0 ? "%d\n" : "%d, ", value);
	if (value > 0)
	{
		rCountDown(value - 1);
	}
}

void iCountUp(int value, const int max)
{
	for (int i = value; i <= max; i++)
	{
		printf(i == max ? "%d\n" : "%d, ", i);
	}
}

void rCountUp(int value, const int max)
{
	printf(value == max ? "%d\n" : "%d, ", value);
	if (value < max)
	{
		rCountUp(value + 1, max);
	}
}

int main()
{
	printf("** Fakultaet **\n");
	printf("Iterativ:\t%d\n", iFac(7));
	printf("Recursiv:\t%d\n", rFac(7));

	printf("\n** CountUp **\n");
	printf("Iterativ:\t");
	iCountUp(0, 7);
	printf("Recursiv:\t");
	rCountUp(0, 7);

	printf("\n** CountDown **\n");
	printf("Iterativ:\t");
	iCountDown(7);
	printf("Recursiv:\t");
	rCountDown(7);


	getch();
	return 0;
}