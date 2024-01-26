#ifndef ANGEM_H
#define ANGEM_H
typedef struct _Vector {
	//double a[0];
	double x;
	double y;
	double z;
} Vector;

typedef struct _Matrix {
	size_t m;
	size_t n;
	double a[];
} Matrix;

typedef struct _Vector Plane; //we store planes as normal-vectors, starting at O, with modules of coordinates increased by 1 each

Matrix* minor_matrix(Matrix* b, size_t md, size_t nd);
double determinant(Matrix* b);
double vector_module(Vector* b);
double scalar_multiply(Vector* a, Vector* b);





#endif
