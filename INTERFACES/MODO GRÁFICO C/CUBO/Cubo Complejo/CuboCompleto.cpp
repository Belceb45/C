/**
 * @file CuboCompleto.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-03-04
 *
 */

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
// Definiciones
#define SIZE_CUBO 5

// Estructuras
typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
    struct Nodo *arriba;
    struct Nodo *abajo;

} NODO;

typedef struct Section
{
    struct Nodo *nodos;
    struct Nodo *head;
    struct Nodo *tail;
} SECTION;

typedef struct Cubo
{
    struct Section *reb;
} CUBO;

// Prototipos de funciones
void menu();
void crear(CUBO *);
void insertar(CUBO *, int);
void mostrar(CUBO *);
void sumar(CUBO *, int);
void eliminar(CUBO *);
void buscar(CUBO *, int);
void modificar(CUBO *, int);
void msg(int);
//Graficos
void graficarCubo();
void aristasCentrales();
void contornoCubo();


// Funcion principal
int main()
{
    CUBO *cubo;
    crear(cubo);
    menu();
}

// Funciones

// Funcion para crear el cubo
void crear(CUBO *cubo)
{
    cubo->reb = (SECTION *)malloc(SIZE_CUBO * sizeof(SECTION));
    if (cubo->reb == NULL)
    {
        msg(0);
        exit(0);
    }
    cubo->reb->nodos = NULL;
    cubo->reb->head = NULL;
    cubo->reb->tail = NULL;
}

// Función de menú
void menu()
{
    initwindow(1920, 1080);
    settextstyle(0, 0, 4);
    char menu[50];
    setcolor(WHITE);
    strcpy(menu, "¿Que desea hacer?");
    outtextxy(850, 150, menu);
    strcpy(menu, "1.- Sumar Caras");
    outtextxy(910, 230, menu);
    strcpy(menu, "2.- Sumar Filas");
    outtextxy(910, 300, menu);
    strcpy(menu, "3.- Sumar Columnas");
    outtextxy(910, 370, menu);
    settextstyle(0, 0, 2);
    strcpy(menu, "Pulsa la tecla de la opcion deseada");
    outtextxy(850, 440, menu);
    //CUBO
    // rectangle(350,150,750,550);
	// line(150,800,350,550);
    aristasCentrales();
    contornoCubo();
    getch();
    closegraph();

}

// Función de mensajes
void msg(int i)
{
    char *msg[] = {"Error de memoria", "Error de dato", "Dato no encontrado", "Dato eliminado", "Dato modificado", "Dato insertado"};
    printf("\n%s", msg[i]);
}

// Funciones para el Modo Grafico

//Funcion para graficar el cubo
void dibujarCubo(){
	rectangle(350,150,750,550);
	line(150,800,350,550);
	aristasCentrales();
	contornoCubo();
	
	
}


void aristasCentrales()
{ // Caras
    setlinestyle(1, 0, 1);
    // CARA POSTERIOR
    setcolor(YELLOW);
    line(350, 250, 750, 250);
    line(350, 350, 750, 350);
    line(350, 450, 750, 450);
    line(450, 150, 450, 550);
    line(550, 150, 550, 550);
    line(650, 150, 650, 550);

    // CARA INFERIOR
    setcolor(GREEN);
    line(300, 612, 700, 612);
    line(250, 675, 650, 675);
    line(200, 737, 600, 737);
    line(250, 800, 450, 550);
    line(350, 800, 550, 550);
    line(450, 800, 650, 550);

    // CARA Izquierda
    setcolor(MAGENTA);
    line(150, 500, 350, 250);
    line(150, 600, 350, 350);
    line(150, 700, 350, 450);
    line(300, 212, 300, 612);
    line(250, 275, 250, 675);
    line(200, 337, 200, 737);

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    // CARA FRONTAL
    setcolor(DARKGRAY);
    line(150, 500, 550, 500);
    line(150, 600, 550, 600);
    line(150, 700, 550, 700);
    line(250, 400, 250, 800);
    line(350, 400, 350, 800);
    line(450, 400, 450, 800);

    // CARA SUPERIOR
    setcolor(BLUE);
    line(300, 212, 700, 212);
    line(250, 275, 650, 275);
    line(200, 337, 600, 337);
    line(250, 400, 450, 150);
    line(350, 400, 550, 150);
    line(450, 400, 650, 150);
    // CARA Derecha
    setcolor(RED);
    line(550, 500, 750, 250);
    line(550, 600, 750, 350);
    line(550, 700, 750, 450);
    line(700, 212, 700, 612);
    line(650, 275, 650, 675);
    line(600, 337, 600, 737);
}

//Dibujar el contorno del cubo
void contornoCubo()
{
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(WHITE);
    rectangle(350, 150, 750, 550);
    line(150, 800, 350, 550);

    rectangle(150, 400, 550, 800);

    line(150, 400, 350, 150);
    line(550, 400, 750, 150);
    line(550, 800, 750, 550);
}
