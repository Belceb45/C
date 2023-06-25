#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **m;
    int a = 3;
    int b = 5;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    //Tamaño 2x5
    //Crear matriz dinamica
    m = (int **)malloc(*p1 * sizeof(int *));
    for (int i = 0; i < *p1; i++)
    {
        m[i] = (int *)malloc(*p2 * sizeof(int));
    }
    //Asignar valores
    for (int filas = 0; filas < *p1; filas++)
    {
        for (int columnas = 0; columnas < *p2; columnas++)
        {
            *(*(m + filas) + columnas) = 1 + rand() % 100;
            printf("\nDat[%d][%d]: %d",filas,columnas,*(*(m + filas) + columnas));
        }
    }

    int x= *(*(m+2)+4)+*(*(m+0)+2);
    printf("\n\nSuma: %d",x);

    int **aux=m;
    //Direcciones de memoria
    printf("\n\nDireccion de M: %p",m);
    printf("\nDireccion de AUX: %p",aux);
    printf("\nDireccion de AUX: %p",&aux);
    printf("\nDireccion de M: %p",&m);

    printf("\n\nValor[0][1]: %d usando la referencia de 'm' que es 'aux'",*(*(aux+0)+1));

    //Nuevo puntero que será la dirección continua de los anteriores
    int **n1;
    printf("\n\nDireccion de memoria de n1: %p",n1);
    n1=(++m);
    //Ahora la dirección de memoria a la que apunta n1 será una después de la de m
    printf("\n\nDireccion de memoria de n1: %p",n1);

    

}