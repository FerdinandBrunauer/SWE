#include "ArrayStack.h"

void InitArrayStack(ArrayStack* stack)
{
	stack->top = 0;
}

bool IsArrayStackFull(ArrayStack* stack)
{
	// We check for greater or equal because nothing is perfect
	return stack->top >= (MAX_ARRAY_SIZE);
}

bool IsArrayStackEmpty(ArrayStack* stack)
{
	// We check for smaller than 1 because nothing is perfect
	return stack->top < 1;
}

void ClearArrayStack(ArrayStack *stack)
{
	while (!IsArrayStackEmpty(stack))
	{
		free(PopFromArrayStack(stack));
	}
}

void* TopOfArrayStack(ArrayStack* stack)
{
	if (IsArrayStackEmpty(stack))
	{
		return 0;
	}

	return stack->data[stack->top - 1];
}

/*
* \return false if stack is full, true if it is inserted successful
*/
bool PushToArrayStack(ArrayStack* stack, void* data, size_t size)
{
	if (IsArrayStackFull(stack))
	{
		return false;
	}

	stack->data[stack->top++] = memcpy(malloc(size), data, size);
	return true;
}

/*
* \return the pointer to the data. Make sure to free the memory!
*/
void* PopFromArrayStack(ArrayStack* stack)
{
	if (IsArrayStackEmpty(stack))
	{
		return NULL;
	}

	// It is voodoo magic. The -- decrements the value after executing the statement
	return stack->data[--stack->top];
}