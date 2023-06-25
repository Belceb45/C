// Programa que sume filas y columnas de un cubo de 5x5x5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de funciones
int ***crear_matriz(int x, int y, int z);
void asignar_valores(int ***matriz, int x, int y, int z);
void imprimir_matriz(int ***matriz, int x, int y, int z);
void sumar_filas(int ***matriz, int x, int y, int z);
void sumar_columnas(int ***matriz, int x, int y, int z);

int main()
{
    // srand(time(NULL));
    int x = 5, y = 5, z = 5;
    int ***matriz = crear_matriz(x, y, z);
    asignar_valores(matriz, x, y, z);
    int i, j, k;
    int opcion;
    int suma;
    do
    {
        printf("\n");
        printf("\n1. Leer matriz \n2. Sumar filas \n3. Sumar columnas \n4. Salir \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            imprimir_matriz(matriz, x, y, z);
            break;
        case 2:
            sumar_filas(matriz, x, y, z);
            break;
        case 3:
            sumar_columnas(matriz, x, y, z);
            break;
        case 4:
            printf("\nSaliendo del programa...");
            break;
        default:
            printf("\nOpcion incorrecta");
            break;
        }
        printf("\n");
    } while (opcion != 4);
    return 0;
}

int ***crear_matriz(int x, int y, int z)
{
    int ***matriz;
    int i, j, k;
    matriz = (int ***)malloc(x * sizeof(int **));
    for (i = 0; i < x; i++)
    {
        matriz[i] = (int **)malloc(y * sizeof(int *));
        for (j = 0; j < y; j++)
        {
            matriz[i][j] = (int *)malloc(z * sizeof(int));
        }
    }
    return matriz;
}

void asignar_valores(int ***matriz, int x, int y, int z)
{
    int i, j, k;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                matriz[i][j][k] = 10 + rand() % 90;
            }
        }
    }
}

void imprimir_matriz(int ***matriz, int x, int y, int z)
{
    int i, j, k;
    printf("\n\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                printf(" %d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void sumar_filas(int ***matriz, int x, int y, int z)
{
    system("cls");
    int i, j, k;
    int suma;
    for (i = 0; i < x; i++)
    {
        suma = 0;
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                suma += matriz[i][j][k];
            }
        }
        printf("La suma de la fila %d es: %d", i + 1, suma);
        printf("\n");
    }
}

void sumar_columnas(int ***matriz, int x, int y, int z)
{
    system("cls");
    int i, j, k;
    int suma;
    for (i = 0; i < x; i++)
    {
        suma = 0;
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                suma += matriz[i][j][k];
            }
        }
        printf("La suma de la columna %d es: %d", i + 1, suma);
        printf("\n");
    }
}
