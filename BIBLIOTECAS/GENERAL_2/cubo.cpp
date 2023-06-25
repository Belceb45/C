// Mostrar un cubo en 2D de forma grafica
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>

// Definicion de constantes
#define PI 3.1415926535897932384626433832795
#define ANCHO 640
#define ALTO 480
#define X0 320
#define Y0 240
#define ESCALA 100

// Definicion de estructuras
struct punto
{
    float x;
    float y;
    float z;
};

// Definicion de funciones
void dibujar_punto(int x, int y, int color);
void dibujar_linea(int x1, int y1, int x2, int y2, int color);
void dibujar_cubo(struct punto p1, struct punto p2, struct punto p3, struct punto p4, struct punto p5, struct punto p6, struct punto p7, struct punto p8, int color);
void rotar_punto(struct punto *p, float angulo, int eje);
void rotar_cubo(struct punto *p1, struct punto *p2, struct punto *p3, struct punto *p4, struct punto *p5, struct punto *p6, struct punto *p7, struct punto *p8, float angulo, int eje);
void proyectar_punto(struct punto *p);
void proyectar_cubo(struct punto *p1, struct punto *p2, struct punto *p3, struct punto *p4, struct punto *p5, struct punto *p6, struct punto *p7, struct punto *p8);


// Funcion principal
int main()
{
    // Declaracion de variables
    int gdriver = DETECT, gmode, errorcode;
    struct punto p1, p2, p3, p4, p5, p6, p7, p8;
    float angulo;
    int eje;

    // Inicializacion de variables
    angulo = 0;
    eje = 1;

    // Inicializacion de la libreria grafica
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
        printf("\nError grafico: %s", grapherrormsg(errorcode));
        printf("\nPulsa una tecla para salir...");
        getch();
        exit(1);
    }

    // Inicializacion de los puntos
    p1.x = -1;
    p1.y = -1;
    p1.z = -1;
    p2.x = 1;
    p2.y = -1;
    p2.z = -1;
    p3.x = 1;
    p3.y = 1;
    p3.z = -1;
    p4.x = -1;
    p4.y = 1;
    p4.z = -1;
    p5.x = -1;                                                  
    p5.y = -1;
    p5.z = 1;
    p6.x = 1;
    p6.y = -1;
    p6.z = 1;
    p7.x = 1;
    p7.y = 1;
    p7.z = 1;
    p8.x = -1;
    p8.y = 1;
    p8.z = 1;

    // Bucle principal
    while (!kbhit())
    {
        // Rotar el cubo
        rotar_cubo(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, angulo, eje);
        // Proyectar el cubo
        proyectar_cubo(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8);
        // Dibujar el cubo
        dibujar_cubo(p1, p2, p3, p4, p5, p6, p7, p8, 15);
        // Incrementar el angulo
        angulo = angulo + 0.1;
        // Cambiar el eje de rotacion
        if (eje == 1)
            eje = 2;
        else
            if (eje == 2)
                eje = 3;
            else
                eje = 1;
        // Esperar un momento
        delay(10);
    }

    // Cerrar la libreria grafica
    closegraph();
    return 0;
}

// Dibujar un punto en la pantalla
void dibujar_punto(int x, int y, int color)
{
    putpixel(x, y, color);
}

// Dibujar una linea en la pantalla
void dibujar_linea(int x1, int y1, int x2, int y2, int color)
{
    line(x1, y1, x2, y2);
}

// Dibujar un cubo en la pantalla
void dibujar_cubo(struct punto p1, struct punto p2, struct punto p3, struct punto p4, struct punto p5, struct punto p6, struct punto p7, struct punto p8, int color)
{
    // Dibujar las caras del cubo
    dibujar_linea(p1.x, p1.y, p2.x, p2.y, color);
    dibujar_linea(p2.x, p2.y, p3.x, p3.y, color);
    dibujar_linea(p3.x, p3.y, p4.x, p4.y, color);
    dibujar_linea(p4.x, p4.y, p1.x, p1.y, color);
    dibujar_linea(p5.x, p5.y, p6.x, p6.y, color);
    dibujar_linea(p6.x, p6.y, p7.x, p7.y, color);
    dibujar_linea(p7.x, p7.y, p8.x, p8.y, color);
    dibujar_linea(p8.x, p8.y, p5.x, p5.y, color);
    dibujar_linea(p1.x, p1.y, p5.x, p5.y, color);
    dibujar_linea(p2.x, p2.y, p6.x, p6.y, color);
    dibujar_linea(p3.x, p3.y, p7.x, p7.y, color);
    dibujar_linea(p4.x, p4.y, p8.x, p8.y, color);
}

// Rotar un punto
void rotar_punto(struct punto *p, float angulo, int eje)
{
    // Declaracion de variables
    float x, y, z;

    // Rotar el punto
    if (eje == 1)
    {
        x = p->x;
        y = p->y * cos(angulo) - p->z * sin(angulo);
        z = p->y * sin(angulo) + p->z * cos(angulo);
    }
    else
        if (eje == 2)
        {
            x = p->x * cos(angulo) + p->z * sin(angulo);
            y = p->y;
            z = -p->x * sin(angulo) + p->z * cos(angulo);
        }
        else
        {
            x = p->x * cos(angulo) - p->y * sin(angulo);
            y = p->x * sin(angulo) + p->y * cos(angulo);
            z = p->z;
        }
    p->x = x;
    p->y = y;
    p->z = z;
}

// Rotar un cubo
void rotar_cubo(struct punto *p1, struct punto *p2, struct punto *p3, struct punto *p4, struct punto *p5, struct punto *p6, struct punto *p7, struct punto *p8, float angulo, int eje)
{
    // Rotar los puntos del cubo
    rotar_punto(p1, angulo, eje);
    rotar_punto(p2, angulo, eje);
    rotar_punto(p3, angulo, eje);
    rotar_punto(p4, angulo, eje);
    rotar_punto(p5, angulo, eje);
    rotar_punto(p6, angulo, eje);
    rotar_punto(p7, angulo, eje);
    rotar_punto(p8, angulo, eje);
}

// // Proyectar un punto
// void proyectar_punto(struct punto *p)
// {
//     // Declaracion de variables
//     float x, y;

//     // Proyectar el punto
//     x = p->x * (focal / (focal + p->z));
//     y = p->y * (focal / (focal + p->z));
//     p->x = x;
//     p->y = y;
// }

// // Proyectar un cubo
// void proyectar_cubo(struct punto *p1, struct punto *p2, struct punto *p3, struct punto *p4, struct punto *p5, struct punto *p6, struct punto *p7, struct punto *p8)
// {
//     // Proyectar los puntos del cubo
//     proyectar_punto(p1);
//     proyectar_punto(p2);
//     proyectar_punto(p3);
//     proyectar_punto(p4);
//     proyectar_punto(p5);
//     proyectar_punto(p6);
//     proyectar_punto(p7);
//     proyectar_punto(p8);
// }



