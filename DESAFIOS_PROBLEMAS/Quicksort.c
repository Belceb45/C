#include <stdio.h>
#include <stdlib.h>

void llenado(int p[], int n);
void mostrarMatriz(int p[], int n);
int descendente(const void *r, const void *q);
int ascendente(const void *r, const void *q);

int main(void)
{
    // Puntero a función
    // int (*p1)(const void *, const void *) = ascendente;
    // int (*p2)(const void *, const void *) = descendente;
    // p1 = &ascendente;
    // p1 = &descendente;
    //Variables
    int n, i, tA;
    //INgreso del tamaño
    printf("Ingresa el tama%co del arreglo: ", 164);
    scanf("%i", &n);
    //Matriz
    int matriz[n];
    //Guardamos el tamaño de la matriz
    tA = sizeof(matriz) / sizeof(int);
    printf("tA: %i\n\n", tA);
    //Llenamos y mostramos
    llenado(matriz, n);
    printf("\n\6----------------------------------------------------\6");
    printf("\nArreglo sin ordenar\n\n");
    mostrarMatriz(matriz, n);
    //Quicksort
    // qsort recibe como parametro a la matriz, el tamaño, el tipo de dato, y el puntero de la funcion
    //Ascendente
    qsort(matriz, tA, sizeof(int), &ascendente);
    //Mostrar ya ordenado
    printf("\n\6----------------------------------------------------\6");
    printf("\nArreglo Ascendente\n\n");
    mostrarMatriz(matriz, n);
    printf("\n\6----------------------------------------------------\6");
    //Descendente
    qsort(matriz, tA, sizeof(int), &descendente);
    printf("\nArreglo Descendente\n\n");
    mostrarMatriz(matriz, n);
    printf("\n\6----------------------------------------------------\6");
}

void llenado(int p[], int n)
{

    for (int i = 0; i < n; i++)
    {

        p[i] = rand() % 15 - 4;
    }
}
void mostrarMatriz(int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4i", p[i]);
    }
}

int ascendente(const void *p, const void *q)
{
    int x, y;
    x = *(int *)p;
    y = *(int *)q;
    if (x < y)
    {
        return -1;
    }
    if (x == y)
    {
        return 0;
    }
    return 1;
}
int descendente(const void *p, const void *q)
{
    int x, y;
    x = *(int *)p;
    y = *(int *)q;
    if (x > y)
    {
        return -1;
    }
    if (x == y)
    {
        return 0;
    }
    return 1;
}
