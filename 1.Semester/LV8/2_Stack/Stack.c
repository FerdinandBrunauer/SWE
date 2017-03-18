#include "Stack.h"

Stack* CreateStack()
{
	Stack *stack = malloc(sizeof(Stack));
	stack->elements = 0;
	stack->top = NULL;
	return stack;
}

void DelStack(Stack *stack)
{
	if (stack == NULL)
	{
		return;
	}

	StackElement *elementBuffer = stack->top;
	while (elementBuffer != NULL)
	{
		StackElement *temp = elementBuffer->bottom;
		free(elementBuffer);
		elementBuffer = temp;
	}

	free(stack);
}

void ResetStack(Stack *stack)
{
	StackElement *elementBuffer = stack->top;
	while (elementBuffer != NULL)
	{
		StackElement *temp = elementBuffer->bottom;
		free(elementBuffer);
		elementBuffer = temp;
	}

	stack->elements = 0;
	stack->top = NULL;
}

void PushStack(Stack *stack, double data)
{
	StackElement *newElement = malloc(sizeof(StackElement));
	newElement->value = data;
	newElement->bottom = stack->top;
	stack->top = newElement;
	stack->elements++;
}

double PopStack(Stack *stack)
{
	if (stack->top == NULL)
	{
		return 0.0;
	}

	double temp = stack->top->value;
	StackElement *buffer = stack->top;
	stack->top = buffer->bottom;
	stack->elements--;
	free(buffer);
	return temp;
}

double TopStack(Stack *stack)
{
	if (stack->top == NULL)
	{
		return 0.0;
	}

	return stack->top->value;
}

bool IsEmptyStack(Stack *stack)
{
	return stack->top == NULL;
}

unsigned int ElmentsStack(Stack *stack)
{
	return stack->elements;
}

