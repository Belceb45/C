
/*
    Listas Enlazadas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Las listas enlazadas son una colección de estructuras
autoreferenciadas, llamadas nodos, con estas podemos
guardar y modificar datos en tiempo de ejecución

Estructura Autoreferenciada:
    Es la que contiene un miembro apuntador que apunta a una
    estructura del mismo tipo

*/
typedef struct nodo
{
    char *titulo;
    char *autor;
    char *isbn;
    struct nodo *sig;
} Libro;


int main()
{
    Libro *Lista = listaLibro(Lista);
    Lista = agregarLibro(Lista, "ESTRUCTURAS DE DATOS C");
    Lista = agregarLibro(Lista, "LISTAS ENLAZADAS");
    Lista = agregarLibro(Lista, "PILAS Y COLAS");
    mostrarLista(Lista);
    eliminarLibro(Lista, "ESTRUCTURAS DE DATOS C");
    mostrarLista(Lista);

    return 0;
}
// La funcion debe devolver un puntero de tipo Libro
// es por eso que la funcion es de tipo Libro
Libro *listaLibro(Libro *Lista)
{
    // NULL es una palabra reservada que nos indica que en una variable no hay nada
    Lista = NULL;
    return Lista;
}

// Funcion de agregar
Libro *agregarLibro(Libro *Lista, char *titulo)
{
    Libro *nuevoLibro, *aux;
    nuevoLibro = (Libro *)malloc(sizeof(Libro));
    nuevoLibro->titulo = titulo;
    nuevoLibro->sig = NULL;
    if (Lista == NULL)
    {
        Lista = nuevoLibro;
    }
    else
    {
        aux = Lista;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevoLibro;
    }
    return Lista;
}

// Funcion de eliminar
Libro *eliminarLibro(Libro *Lista, char *titulo)
{
    while (Lista != NULL)
    {
        if (stricmp(titulo, Lista->titulo)==0)
        {
            printf("\nSe eliminara el libro: %s",Lista->titulo);
            free(Lista->titulo);
        }

        Lista = Lista->sig;
    }

    return Lista;
}
// Funcion de mostrar
void mostrarLista(Libro *Lista)
{
    while (Lista != NULL)
    {
        printf("%s\n", Lista->titulo);
        Lista = Lista->sig;
    }
    printf("Lista vacia");
}