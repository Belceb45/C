#include <stdio.h>
#include <stdlib.h>

/*Hacer un programa que muestre la diagonal de la
  matriz (Haciendo uso de funciones) */

void diagonal(int p[][0], int n);
void llenado(int p[][0], int n);

int main()
{
    int n;
    printf("Ingresa las filas (nxn): ");
    scanf("%i", &n);
    int matriz[n][n];
    llenado(matriz, n);
    diagonal(matriz, n);
    return 0;
}

void llenado(int p[][0], int n)
{
    printf("\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            p[i][j] = 1 + rand() % 20;
            printf("\t%i", p[i][j]);
        }
        printf("\n");
    }
}

void diagonal(int p[][0], int n)
{
    printf("\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("\tDiagonal %i %i=%i",i,j,p[i][j]);
            }
            printf("\n");
        }
    }
}