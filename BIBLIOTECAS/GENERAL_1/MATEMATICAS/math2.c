// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "math2.h"

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