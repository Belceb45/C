/**
 * @file main.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-02-24
 *
 *
 */
#include <stdio.h>
#include <graphics.h>

// Prototipos
void in_graph(int, int);
void posicionamiento(int, int);

int main()
{
	in_graph(-0, +0);
}

void posicionamiento(int x, int y)
{
	// CUBO_LINEAS
	setcolor(BLUE);
	setlinestyle(0, 0, 4);
	// Arriba
	line(500+x, 300+y, 700+x, 300+y);
	// Derecha
	line(700+x, 300+y, 700+x, 500+y);
	// Izquierda
	line(500+x, 300+y, 500+x, 500+y);
	// Abajo
	line(500+x, 500+y, 700+x, 500+y);
	// 2
	// Arriba
	line(400+x, 400+y, 600+x, 400+y);
	// Derecha
	line(600+x, 400+y, 600+x, 600+y);
	// Izquierda
	line(400+x, 400+y, 400+x, 600+y);
	// Abajo
	line(400+x, 600+y, 600+x, 600+y);
	// Uniones
	// Superior-izquierda
	line(400+x, 400+y, 500+x, 300+y);
	// Inferior-izquierda
	line(400+x, 600+y, 500+x, 500+y);
	// Superior-derecha
	line(600+x, 400+y, 700+x, 300+y);
	// Inferior-derecha
	line(600+x, 600+y, 700+x, 500+y);
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
	posicionamiento(x,y);
	getch();
	closegraph();
}
