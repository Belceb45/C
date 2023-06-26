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
#define SIZE_SEC 25
#define SIZE_CUBO 5
// Estructuras
typedef struct Nodo
{
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
    struct Nodo *arriba;
    struct Nodo *abajo;
    struct Nodo *adelante;
    struct Nodo *atras;

} NODO;

typedef struct lista
{
    struct Nodo *inicio;
    struct Nodo *fin;

} LIST;

// Prototipos de funciones
void crearCubo();
void menu();

void crearListas(struct lista *, int);
void insertar(struct lista *, int);
void mostrar(struct lista *);
void mostrarInverso(struct lista *);
void num_listas(struct lista **, int);

void msg(int );
void funt1();
void longitud(int *, int *);
void mostrarListas(struct lista *, int);
void mostrarInicioFin(struct lista *, int);

// Graficos
void graficarCubo();
void aristasCentrales(int, int);
void contornoCubo(int, int);

// Funcion principal
int main()
{
    crearCubo();
    return 0;
}
// Crear Cubo
void crearCubo()
{
    funt1();
    menu();
}

//Función para el tamaño del cubo
void tam_CUBO(int *n)
{
    printf("\nParametro del CUBO (NxN): ");
    scanf("%d",n);
}
// Funcion para crear las listas
void crearListas(struct lista *lista, int n)
{

    if (n == 0)
    {
        return;
    }

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            insertar(&lista[i], rand() % 100 + 1);
        }
    }
}

// Funcion para insertar elementos a la lista
void insertar(struct lista *lista, int n)
{
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = n;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = nuevo;
        lista->fin = nuevo;
    }
    else
    {
        lista->fin->izquierda = nuevo;
        nuevo->derecha = lista->fin;
        lista->fin = nuevo;
    }
}

// Funcion para mostrar los elementos de la lista
void mostrar(struct lista *lista)
{
    struct Nodo *actual = (struct Nodo *)malloc(sizeof(struct Nodo));
    actual = lista->inicio;
    printf("\n");
    int cont = 1;
    if (lista->inicio != NULL)
    {
        while (actual != NULL)
        {
            printf("\nNodo[%d]: %d ", cont, actual->dato);
            actual = actual->izquierda;
            cont++;
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
}



// Funcion funt
void funt1()
{
    
    struct lista *lista;
    int n, nodos;
    longitud(&n, &nodos);
    printf("\nn: %d  nodos: %d", n, nodos);
    srand(time(NULL));
    num_listas(&lista, n);
    crearListas(lista, n);
    mostrarListas(lista, n);
    mostrarInicioFin(lista, n);
    
}

// Funcion longitud
void longitud(int *n, int *nodos)
{
    printf("\nIngrese la dimension del cubo (No se recomienda mas de 10): ");
    scanf("%d", n);
    *nodos = (*n) * (*n);
}

// Funcion num_listas
void num_listas(struct lista **lista, int n)
{
    (*lista) = (struct lista *)malloc(n * sizeof(struct lista));
    for (int i = 0; i < n; i++)
    {
        (*lista)[i].inicio = NULL;
        (*lista)[i].fin = NULL;
    }
}

// Funcion mostrarListas
void mostrarListas(struct lista *lista, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\n\nLista %d", i + 1);
        mostrar(&lista[i]);
    }
}

// Funcion que muestra el inicio y el fin de cada lista
void mostrarInicioFin(struct lista *lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\nLista %d", i + 1);
        printf("\nInicio: %d", lista[i].inicio->dato);
        printf("\nFin: %d", lista[i].fin->dato);
    }
}


// Funcion de menu
void menu()
{
    initwindow(1440, 840, "CUBO COMPLETO");
    int op_salir = 0;
    while (op_salir == 0)
    {
        settextstyle(1, 0, 3);
        char menu[50];
        setcolor(WHITE);
        strcpy(menu, "MENU: ");
        outtextxy(1000, 150, menu);
        strcpy(menu, "1.- Sumar Caras");
        outtextxy(1000, 230, menu);
        strcpy(menu, "2.- Sumar Filas");
        outtextxy(1000, 300, menu);
        strcpy(menu, "3.- Sumar Columnas");
        outtextxy(1000, 370, menu);
        strcpy(menu, "4.- Salir");
        outtextxy(1000, 440, menu);
        strcpy(menu, "Rubio Haro Diego 2CM3");
        outtextxy(900, 800, menu);
        // CUBO
        graficarCubo();
        //
        char letra = getch();
        int opcion = letra - '0';
        // printf("\nLetra: %c", letra);
        // printf("\nNum: %d", opcion);
        switch (opcion)
        {
        case 1:
            printf("\nSumar Caras");
            break;
        case 2:
            printf("\nSumar Filas");
            break;
        case 3:
            printf("\nSumar Columnas");
            break;
        case 4:
            printf("\nSaliendo.....");
            op_salir = 1;
            break;
        default:
            break;
        }
    }
}

// Funcion que devuelve un numero aleatorio
int num_Aleatorio()
{
    int num = 1 + rand() % 99;
    return num;
}
// Función de mensajes
void msg(int i)
{
    char *msg[] = {"Error de memoria", "Error de dato", "Dato no encontrado", "Dato eliminado", "Dato modificado", "Dato insertado"};
    printf("\n%s", msg[i]);
}

// Funciones para el Modo Grafico

// Funcion para graficar el cubo
void graficarCubo()
{
    
    aristasCentrales(0, -120);
    contornoCubo(0, -120);
}

//
void aristasCentrales(int x, int y)
{ // Caras
    setlinestyle(1, 0, 1);
    // CARA POSTERIOR
    setcolor(YELLOW);
    line(430 + x, 150 + y, 430 + x, 550 + y);
    line(510 + x, 150 + y, 510 + x, 550 + y);
    line(590 + x, 150 + y, 590 + x, 550 + y);
    line(670 + x, 150 + y, 670 + x, 550 + y);

    line(350 + x, 230 + y, 750 + x, 230 + y);
    line(350 + x, 310 + y, 750 + x, 310 + y);
    line(350 + x, 390 + y, 750 + x, 390 + y);
    line(350 + x, 470 + y, 750 + x, 470 + y);

    // CARA INFERIOR
    setcolor(GREEN);
    // x
    line(230 + x, 800 + y, 430 + x, 550 + y);
    line(310 + x, 800 + y, 510 + x, 550 + y);
    line(390 + x, 800 + y, 590 + x, 550 + y);
    line(470 + x, 800 + y, 670 + x, 550 + y);
    // y
    line(716 + x, 594 + y, 320 + x, 594 + y);
    line(670 + x, 644 + y, 280 + x, 644 + y);
    line(630 + x, 697 + y, 240 + x, 697 + y);
    line(590 + x, 750 + y, 200 + x, 750 + y);

    // CARA Izquierda
    setcolor(MAGENTA);
    line(150 + x, 500 + y, 350 + x, 250 + y);
    line(150 + x, 600 + y, 350 + x, 350 + y);
    line(150 + x, 700 + y, 350 + x, 450 + y);
    line(300 + x, 212 + y, 300 + x, 612 + y);
    line(250 + x, 275 + y, 250 + x, 675 + y);
    line(200 + x, 337 + y, 200 + x, 737 + y);

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    // CARA FRONTAL
    setcolor(CYAN);
    line(150 + x, 480 + y, 550 + x, 480 + y);
    line(150 + x, 560 + y, 550 + x, 560 + y);
    line(150 + x, 640 + y, 550 + x, 640 + y);
    line(150 + x, 720 + y, 550 + x, 720 + y);

    line(230 + x, 400 + y, 230 + x, 800 + y);
    line(310 + x, 400 + y, 310 + x, 800 + y);
    line(390 + x, 400 + y, 390 + x, 800 + y);
    line(470 + x, 400 + y, 470 + x, 800 + y);

    // CARA SUPERIOR
    setcolor(BLUE);
    // Horizontales
    line(320 + x, 194 + y, 716 + x, 194 + y);
    line(280 + x, 244 + y, 670 + x, 244 + y);
    line(233 + x, 297 + y, 630 + x, 297 + y);
    line(186 + x, 350 + y, 588 + x, 350 + y);
    // Verticales
    line(230 + x, 400 + y, 430 + x, 150 + y);
    line(310 + x, 400 + y, 510 + x, 150 + y);
    line(390 + x, 400 + y, 590 + x, 150 + y);
    line(470 + x, 400 + y, 670 + x, 150 + y);
    // CARA Derecha
    setcolor(RED);
    // Horizontal
    line(550 + x, 480 + y, 750 + x, 230 + y);
    line(550 + x, 560 + y, 750 + x, 310 + y);
    line(550 + x, 640 + y, 750 + x, 390 + y);
    line(550 + x, 720 + y, 750 + x, 470 + y);
    // Vertical
    line(716 + x, 194 + y, 716 + x, 594 + y);
    line(670 + x, 244 + y, 670 + x, 644 + y);
    line(630 + x, 297 + y, 630 + x, 697 + y);
    line(590 + x, 350 + y, 590 + x, 750 + y);
}

// Dibujar el contorno del cubo
void contornoCubo(int x, int y)
{
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(WHITE);

    // Lineas superiores de contorno
    line(350 + x, 150 + y, 750 + x, 150 + y);
    line(150 + x, 400 + y, 550 + x, 400 + y);

    // Superior izquierda
    line(150 + x, 400 + y, 350 + x, 150 + y);
    // Superior derecha
    line(550 + x, 400 + y, 750 + x, 150 + y);
    // Inferior izquierda
    line(150 + x, 800 + y, 350 + x, 550 + y);
    // Inferior derecha
    line(550 + x, 800 + y, 750 + x, 550 + y);

    // Lineas verticales de contorno
    // Izquierda superior
    line(350 + x, 550 + y, 350 + x, 150 + y);
    // Izquierda inferior
    line(150 + x, 400 + y, 150 + x, 800 + y);
    // Derecha superior
    line(750 + x, 150 + y, 750 + x, 550 + y);
    // Derecha inferior
    line(550 + x, 400 + y, 550 + x, 800 + y);

    // Cara inferior
    line(350 + x, 550 + y, 750 + x, 550 + y);
    // Cara inferior
    line(150 + x, 800 + y, 550 + x, 800 + y);
}
