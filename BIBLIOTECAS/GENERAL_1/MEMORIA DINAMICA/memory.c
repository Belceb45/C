#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

// Función Crear matriz N (Enteros)
int *matz_I(int n)
{
    int *m = (int *)malloc(n * sizeof(int));
    return m;
}

// Función Crear matriz N (Decimales)
float *matz_F(int n)
{
    float *m = (float *)malloc(n * sizeof(float));
    return m;
}

// Función Crear matriz N (Doubles)
double *matz_D(int n)
{
    double *m = (double *)malloc(n * sizeof(double));
    return m;
}

// Función Crear matriz N Caracteres (String)
char *matz_C(int n)
{
    char *m = (char *)malloc(n * sizeof(char));
    return m;
}

// Función Crear Matriz NXM (Enteros)
int **matzz_I(int filas, int columnas)
{
    int **m = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (int *)malloc(columnas * sizeof(int));
    }
    return m;
}

// Función Crear Matriz NXM (Decimales)
float **matzz_F(int filas, int columnas)
{
    float **m = (float **)malloc(filas * sizeof(float *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (float *)malloc(columnas * sizeof(float));
    }
    return m;
}

// Función Crear Matriz NXM (Doubles)
double **matzz_D(int filas, int columnas)
{
    double **m = (double **)malloc(filas * sizeof(double *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (double *)malloc(columnas * sizeof(double));
    }

    return m;
}