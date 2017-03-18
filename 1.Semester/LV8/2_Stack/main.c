#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "Stack.h"

int main()
{
	Stack *stack = CreateStack();
	printf("Created new Stack.\n");
	printf("Stack empty:\t%s\n", IsEmptyStack(stack) ? "Yes" : "No");
	printf("Elements:\t%d\n", ElmentsStack(stack));
	printf("Top:\t\t%lf\n\n", TopStack(stack));

	printf("Push 10 elments from f(x)=x^4+4x^3+4x^2+0.5x where x > -3 and interval=0.75!\n");
	for (int i = 0; i < 10; i++)
	{
		double step = -3 + (0.75 * i);
		double value = (pow(step, 4)) + (4 * pow(step, 3)) + (4 * pow(step, 2)) + (0.5 * step);
		PushStack(stack, value);
		printf("Pushed:\t%lf\n", value);
	}

	printf("\nStack empty:\t%s\n", IsEmptyStack(stack) ? "Yes" : "No");
	printf("Elements:\t%d\n", ElmentsStack(stack));
	printf("Top:\t\t%lf\n\n", TopStack(stack));

	printf("Pop all element!");
	while (!IsEmptyStack(stack))
	{
		printf("Poped:\t%lf\n", PopStack(stack));
	}

	getch();
	return 0;
}