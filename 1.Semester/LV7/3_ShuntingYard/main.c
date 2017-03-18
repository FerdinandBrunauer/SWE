#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ArrayStack.h"
#include "Constants.h"

/*
 * \brief: The shunting yard algorithm is a pretty well known Algorithm to convert a mathematical expression (infix notation) to a postfix notation also called Reverse
			polish notation.
			In this implementation it is only possible to use the operators ^, *, /, + and -. Only Numbers from 0 - 9 are allowed
 */

typedef enum Associativity {
	LEFT,
	RIGHT
} Associativity;

typedef struct Operator {
	char operator;
	short precedence;
	enum Associativity associativity;
	bool isBracket;
} Operator;

Operator operators[] =
{
	{	'^',	4,	RIGHT,	false	},
	{	'*',	3,	LEFT,	false	},
	{	'/',	3,	LEFT,	false	},
	{	'+',	2,	LEFT,	false	},
	{	'-',	2,	LEFT,	false	},
	{	'(',	0,	LEFT,	true	},
	{	')',	0,	LEFT,	true	}
};

Operator* getOperator(char readChar)
{
	short foundOperators = sizeof(operators) / sizeof(Operator);
	for (int i = 0; i < foundOperators; i++)
	{
		if (readChar == operators[i].operator)
		{
			return &operators[i];
		}
	}

	return NULL;
}

int main()
{
	ArrayStack stack;
	InitArrayStack(&stack);

	printf("Examples: 3+4*2/(1-5)^2^3 OR 3 + 4\n\n");

	char buffer[MAX_ARRAY_SIZE];
	while (1)
	{
		ClearArrayStack(&stack);

		printf("Your input: ");
		fgets(buffer, MAX_ARRAY_SIZE, stdin);

		for (int i = 0; i < MAX_ARRAY_SIZE && buffer[i] != '\n'; i++)
		{
			if (buffer[i] == ' ')
			{
				continue;
			}

			if (buffer[i] >= '0' && buffer[i] <= '9')
			{
				printf("%c ", buffer[i]);
				continue;
			}

			Operator* foundOperator = getOperator(buffer[i]);
			if (foundOperator != NULL && !foundOperator->isBracket) // It is a operator doe!
			{
				while
				(
					(
						!IsArrayStackEmpty(&stack)
						&&
						!((Operator*)TopOfArrayStack(&stack))->isBracket
					)
					&&
					(
						(foundOperator->associativity == LEFT && foundOperator->precedence <= ((Operator*)TopOfArrayStack(&stack))->precedence)
						||
						(foundOperator->associativity == RIGHT && foundOperator->precedence < ((Operator*)TopOfArrayStack(&stack))->precedence)
					)
				)
				{
					printf("%c ", ((Operator*)PopFromArrayStack(&stack))->operator);
				}

				PushToArrayStack(&stack, foundOperator, sizeof(Operator));
				continue;
			}

			if (foundOperator->isBracket && foundOperator->operator == '(')
			{
				PushToArrayStack(&stack, foundOperator, sizeof(Operator));
				continue;
			}

			if (foundOperator->isBracket && foundOperator->operator == ')')
			{
				// if error -> mismatched parantheses
				while (!IsArrayStackEmpty(&stack) && !((Operator*)TopOfArrayStack(&stack))->isBracket)
				{
					Operator *popedOperator = PopFromArrayStack(&stack);
					if (popedOperator->operator != '(')
					{
						printf("%c ", popedOperator->operator);
					}
				}

				if (IsArrayStackEmpty(&stack))
				{
					printf("\nParantheses mismatch!\n\n");
					break;
				}

				PopFromArrayStack(&stack); // Remaining parantheses

				continue;
			}
		}

		while (!IsArrayStackEmpty(&stack))
		{
			printf("%c ", ((Operator*)PopFromArrayStack(&stack))->operator);
		}

		printf("\n\n");
	}
}