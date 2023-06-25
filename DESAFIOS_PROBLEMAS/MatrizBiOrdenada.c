#include <stdio.h>
#include <stdlib.h>

// Prototipos
void llenado(int **p, int filas, int columnas);
void ordenado(int **p, int filas, int columnas);
int main()
{
    int filas, i, j, columnas;
    printf("Ingresa el numero de filas: ");
    scanf("%i", &filas);
    printf("Ingresa el numero de columnas: ");
    scanf("%i", &columnas);
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (i = 0; i < columnas; i++)
    {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }
    printf("\n------------------------------------------------\nMatriz\n\n");
    llenado(matriz, filas, columnas);
    printf("------------------------------------------------\n");
    ordenado(matriz, filas, columnas);
    // Matriz ordenada
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("\t%i", matriz[i][j]);
        }
        printf("\n");
    }
}

void llenado(int **p, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            p[i][j] = 1 + rand() % 20;
            printf("\t%i", p[i][j]);
        }
        printf("\n");
    }
}

void ordenado(int **p, int filas, int columnas)
{
    int i, j, x, y;
    int mayor = 0;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            for (x = 0; x < filas; x++)
            {
                for (y = 0; y < columnas; y++)
                {
                    if (p[i][j] > p[x][y])
                    {
                        mayor = p[i][j];
                        p[i][j] = p[x][y];
                        p[x][y] = mayor;
                    }
                }
            }
        }
    }
    
}
