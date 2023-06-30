/**
 * @file arbol.c
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-14
 *
 * Implementación de un arbol binario
 */

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
// Constantes
#define RESOLUCION_X 1280
#define RESOLUCION_Y 720
#define RADIO 24
// Estructuras

/*Estructura del nodo*/
typedef struct nodo
{
    struct nodo *izquierda;
    int hijosIzquierda;
    struct nodo *padre;
    int dato;
    int hijosDerecha;
    struct nodo *derecha;

} Nodo;

/*Estructura del arbol*/
typedef struct arbol
{
    int Total_iqz;
    int Total_derecho;
    Nodo *raiz;
} Arbol;

// Prototipos de funciones
Arbol *crearArbol();
Nodo *crearNodo(int dato);
void insertarNodo(Arbol *a, Nodo *n, int *, int *);
int estaVacioArbol(Arbol *a);
void imprimir(Arbol *a);
void imprimirNodo(Nodo *n);
void dimension(int *n);
void menu(Arbol *a);
void aleatorios(Arbol *a);
void datosManuales(Arbol *a);
void arbol_grafico(Arbol *a);
// Función principal
int main(int *argc, char *argv[])
{

    srand(time(NULL));
    initwindow(RESOLUCION_X, RESOLUCION_Y, "ARBOLES ABB");
    setbkcolor(15);
    cleardevice();
    setcolor(1);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(50, 10, "2CM4");
    setcolor(1);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(475, 10, "Arboles ABB");
    setcolor(1);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(1000, 10, "Rubio Haro Diego");

    Arbol *a = crearArbol();
    menu(a);
    return 0;
}
// Cuerpo de funciones

/*Función crear el arbol*/
Arbol *crearArbol()
{
    Arbol *aux = (Arbol *)malloc(sizeof(Arbol));
    aux->Total_iqz = 0;
    aux->Total_derecho = 0;
    aux->raiz = NULL;
    return aux;
}

/*Función crear nodo*/
Nodo *crearNodo(int dato)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->izquierda = NULL;
    aux->padre = NULL;
    aux->derecha = NULL;
    aux->hijosIzquierda = 0;
    aux->hijosIzquierda = 0;
    aux->dato = dato;
    return aux;
}

/*Función insertar nodo*/
void insertarNodo(Arbol *a, Nodo *n, int *x, int *y)
{
    char num[5];
    int nt = 100;
    int posy = nt - RADIO - 10;
    int errorx = 13;
    int errory = 10;

    Nodo *aux, *anterior;
    if (estaVacioArbol(a))
    {
        a->raiz = n;
        setfillstyle(SOLID_FILL, BLUE);
        circle(RESOLUCION_X / 2, posy, RADIO);
        setcolor(1);
        sprintf(num, "%d", a->raiz->dato);
        settextstyle(BOLD_FONT, HORIZ_DIR, 1);
        outtextxy((RESOLUCION_X / 2) - errorx, posy - errory, num);
    }
    else
    {
        aux = a->raiz;
        while (aux != NULL)
        {
            anterior = aux;
            if (n->dato > aux->dato)
            {
                aux = aux->derecha;

                setfillstyle(SOLID_FILL, BLUE);
                circle((RESOLUCION_X / 2) + (*x), (nt - (RADIO / 2)) + (*y), RADIO);
                setcolor(1);
                sprintf(num, "%d", aux->dato);

                // settextstyle(BOLD_FONT, HORIZ_DIR, 1);
                // outtextxy(((RESOLUCION_X / 2)+(*x)) - 13, (nt - RADIO)+(*y), num);
                (*x) = (*x) + (*x);
                (*y) = (*y) + (*y);
            }
            else
            {
                aux = aux->izquierda;
                // setfillstyle(SOLID_FILL, BLUE);
                // circle((RESOLUCION_X / 2) - (*x), (nt - (RADIO / 2)) + (*y), RADIO);
                // setcolor(1);
                // sprintf(num, "%d", aux->dato);
                // settextstyle(BOLD_FONT, HORIZ_DIR, 1);
                // outtextxy((RESOLUCION_X / 2)+*x - 13, (nt - RADIO)+*y, num);
                // *x = *x + *x;
                // *y = *y + *y;
            }
        }
        n->padre = anterior;
        if (n->dato > anterior->dato)
        {
            anterior->derecha = n;
        }
        else
        {
            anterior->izquierda = n;
        }
    }
}

/*Función arbol=vacío*/
int estaVacioArbol(Arbol *a)
{
    if (a->raiz == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*Función imprimir arbol*/
void imprimir(Arbol *a)
{
    if (estaVacioArbol(a))
    {
        printf("\nArbol vacio");
    }
    else
    {
        imprimirNodo(a->raiz);
    }
}

/*Función imprimir nodo*/
void imprimirNodo(Nodo *n)
{
    if (n != NULL)
    {
        printf(" %d", n->dato);
        imprimirNodo(n->izquierda);
        imprimirNodo(n->derecha);
    }
}

/*Función menú*/
void menu(Arbol *a)
{

    int opc = 0;
    system("cls");
    printf("\n----------------------- Arbol ABB ----------------------");
    printf("\n1. Numeros Aleatorios\n2. Numeros elegidos\n3. Ver arbol\n4. Salir");
    printf("\n--------------------------------------------------------");
    printf("\nOpcion: ");
    scanf("%d", &opc);
    if (opc == 1)
    {
        aleatorios(a);
        menu(a);
    }
    else if (opc == 2)
    {
        datosManuales(a);
        menu(a);
    }
    else if (opc == 3)
    {
        imprimir(a);
        printf("\n\n");
        system("pause");
        menu(a);
    }
    else if (opc == 4)
    {
        exit(0);
    }
    else if (opc == 5)
    {
        // arbol_grafico(a);
    }

    else
    {
        system("cls");
        printf("ERROR, INTENTE DE NUEVO");
    }
}

/*Función ingreso de nodos con valores aleatorios*/
void aleatorios(Arbol *a)
{
    int x = RADIO * 2 + 10;
    int y = RADIO * 2 + 10;
    for (int i = 0; i < 50; i++)
    {
        insertarNodo(a, crearNodo(1 + rand() % 200), &x, &y);
    }
}

/*Función ingreso de nodos manualmente*/
void datosManuales(Arbol *a)
{
    system("cls");
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        int aux;
        int x = RADIO * 2 + 10;
        int y = RADIO * 2 + 10;
        printf("\nValor [%i]: ", i + 1);
        scanf("%d", &aux);
        insertarNodo(a, crearNodo(aux), &x, &y);
    }
}