/**
 * @file Reinas.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief 
 * @version 0.1
 * @date 2023-03-26
 * 
 * 
 */
//Librerias
#include <stdio.h>
#include <graphics.h>

// Macros
#define N 8 // Tamaño del tablero de ajedrez

// Estructuras

// Prototipos
void graf_tablero();
void Reina(int, int);
bool es_seguro(int tablero[N][N], int fila, int columna);
bool resolver_reinas(int tablero[N][N], int columna);

// Función principal
int main()
{
    initwindow(1080, 720, "N REINAS");
    setviewport(0, 0, 1080, 700, 1);
    setbkcolor(RGB(255, 255, 255));
    cleardevice();
    graf_tablero();

    int tablero[N][N] = {0};
    if (resolver_reinas(tablero, 0))
    {
        printf("Las reinas han sido ubicadas correctamente en el tablero.\n");
    }
    else
    {
        printf("No se pudo ubicar las reinas en el tablero.\n");
    }

    getch();
    closegraph();
}

// Función del tablero
void graf_tablero()
{
    int x = 300;   // coordenada x de la esquina superior izquierda del cuadrado
    int y = 150;   // coordenada y de la esquina superior izquierda del cuadrado
    int size = 50; // tamaño de los cuadrados
    setcolor(BLUE);
    settextstyle(4, 0, 4);
    outtextxy(300, 90, "Reinas que no comen");
    setcolor(RED);
    settextstyle(4, 0, 2);
    outtextxy(50, 650, "Rubio Haro Diego  2CM3");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j) % 2 == 0)
            {
                setfillstyle(SOLID_FILL, WHITE);
            }
            else
            {
                setfillstyle(SOLID_FILL, BLACK);
            }
            bar(x + j * size, y + i * size, x + (j + 1) * size, y + (i + 1) * size);
        }
    }
    // Dibujar contorno negro alrededor del tablero
    setcolor(BLACK);
    rectangle(x, y, x + size * N, y + size * N);
}

// Función que dibuja una reina
void Reina(int x, int y)
{
    // Dibuja el cuerpo de la reina
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    line(x + 5, y + 45, x + 45, y + 45);
    line(x + 45, y + 45, x + 45, y + 30);
    line(x + 45, y + 30, x + 40, y + 20);
    line(x + 40, y + 20, x + 35, y + 30);
    line(x + 35, y + 30, x + 25, y + 5);
    line(x + 25, y + 5, x + 15, y + 30);
    line(x + 15, y + 30, x + 10, y + 20);
    line(x + 10, y + 20, x + 5, y + 30);
    line(x + 5, y + 30, x + 5, y + 45);
    floodfill(x + 30, y + 25, RED);

    // Dibuja la corona de la reina
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    line(x + 5, y + 20, x + 15, y + 5);
    line(x + 15, y + 5, x + 25, y + 5);
    line(x + 25, y + 5, x + 35, y + 20);
    line(x + 35, y + 20, x + 5, y + 20);
    floodfill(x + 20, y + 13, YELLOW);
}

//
bool es_seguro(int tablero[N][N], int fila, int columna)
{
    int i, j;

    // Verifica si hay otra reina en la misma fila
    for (i = 0; i < columna; i++)
    {
        if (tablero[fila][i])
        {
            return false;
        }
    }

    // Verifica si hay otra reina en la diagonal principal superior
    for (i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
    {
        if (tablero[i][j])
        {
            return false;
        }
    }

    // Verifica si hay otra reina en la diagonal secundaria inferior
    for (i = fila, j = columna; j >= 0 && i < N; i++, j--)
    {
        if (tablero[i][j])
        {
            return false;
        }
    }

    return true;
}

// Función recursiva para resolver el problema de las N reinas
bool resolver_reinas(int tablero[N][N], int columna)
{
    // Caso base: todas las reinas han sido ubicadas
    if (columna >= N)
    {
        return true;
    }
    // Para cada fila en la columna actual
    for (int i = 0; i < N; i++)
    {
        // Verifica si la posición actual es segura para colocar una reina
        if (es_seguro(tablero, i, columna))
        {
            // Coloca una reina en la posición actual
            tablero[i][columna] = 1;

            // Dibuja la reina en el tablero
            Reina(columna * 50 + 300, i * 50 + 152);
            delay(300); // Agrega un retardo para poder apreciar mejor cada cambio

            // Llamada recursiva para ubicar las reinas en las columnas restantes
            if (resolver_reinas(tablero, columna + 1))
            {
                return true;
            }

            // Si no se puede ubicar una reina en la siguiente columna, retrocede y prueba otra fila en la columna actual
            tablero[i][columna] = 0;
            cleardevice(); // Borra el tablero actual para actualizarlo con la nueva posición de las reinas
            graf_tablero();     // Dibuja el tablero actualizado sin la reina en la posición anterior
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (tablero[j][k] == 1)
                    {
                        Reina(k * 50 + 300, j * 50 + 152); 
                    }
                }
            }
            delay(300); // Agrega un retardo para poder apreciar mejor cada cambio
        }
    }

    // Si no se puede ubicar una reina en ninguna fila de la columna actual, retrocede y prueba otra fila en la columna anterior
    return false;
}
