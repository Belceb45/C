/**
 * @file tienda.c
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * Archivo/Desarrollo de funciones
 */

// Librerias
#include "tienda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

/*Funciones de listas*/
// Función crear nodo lista de clases
void crearNodo(tipo **nuevoNodo, char nombreTipo[])
{
    *nuevoNodo = (tipo *)malloc(sizeof(tipo));
    strcpy((*nuevoNodo)->tipoProducto, nombreTipo);
    (*nuevoNodo)->listaP = NULL;
    (*nuevoNodo)->sig = NULL;
    (*nuevoNodo)->anterior = NULL;
}
// Función para insertar nodos de lista de clases
void insertarNodo(tipo **lista, char tipoProducto[])
{
    tipo *nuevoNodo;
    crearNodo(&nuevoNodo, tipoProducto);
    if (*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        tipo *actual = *lista;
        while (actual->sig != NULL)
        {
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
        nuevoNodo->anterior = actual;
    }
}
// Función que crea Nodos de la sublista de clases (lista de productos)
void crearNodoProducto(producto** nuevoNodo, char nombre[], int cantidad) {
    *nuevoNodo = (producto*)malloc(sizeof(producto));
    strcpy((*nuevoNodo)->nombre_producto, nombre);
    (*nuevoNodo)->precio = cantidad;
    (*nuevoNodo)->sig = NULL;
}
//  Función para insertar nodos a la sublista de clases (lista de productos)
void insertarNodoProducto(producto **listaProductos, char nombre[], int cantidad)
{
    producto *nuevoNodo;
    crearNodoProducto(&nuevoNodo, nombre, cantidad);
    if (*listaProductos == NULL)
    {
        *listaProductos = nuevoNodo;
    }
    else
    {
        producto *actual = *listaProductos;
        while (actual->sig != NULL)
        {
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
    }
}
// Función para imprimir lista
void imprimirLista(tipo *lista)
{
    tipo *actualTipo = lista;
    while (actualTipo != NULL)
    {
        printf("\nTipo de Producto: %s\n", actualTipo->tipoProducto);
        producto *actualProducto = actualTipo->listaP;
        while (actualProducto != NULL)
        {
            printf("Nombre: %s, Cantidad: %d\n", actualProducto->nombre_producto, actualProducto->precio);
            actualProducto = actualProducto->sig;
        }
        actualTipo = actualTipo->sig;
    }
}
// Impimir todo

// Función que libera las listas
void liberarLista(tipo **lista)
{
    if (*lista != NULL)
    {
        tipo *actualTipo = *lista;
        while (actualTipo != NULL)
        {
            producto *actualProducto = actualTipo->listaP;
            while (actualProducto != NULL)
            {
                producto *siguienteProducto = actualProducto->sig;
                free(actualProducto);
                actualProducto = siguienteProducto;
            }
            tipo *siguienteTipo = actualTipo->sig;
            free(actualTipo);
            actualTipo = siguienteTipo;
        }
        *lista = NULL;
    }
}

/*Funciones dist*/
// Función que crea el numero de clases de productos y asigna tipos de productos
void CrearClases(tipo **clases)
{
    // Agregar las clases base
    insertarNodo(clases, "PRODUCTOS DE DESPENSA");
    insertarNodo(clases, "BEBIDAS");
    insertarNodo(clases, "BOTANAS");
    insertarNodo(clases, "CONFITERIA");
    insertarNodo(clases, "FRIOS");
    insertarNodo(clases, "JARCIERIA");
    insertarNodo(clases, "HIGIENE PERSONAL");
    insertarNodo(clases, "PRODUCTOS ALIMENTICIOS EXTRAS");
    insertarNodo(clases, "DOMESTICO");
    // Agregar los productos base
    insertarNodoProducto(&((*clases)->listaP), "Leche", 20);
    insertarNodoProducto(&((*clases)->listaP->sig), "Galletas", 50);
    // Linea para accecer al nombre del segundo nodo de la lista principal

    imprimirLista(*clases);
}

// Función de mensaje
void msj(int n)
{
    char *opcion[4] = {"\nNO FUE POSIBLE ASIGNAR LA MEMORIA",
                       "\nMEMORIA ASIGNADA CON EXITO"};
    printf("\n%s\n", opcion[n]);
}
