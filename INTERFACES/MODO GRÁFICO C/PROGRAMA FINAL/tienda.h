/**
 * @file tienda.h
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * Archivo de cabecera
 */

// Directiva del preprocesador
#ifndef __tienda__
#define __tienda__

// Estructuras
// Estructura de producto
typedef struct producto
{
    char nombre_producto[100];
    int precio;
    int id;
    struct producto *sig;
    struct producto *anterior;
} producto;

// Estructura de tipos
typedef struct tienda
{
    char tipoProducto[50];
    struct product *listaP;
    struct tipo *sig;
    struct tipo *anterior;
} tipo;


void crearNodo(tipo **nuevoNodo, char nombreTipo[]);
void insertarNodo(tipo **lista, char tipoProducto[]);
void crearNodoProducto(producto **nuevoNodo, char nombre[], int cantidad);
void insertarNodoProducto(producto **listaProductos, char nombre[], int cantidad);
void imprimirLista(tipo *);
void liberarLista(tipo **);
void CrearClases(tipo **);

void msj(int);

#endif