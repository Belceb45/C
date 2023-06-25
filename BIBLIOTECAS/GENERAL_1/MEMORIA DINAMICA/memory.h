#ifndef _memory
#define _memory

// Función Crear matriz N (Enteros)
int *matz_I(int);
// Función Crear matriz N (Decimales)
float *matz_F(int);
// Función Crear matriz N (Doubles)
double *matz_D(int);
// Función Crear matriz N Caracteres (String)
char *matz_C(int);
// Función Crear Matriz NXM (Enteros)
int **matzz_I(int, int);
// Función Crear Matriz NXM (Decimales)
float **matzz_F(int, int);
// Función Crear Matriz NXM (Doubles)
double **matzz_D(int, int);

#include "memory.c"
#endif