#include <stdio.h>
#include <stdlib.h>

/*Al recibir dos arreglos bidimensionales de mxn
  elmentos cada uno, calcule la suma de ambos arreglos
  y almacene el resultado en otro arreglo bidimensional */

void llenado(int filas, int columnas);
void suma(int **m1, int **m2, int filas, int columnas);

int main()
{
    int filas, columnas;
    printf("-------------------------------------------\n");
    printf("Ingresa el tama%co de filas: ",164);
    scanf("%i", &filas);
    printf("Ingresa el tama%co de columnas: ",164);
    scanf("%i", &columnas);
    printf("-------------------------------------------\n");
    llenado(filas, columnas);
    return 0;
}

void llenado(int filas, int columnas)
{
    printf("Matriz 1\n\n");
    // int matriz_1[filas][columnas], matriz_2[filas][columnas]
    int i, j;
    int **matriz_1 = (int **)malloc(filas * sizeof(int));
    for (int i = 0; i < columnas; i++)
        matriz_1[i] = (int *)malloc(columnas * sizeof(int));

    // Asignacion de valores para la matriz_1
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz_1[i][j] = 1 + rand() % 20;
            printf("\t%i", matriz_1[i][j]);
        }
        printf("\n");
    }
    // Asignacion de valores para la matriz_2
    printf("-------------------------------------------\n");
    printf("Matriz 2\n\n");
    int **matriz_2 = (int **)malloc(filas * sizeof(int));
    for (int i = 0; i < columnas; i++)
        matriz_2[i] = (int *)malloc(columnas * sizeof(int));
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz_2[i][j] = 1 + rand() % 20;
            printf("\t%i", matriz_2[i][j]);
        }
        printf("\n");
    }
    suma(matriz_1, matriz_2, filas, columnas);
}

void suma(int **m1, int **m2, int filas, int columnas)
{
    // int matriz_3[filas][columnas];
    int **matriz_3 = (int **)malloc(filas * sizeof(int));
    for (int i = 0; i < columnas; i++)
        matriz_3[i] = (int *)malloc(columnas * sizeof(int));
    // int t=sizeof(m1)/sizeof(int);
    // printf("t=%i'n",t);
    printf("\nValor de las filas: %i", filas);
    printf("\nValor de las columnas: %i\n", columnas);

    printf("\n---------------------------------------------\nMatriz  3\n\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = m1[i][j] + m2[i][j];
            printf("\t%i", matriz_3[i][j]);
        }
        printf("\n");
    }
}