#pragma once

#include <stdlib.h>
#include <stdbool.h>

/*
*	+---+
*	| N |
*	+---+
*	| 5 |
*	+---+
*	| 4 |
*	+---+
*	| 3 |
*	+---+
*	| 2 |
*	+---+
*	| 1 |
*	+---+
*	| 0 |
*	+---+
*/
typedef struct StackElement
{
	double value;
	struct StackElement *bottom;
} StackElement;

typedef struct Stack
{
	unsigned int elements;
	struct StackElement *top;
} Stack;

Stack* CreateStack();
void DelStack(Stack *stack);
void ResetStack(Stack *stack);

void PushStack(Stack *stack, double data);
double PopStack(Stack* stack);
double TopStack(Stack *stack);

bool IsEmptyStack(Stack *stack);
unsigned int ElmentsStack(Stack *stack);
