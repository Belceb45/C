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

// #include <graphics.h>

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
void insertarNodo(Arbol *a, Nodo *n);
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
    // srand(time(NULL));
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
void insertarNodo(Arbol *a, Nodo *n)
{
    Nodo *aux, *anterior;
    if (estaVacioArbol(a))
    {
        a->raiz = n;
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
            }
            else
            {
                aux = aux->izquierda;
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
        arbol_grafico(a);
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
    for (int i = 0; i < 50; i++)
    {
        insertarNodo(a, crearNodo(1 + rand() % 200));
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
        printf("\nValor [%i]: ", i + 1);
        scanf("%d", &aux);
        insertarNodo(a, crearNodo(aux));
    }
}