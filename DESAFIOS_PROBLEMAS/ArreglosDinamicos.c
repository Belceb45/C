#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Uso de memoria dinamica

// Prototipos
void llenado(int **p, int filas, int columnas);
void longitud_filas(int **p, int filas, int columnas);
void longitud_columnas(int **p, int filas, int columnas);
void longitud_ambas(int **p, int filas, int columnas);
void imprimir(int **p, int filas, int columnas);
int main()
{
    int filas, columnas;

    printf("Ingresa el numero de filas: ");
    scanf("%i", &filas);
    printf("Ingresa el numero de columnas: ");
    scanf("%i", &columnas);

    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    llenado(matriz, filas, columnas);
    char condicional[5];
    printf("%cDeseas cambiar el tama%co?\nR: ", 168, 164);
    scanf("%s", &condicional);
    if (strcmp(condicional, "si") == 0)
    {
        char condicional2[20];
        printf("%cQue deseas cambiar?: ", 168);
        gets(condicional2);
        gets(condicional2);

        if (strcmp(condicional2, "filas") == 0)
        {
            longitud_filas(matriz, filas, columnas);
        }
        else if (strcmp(condicional2, "columnas") == 0)
        {
            longitud_columnas(matriz, filas, columnas);
        }
        else if (strcmp(condicional2, "filas y columnas") == 0 || strcmp(condicional2, "ambas") == 0)
        {
            longitud_ambas(matriz, filas, columnas);
        }
        else
        {
            printf("\nElige una opcion valida");
        }
    }

    // longitud(matriz, filas, columnas, condicional);
    printf("\nCantidad de memoria: %i", (5 * sizeof(int)));

    return 0;
}

void llenado(int **p, int filas, int columnas)
{
    printf("\nFilas: %i", filas);
    printf("\nColumnas: %i\n\n", columnas);

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

void longitud_filas(int **p, int filas, int columnas)
{
    int n, i, j;
    printf("\nIngresa la nueva cantidad filas: ");
    scanf("%i", &n);
    // int **temp;

    p = (int **)realloc(p, n * sizeof(int *));

    for (int i = filas; i < n; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; j++)
            p[i][j] = 1 + rand() % 20;
    }

    imprimir(p, n, columnas);
}

void longitud_columnas(int **p, int filas, int columnas)
{
    int n, i, j;
    printf("\nIngresa la nueva cantidad columnas: ");
    scanf("%i", &n);
    // int **temp;
    for (int i = 0; i < filas; i++)
    {
        p[i] = (int *)realloc(p[i], sizeof(int) * n);
        for (int j = columnas; j < n; j++)
            p[i][j] = 1 + rand() % 20;
    }

    imprimir(p, filas, n);
}

void longitud_ambas(int **p, int filas, int columnas)
{
    int nf, nc, i, j;
    printf("\nIngresa la nueva cantidad filas: ");
    scanf("%i", &nf);
    printf("\nIngresa la nueva cantidad columnas: ");
    scanf("%i", &nc);
    // int **temp;

    

    if (nf > filas && nc > columnas)
    {
        printf("\nSON MAYORES AMBOS\n");
        p = (int **)realloc(p, nf * sizeof(int *));
        for (int i = filas; i < nf; i++)
        {
            p[i] = (int *)realloc(p[i], sizeof(int) * nc);
            for (int j = columnas; j < nc; j++)
                p[i][j] = 1 + rand() % 20;
        }
    }
    else if (nf > filas && nc <= columnas)
    {
        for (int i = filas; i < nf; i++)
        {
            p[i] = (int *)realloc(p[i], sizeof(int) * nc);
            for (int j = 0; j < nc; j++)
                p[i][j] = 1 + rand() % 20;
        }
    }
    else if (nf < filas && nc > columnas)
    {
        for (int i = 0; i < nf; i++)
        {
            p[i] = (int *)realloc(p[i], sizeof(int) * nc);
            for (int j = columnas; j < nc; j++)
                p[i][j] = 1 + rand() % 20;
        }
    }
    else if (nf < filas && nc < columnas)
    {
        for (int i = 0; i < nf; i++)
        {
            p[i] = (int *)realloc(p[i], sizeof(int) * nc);
        }
    }
    imprimir(p, nf, nc);
}

void imprimir(int **p, int filas, int columnas)
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("\t%i", p[i][j]);
        }
        printf("\n");
    }
}