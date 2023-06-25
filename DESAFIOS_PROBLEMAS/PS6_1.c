
#include <stdio.h>
#include <stdlib.h>

/*Escribir un programa que coloque 1 en las diagonales
  de una matriz nxn. El resto se debe de completar con 0*/

int main()
{
    int filas, columnas, i, j;

    printf("Ingresa el numero de filas: ");
    scanf("%i", &filas);
    printf("Ingresa el numero de columnas: ");
    scanf("%i", &columnas);

    int M[filas][columnas];
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j == i)
            {
                M[i][j] = 1;
            }
            M[i][j] = 0;
        }
    }
    // Imprimir
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("\t%i", M[i][j]);
        }
        printf("\n");
    }
}