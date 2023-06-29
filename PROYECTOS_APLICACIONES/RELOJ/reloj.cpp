/**
 * @file crono.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-26
 *
 * Reloj implementado en C (Grafico)
 * / Está programado en C pero se usa la versión de un compilador
 *   de 32 bits de c++/
 */

// Librerias
#include <stdio.h>
#include <windows.h>
#include <graphics.h>
#include <time.h>
// Estructuras

// Prototipos
void menu();

// Función principal
int main(int argc, char *argv[])
{

    menu();
}

void menu()
{
    time_t time;
    struct tm *TimeClock;
    initwindow(1720, 1080, "RELOJ");
    setbkcolor(BLACK);
    cleardevice();

    setcolor(BLUE);
    settextstyle(4, 0, 4);
    outtextxy(300, 90, "");

    getch();
}