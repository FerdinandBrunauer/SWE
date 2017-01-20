#define _CRT_SECURE_NO_WARNINGS // Disable warning when using "unsafe" string functions
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Vector.h"

#define A 65
#define Z 90
#define IdentifierCount (Z - A)
#define ConsoleBuffer 80

#define CHECK_IDENTIFIER(IDENTIFIER, PRINTMESSAGE)									\
if (IDENTIFIER < A || IDENTIFIER > Z)												\
{																					\
	printf(PRINTMESSAGE ? "Invalid identifier! Only A to Z is allowed\n\n" : "");	\
	continue;																		\
}

struct Vector* vectors[IdentifierCount];

char getNextFreeIdentifier()
{
	for (int i = 0; i < IdentifierCount; i++)
	{
		if (vectors[i] == NULL)
		{
			printf("New Vector %c created!\n\n", i + A);
			return A + i;
		}
	}

	printf("No free Identifier found! Please delete a existing vector!\n");
	return ' '; // Invalid identifier ...
}

void printHelp()
{
	printf("Usage: You can define N Vectors. A Vectors needs 3 coordinates and an upper case Identifier.\n");
	printf("If you define a new Vector with an already exisiting Identifier, the old one will be overwritten.\n");
	printf("If you use a calculation method, the resulting Vector will receive the first free Identifier. Skalars will be printed directly.\n\n");

	printf("Define a Vector: define IDENTIFIER X Y Z, Example: define A 2 2 2\n");
	printf("Delete a Vector: delete IDENTIFIER, Example: delete A\n\n");

	printf("Add two Vectors: add IDENTIFIER IDENTIFIER, Example add A B\n");
	printf("Subtract two Vectors: sub IDENTIFIER IDENTIFIER, Example sub A B\n");
	printf("Scalar product from 2 Vectors: scalar IDENTIFIER IDENTIFIER, Example scalar A B\n");
	printf("Cross product from 2 Vectors: cross IDENTIFIER IDENTIFIER, Example cross A B\n");
	printf("Spat product from 3 Vectros: spat IDENTIFIER IDENTIFIER IDENTIFIER, Example spat A B C\n");
	printf("Multiply with scalar: mult IDENTIFIER skalar, Example mult A 5\n\n");

	printf("Print specific Vector: print IDENTIFIER, Example print A\n");
	printf("Print all defined Vectors: print\n");
	printf("Print help: help\n");
	printf("Exit the calculator: exit\n\n");
	// TODO add remaining operations
}

int main()
{
#pragma region Test
#ifdef DEBUG
	struct Vector *vector1 = newVector(1, 2, 3);
	struct Vector *vector2 = newVector(4, 5, 6);
	struct Vector *vector3 = newVector(7, 8, 9);

	struct Vector *vResult = addVectors(3, vector1, vector2, vector3);
	vResult = subVectors(3, vector3, vector2, vector1);
	double dResult = scalarProduct(vector1, vector2);
	vResult = crossProduct(vector1, vector2);
	dResult = spatProduct(vector1, vector2, vector3);
	vResult = multWithSkalar(vector1, 5);

	free(vector1);
	free(vector2);
	free(vector3);
	free(vResult);
#endif // DEBUG
#pragma endregion
	printf("Welcome to the vector calculater by Ferdi\n\n");
	printHelp();

	// Init vector store
	for (int i = 0; i < IdentifierCount; i++)
	{
		vectors[i] = NULL;
	}

	char buffer[ConsoleBuffer];
	char identifier, identifier1, identifier2;
	double x, y, z, skalar;
	while (1)
	{
		printf("Your command: ");
		fgets(buffer, ConsoleBuffer, stdin);

		if (sscanf(buffer, "define %c %lf %lf %lf\n", &identifier, &x, &y, &z) > 3)
		{
			CHECK_IDENTIFIER(identifier, true)

			if (vectors[identifier - A] == NULL)
			{
				vectors[identifier - A] = newVector(x, y, z);
				printf("Successfully created!\n\n");
				continue;
			}

			*vectors[identifier - A]->x = x;
			*vectors[identifier - A]->y = y;
			*vectors[identifier - A]->z = z;
			printf("Overwritten Vector %c\n\n", identifier);
			continue;
		}

		if (sscanf(buffer, "delete %c\n", &identifier) > 0)
		{
			CHECK_IDENTIFIER(identifier, true)

			if (vectors[identifier - A] != NULL)
			{
				printf("Deleted successful!\n\n");
				free(vectors[identifier - A]);
				vectors[identifier - A] = NULL;
			}
			else
			{
				printf("Non existing Vector!\n\n");
			}

			continue;
		}

		if (sscanf(buffer, "add %c %c\n", &identifier, &identifier1) > 1)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)

			char newIdentifier = getNextFreeIdentifier();
			CHECK_IDENTIFIER(newIdentifier, false);

			vectors[newIdentifier - A] = addVectors(2, vectors[identifier - A], vectors[identifier1 - A]);
			continue;
		}

		if (sscanf(buffer, "sub %c %c\n", &identifier, &identifier1) > 1)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)

			char newIdentifier = getNextFreeIdentifier();
			CHECK_IDENTIFIER(newIdentifier, false);

			vectors[newIdentifier - A] = subVectors(2, vectors[identifier - A], vectors[identifier1 - A]);
			continue;
		}

		if (sscanf(buffer, "scalar %c %c\n", &identifier, &identifier1) > 1)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)

			printf("Scalar product from %c and %c = %lf\n\n", identifier, identifier1, scalarProduct(vectors[identifier - A], vectors[identifier1 - A]));
			continue;
		}

		if (sscanf(buffer, "cross %c %c\n", &identifier, &identifier1) > 1)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)

			char newIdentifier = getNextFreeIdentifier();
			CHECK_IDENTIFIER(newIdentifier, false);

			vectors[newIdentifier - A] = crossProduct(vectors[identifier - A], vectors[identifier1 - A]);
			continue;
		}

		if (sscanf(buffer, "mult %c %lf\n", &identifier, &skalar) > 1)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)

			char newIdentifier = getNextFreeIdentifier();
			CHECK_IDENTIFIER(newIdentifier, false);

			vectors[newIdentifier - A] = multWithSkalar(vectors[identifier - A], skalar);
			continue;
		}

		if (sscanf(buffer, "spat %c %c %c\n", &identifier, &identifier1, &identifier2) > 2)
		{
			CHECK_IDENTIFIER(identifier, true)
			CHECK_IDENTIFIER(identifier1, true)
			CHECK_IDENTIFIER(identifier2, true)

			printf("Spat product from %c, %c and %c = %lf\n\n", identifier, identifier1, identifier2, spatProduct(vectors[identifier - A], vectors[identifier1 - A], vectors[identifier2 - A]));
			continue;
		}

		if (sscanf(buffer, "print %c\n", &identifier) > 0)
		{
			CHECK_IDENTIFIER(identifier, true)

			if (vectors[identifier - A] != NULL)
			{
				printf("\t\t%lf\n", *vectors[identifier - A]->x);
				printf("%c\t->\t%lf\n", identifier, *vectors[identifier - A]->y);
				printf("\t\t%lf\n\n", *vectors[identifier - A]->z);
			}
			else
			{
				printf("Non existing Vector!\n\n");
			}

			continue;
		}

		if (strcmp(buffer, "print\n") == 0)
		{
			for (int i = 0; i < IdentifierCount; i++)
			{
				if (vectors[i] != NULL)
				{
					printf("\t\t%lf\n", *vectors[i]->x);
					printf("%c\t->\t%lf\n", i + A, *vectors[i]->y);
					printf("\t\t%lf\n\n", *vectors[i]->z);
				}
			}

			continue;
		}

		if (strcmp(buffer, "help\n") == 0)
		{
			printHelp();
			continue;
		}

		if (strcmp(buffer, "exit\n") == 0)
		{
			break;
		}

		printf("Invalid command provided!\n\n");
	}

	// Free vector store
	for (int i = 0; i < IdentifierCount; i++)
	{
		if (vectors[i] != NULL)
		{
			free(vectors[i]);
		}
	}

	printf("Bye!");
	scanf("");
	return 0;
}