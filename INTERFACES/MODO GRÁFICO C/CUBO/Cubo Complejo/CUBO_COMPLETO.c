/**
 * @file CUBO_COMPLETO.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-03-05
 *
 *
 */

// Crear un programa que genere una lista doblemente enlazada con n nodos, cada nodo debe contener un numero aleatorio entre 1 y 100, debe mostrar los nodos de forma inversa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int dato;
    struct nodo *izquierda;
    struct nodo *derecha;
    struct nodo *arriba;
    struct nodo *abajo;
    struct nodo *adelante;
    struct nodo *atras;


};

struct lista
{
    struct nodo *inicio;
    struct nodo *fin;
};

// Prototipos de funciones
// Funciones con estructuras
void crearListas(struct lista *, int);
void insertar(struct lista *, int);
void mostrar(struct lista *);
void mostrarInverso(struct lista *);
void num_listas(struct lista **, int);

void funt1();
void longitud(int *, int *);
void mostrarListas(struct lista *, int);
void mostrarInicioFin(struct lista *, int);
// Funcion principal
int main()
{
    funt1();
    return 0;
}

// Funcion para crear las listas
void crearListas(struct lista *lista, int n)
{

    if (n==0)
    {
        return;
    }
    
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            insertar(&lista[i], rand() % 100 + 1);
        }
    }
}

// Funcion para insertar elementos a la lista
void insertar(struct lista *lista, int n)
{
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
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
    struct nodo *actual = (struct nodo *)malloc(sizeof(struct nodo));
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

// Funcion para mostrar los elementos de la lista inversa
void mostrarInverso(struct lista *lista)
{
    struct nodo *actual = (struct nodo *)malloc(sizeof(struct nodo));
    actual = lista->fin;
    if (lista->inicio != NULL)
    {
        int cont = 1;
        while (actual != NULL)
        {
            printf("\nNodo[%d]: %d ", cont, actual->dato);
            actual = actual->derecha;
        }
    }
    else
    {
        printf("\nbLa lista esta vacia");
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
    mostrar(&lista[n-1]);
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