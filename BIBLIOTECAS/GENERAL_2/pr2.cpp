//Rubio Haro Diego 2CM3

#include<stdio.h>
#include<graphics.h>

int main()
{
	//Para graficar es necesario conocer las caracteristicas de nuestro monitor
	int gd=DETECT;
	int gm;
	//Con initgraph inicializamos los graficos.
	//El primer parametro de tipo entero determina el tipo de monitor, con DETECT se reconoce
	//El segundo paramtero es el modo de operación gráfico del monitor, por ejemplo, vga, super vga, etc.
	//El último parametro es la ubicación de los controladores
	initgraph(&gd,&gm, "C:\\TC\\BGI");
	
	//Funciones de posicionamiento
	//Para pintar cualquier objeto en pantalla se requieren las coordenadas en donde se ubiacará.
	//Ejemplo 
	outtextxy(250,250,"Estructuras de Datos");
	
		
	getch();
	closegraph();
}