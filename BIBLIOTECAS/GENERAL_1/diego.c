#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diego.h"

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class MEMORY
 **/

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
    char *m = (char *)malloc(n + 1 * sizeof(char));
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

// Función Crear Matriz N (Enteros) aleatorios
int *matz_Irand(int n)
{
    srand(time(NULL));
    int *m = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        m[i] = 1 + rand() % 100;
    }
    return m;
}

// Función Crear Matriz N (Decimales) aleatorios
float *matz_Frand(int n)
{
    srand(time(NULL));
    float *m = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        m[i] = 1 + rand() % 100;
    }
    return m;
}

// Función Crear Matriz N (Doubles) aleatorios
double *matz_Drand(int n)
{
    srand(time(NULL));
    double *m = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        m[i] = 1 + rand() % 100;
    }
    return m;
}

// Función Crear Matriz NXM (Enteros) aleatorios
int **matzz_Irand(int filas, int columnas)
{
    srand(time(NULL));
    int **m = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (int *)malloc(columnas * sizeof(int));
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            m[i][j] = 1 + rand() % 100;
        }
    }

    return m;
}

// Función Crear Matriz NXM (Decimales) aleatorios
float **matzz_Frand(int filas, int columnas)
{
    srand(time(NULL));
    float **m = (float **)malloc(filas * sizeof(float *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (float *)malloc(columnas * sizeof(float));
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            m[i][j] = 1 + rand() % 100;
        }
    }
    return m;
}

// Función Crear Matriz NXM (Decimales) aleatorios
double **matzz_Drand(int filas, int columnas)
{
    double **m = (double **)malloc(filas * sizeof(double *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (double *)malloc(columnas * sizeof(double));
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            m[i][j] = 1 + rand() % 100;
        }
    }
    return m;
}


/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class MATH
 **/

// Función MCD
int mcd(int a, int b)
{
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

// Función MCM
int mcm(int a, int b)
{
    return (a * b) / mcm(a, b);
}

// Función Factorial
int factorial(int a)
{
    if (a > 0 || a <= 10)
        return a * factorial(a - 1);
}

// Función fibonacci
int fibonacci(int n)
{
    int x = 0, y = 1, z;
    for (int i = 0; i < n; i++)
    {
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}

// Función multiplicacion de matrices
int **mult_mtz(int **A, int **B, int filasA, int columnasA, int filasB, int columnasB)
{
    int **m = (int **)malloc(filasA * sizeof(int *));
    int i, j, k;
    for (i = 0; i < filasA; i++)
    {
        m[i] = (int *)malloc(columnasB * sizeof(int));
    }
    // Multiplicación de las matrices
    for (i = 0; i < filasA; i++)
    {
        for (j = 0; j < columnasB; j++)
        {
            *(*(m + i) + j) = 0; // m[i][j] = 0;
            for (k = 0; k < columnasA; k++)
            {
                *(*(m + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j)); // matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    return m;
}

// Función suma de matrices
int **sum_mtz(int **A, int **B, int filas, int columnas)
{
    int **m = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (int *)malloc(columnas * sizeof(int));
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(m + i) + j) = (*(*(A + i) + j)) + (*(*(B + i) + j));
        }
    }
    return m;
}

// Función resta de matrices
int **rest_mtz(int **A, int **B, int filas, int columnas)
{
    int **m = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        m[i] = (int *)malloc(columnas * sizeof(int));
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(m + i) + j) = (*(*(A + i) + j)) - (*(*(B + i) + j));
        }
    }
    return m;
}

// Función determinante de una Matriz
double det_mtz(double **A, int d)
{
    double aux;
    double determinante = 1;
    for (int k = 0; k < d - 1; k++)
    { // recorrer la diagonal
        determinante *= A[k][k];
        if (A[k][k] == 0)
            return 0;
        else
        {

            for (int i = k + 1; i < d; i++)
            { // recorrer fila
                aux = -A[i][k];
                for (int j = k; j < d; j++)
                {
                    A[i][j] = A[i][j] + aux * A[k][j] / A[k][k];
                }
            }
        }
    }
    determinante *= A[d - 1][d - 1];
    return determinante;
}
