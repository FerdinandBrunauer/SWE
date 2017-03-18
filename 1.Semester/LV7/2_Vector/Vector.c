#include "Vector.h"

Vector* newVector(double x, double y, double z)
{
	struct Vector* result = malloc(sizeof(struct Vector));

	if (result == NULL)
	{
		return NULL;
	}

	result->x = malloc(sizeof(double));
	result->y = malloc(sizeof(double));
	result->z = malloc(sizeof(double));
	if (result->x == NULL || result->y == NULL)
	{
		return NULL;
	}

	*result->x = x;
	*result->y = y;
	*result->z = z;

	return result;
}

void delVector(Vector *vector)
{
	free(vector->x);
	free(vector->y);
	free(vector->z);
	free(vector);
}

Vector* addVectors(int num, ...)
{
	double x = 0, y = 0, z = 0;
	va_list arguments;
	va_start(arguments, num);
	for (int i = 0; i < num; i++)
	{
		struct Vector *currentVector = va_arg(arguments, struct Vector*);
		x += *currentVector->x;
		y += *currentVector->y;
		z += *currentVector->z;
	}
	va_end(arguments);

	return newVector(x, y, z);
}

Vector* subVectors(int num, ...)
{
	va_list arguments;
	va_start(arguments, num);
	struct Vector *startVector = va_arg(arguments, struct Vector*);
	double x = *startVector->x, y = *startVector->y, z = *startVector->z;

	for (int i = 0; i < num - 1; i++)
	{
		struct Vector *currentVector = va_arg(arguments, struct Vector*);
		x -= *currentVector->x;
		y -= *currentVector->y;
		z -= *currentVector->z;
	}
	va_end(arguments);

	return newVector(x, y, z);
}

double scalarProduct(Vector *vector1, Vector *vector2)
{
	return *vector1->x * *vector2->x + *vector1->y * *vector2->y + *vector1->z * *vector2->z;
}

Vector* crossProduct(Vector *vector1, Vector *vector2)
{
	struct Vector* result = newVector(
		(*vector1->y * *vector2->z) - (*vector1->z * *vector2->y),
		(*vector1->z * *vector2->x) - (*vector1->x * *vector2->z),
		(*vector1->x * *vector2->y) - (*vector1->y * *vector2->x)
	);

	return result;
}

double spatProduct(Vector *vector1, Vector *vector2, Vector *vector3)
{
	double value = (*vector1->x**vector2->y**vector3->z)
		+ (*vector1->y**vector2->z**vector3->x)
		+ (*vector1->z**vector2->x**vector3->y)
		- (*vector1->z**vector2->y**vector3->x)
		- (*vector1->y**vector2->x**vector3->z)
		- (*vector1->x**vector2->z**vector3->y);
	return value < 0 ? value * -1 : value; // Abs
}

Vector* multWithSkalar(Vector *vector, double skalar)
{
	struct Vector *result = newVector(
		*vector->x * skalar,
		*vector->y * skalar,
		*vector->z * skalar
	);

	return result;
}
