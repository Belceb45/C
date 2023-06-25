#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataStructures.h"

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class ESTRUCTURAS
 * @category Pilas Estáticas
 **/

// Función crear pila
Pila *crearPila()
{
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    pila->indice = 0;
    pila->total = 0;
    return pila;
}

// Función que retorna si la pila esta vacia
int vacia(Pila pila)
{
    if (pila.total == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función que retorna si la pila esta llena
int llena(Pila pila)
{
    if (pila.total == MAX_ELEMENTOS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función para agregar (push)
int push(Pila *pila, int dato)
{
    if (pila->total < MAX_ELEMENTOS)
    {
        pila->datos[pila->indice] = dato;
        pila->indice++;
        pila->total++;
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función para eliminar (pop)
int pop(Pila *pila)
{
    int aux;
    if (pila->total > 0)
    {
        aux = pila->datos[pila->indice - 1];
        pila->indice--;
        pila->total--;
        return aux;
    }
    else
    {
        return 0;
    }
}

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class ESTRUCTURAS
 * @category Pilas Dinámicas
 **/

// FUNCIONES PARA PILAS DINAMICAS

// Función crear Coche
Coche *crearCoche(char matricula[10], int modelo, int color, int marca)
{
    Coche *aux = (Coche *)malloc(sizeof(Coche));
    strcpy(aux->matricula, matricula);
    aux->modelo = modelo;
    aux->color = color;
    aux->marca = marca;
    return aux;
}

// Función crear Nodo
Nodo_p *crearNodoD(Coche *coche)
{
    Nodo_p *aux = (Nodo_p *)malloc(sizeof(Nodo_p));
    aux->dato = coche;
    aux->siguiente = NULL;
    return aux;
}

// Función crear Pila
PilaD *crearPilaD()
{
    PilaD *aux = (PilaD *)malloc(sizeof(PilaD));
    aux->tope = NULL;
    aux->total = 0;
    return aux;
}

// Función que determina si la pila está vacía
int vaciaD(PilaD *pila)
{
    // 1 si está vacía y 0 si no lo está
    if (pila->total == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Función que inserta los valores en la pila
void pushP(PilaD *pila, Nodo_p *aux)
{
    if (vaciaD(pila))
    {
        pila->tope = aux;
    }
    else
    {
        aux->siguiente = pila->tope;
        pila->tope = aux;
    }
    pila->total++;
}

// Función que elimina un elemento
Nodo_p *popP(PilaD *pila)
{
    Nodo_p *aux = NULL;
    if (!vaciaD(pila))
    {
        aux = pila->tope;
        pila->tope = pila->tope->siguiente;
        pila->total--;
        return aux;
    }
    else
    {
        return NULL;
    }
}

// Función que vacía la pila
void vaciarP(PilaD *pila)
{
    Nodo_p *aux;
    aux = popP(pila);
    while (aux != NULL)
    {
        free(aux);
        aux = popP(pila);
    }
}

// Función que imprime
void imprimirP(PilaD *pila)
{
    Nodo_p *aux = pila->tope;
    Coche *c;
    printf("\n\n");
    if (!vaciaD(pila))
    {
        while (aux != NULL)
        {
            c = aux->dato;
            printf("\n%s  %d  %d  %d", c->matricula, c->modelo, c->color, c->marca);
            aux = aux->siguiente;
        }
    }else
    {
        printf("\n\nLa pila esta vacia");
    }
    
}