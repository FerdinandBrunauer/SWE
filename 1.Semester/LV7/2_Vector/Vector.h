#include <stdlib.h>
#include <stdarg.h>

typedef struct Vector
{
	double *x;
	double *y;
	double *z;
} Vector;

/* CREATION / DELETION */
struct Vector* newVector(double x, double y, double z);
void delVector(struct Vector* vector);

/* CALCULATION */
struct Vector* addVectors(int num, ...);
struct Vector* subVectors(int num, ...);
double scalarProduct(struct Vector *vector1, struct Vector *vector2);
struct Vector* crossProduct(struct Vector *vector1, struct Vector *vector2);
double spatProduct(struct Vector *vector1, struct Vector *vector2, struct Vector *vector3);
struct Vector* multWithSkalar(struct Vector *vector, double skalar);