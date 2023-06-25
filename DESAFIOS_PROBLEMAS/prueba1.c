#include <stdio.h>
#include <stdlib.h>

void llenado(int p[], int n);
void mostrarMatriz(int p[], int n);
int comparar_matriz(const void *r, const void *q);

int main(void)
{
    // Puntero a función
    int (*p1)(const void *, const void *) = comparar_matriz;
    p1 = &comparar_matriz;
    //
    int n, i, tA;

    printf("Ingresa el tama%co del arreglo: ", 164);
    scanf("%i", &n);
    int matriz[n];
    llenado(matriz, n);
    mostrarMatriz(matriz, n);
    tA = sizeof(matriz) / sizeof(int);
    printf("tA: %i\n\n", tA);
    qsort(matriz, tA, sizeof(int), p1);
    printf("\n------------------------------------------------------------------------");
    printf("\n\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\t%i", matriz[i]);
    }
    return 0;
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
        printf("\t%i", p[i]);
    }
}

int comparar_matriz(const void *p, const void *q)
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
