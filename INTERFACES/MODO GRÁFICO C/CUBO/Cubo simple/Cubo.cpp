/**
 * @file Cubo.c
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @class Estructuras de Datos
 * @version 1.0
 * @date 2023-02-23
 *
 *
 */

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

// Prototipos de funciones
// Funciones
int ***crear_matriz(int x, int y, int z);
void asignar_valores(int ***matriz, int x, int y, int z);
void imprimir_matriz(int ***matriz, int x, int y, int z);
void sumar_filas(int ***matriz, int x, int y, int z);
void sumar_columnas(int ***matriz, int x, int y, int z);
// Funciones de interfaz
void in_graph(int, int);
void posicionamiento(int, int);

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
        printf("\n1. Mostrar matriz \n2. Sumar filas \n3. Sumar columnas \n4. Mostrar CUBO \n5. Salir \n");
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
            in_graph(0, 0);
            break;
        case 5:
            printf("\nSaliendo ....");
            break;
        default:
            printf("\nERROR DE ELECCION");
            break;
        }
        printf("\n");
    } while (opcion != 5);
    return 0;
}

int ***crear_matriz(int x, int y, int z)
{
    int ***matriz;
    int i, j, k;
    matriz = (int ***)malloc(x * sizeof(int **));
    for (i = 0; i < x; i++)
    {
        *(matriz + i) = (int **)malloc(y * sizeof(int *));
        for (j = 0; j < y; j++)
        {
            *(*(matriz + i) + j) = (int *)malloc(z * sizeof(int));
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
                *(*(*(matriz + i) + j) + k) = 10 + rand() % 90;
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
                printf(" %d ", *(*(*(matriz + i) + j) + k));
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
                suma += *(*(*(matriz + i) + j) + k);
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
                suma += *(*(*(matriz + i) + j) + k);
            }
        }
        printf("La suma de la columna %d es: %d", i + 1, suma);
        printf("\n");
    }
}

void posicionamiento(int x, int y)
{
    // CUBO_LINEAS
    setcolor(BLUE);
    setlinestyle(0, 0, 4);
    // Arriba
    line(500 + x, 300 + y, 700 + x, 300 + y);
    // Derecha
    line(700 + x, 300 + y, 700 + x, 500 + y);
    // Izquierda
    line(500 + x, 300 + y, 500 + x, 500 + y);
    // Abajo
    line(500 + x, 500 + y, 700 + x, 500 + y);
    // 2
    // Arriba
    line(400 + x, 400 + y, 600 + x, 400 + y);
    // Derecha
    line(600 + x, 400 + y, 600 + x, 600 + y);
    // Izquierda
    line(400 + x, 400 + y, 400 + x, 600 + y);
    // Abajo
    line(400 + x, 600 + y, 600 + x, 600 + y);
    // Uniones
    // Superior-izquierda
    line(400 + x, 400 + y, 500 + x, 300 + y);
    // Inferior-izquierda
    line(400 + x, 600 + y, 500 + x, 500 + y);
    // Superior-derecha
    line(600 + x, 400 + y, 700 + x, 300 + y);
    // Inferior-derecha
    line(600 + x, 600 + y, 700 + x, 500 + y);
}

void in_graph(int x, int y)
{
    // Para graficar es necesario conocer las caracteristicas de nuestro monitor
    int gd = DETECT;
    int gm;
    // Con initgraph inicializamos los graficos.
    // El primer parametro de tipo entero determina el tipo de monitor, con DETECT se reconoce
    // El segundo paramtero es el modo de operacion grafico del monitor, por ejemplo, vga, super vga, etc.
    // El ultimo parametro es la ubicacion de los controladores

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    // Crear ventana
    initwindow(1250, 800, "ESTRUCTURAS DE DATOS", 0, 0, false, true);
    setbkcolor(15);
    cleardevice();
    //
    setcolor(BLUE);
    settextstyle(4, 0, 10);
    outtextxy(350, 10, "CUBO");

    setcolor(BLACK);
    settextstyle(1, 0, 3);
    outtextxy(40, 750, "Rubio Haro Diego");
    // settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    readimagefile("logo_2.jpg", 40, 40, 220, 220);
    readimagefile("Logo-IPN.jpg", 994, 40, 800, 200);
    posicionamiento(x, y);
    delay(10000);
    closegraph();
}
