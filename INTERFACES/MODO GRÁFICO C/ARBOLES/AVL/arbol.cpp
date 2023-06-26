/**
 * @file arbol.c
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-25
 *
 *
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
Nodo *buscarNodo(Arbol *a, int valor);
Nodo *HijoNoNull(Nodo *a);
int estaVacioArbol(Arbol *a);
int alturaNodo(Nodo *n);
void insertarNodo(Arbol *a, Nodo *n);
void preorden(Nodo *n);
void enorden(Nodo *n);
void postorden(Nodo *n);
void imprimir(Arbol *a);
void imprimirPreorden(Arbol *a);
void imprimirEnorden(Arbol *a);
void imprimirPostorden(Arbol *a);
void imprimirNodo(Nodo *n);
void dimension(int *n);
void Buscar(Arbol *a);
void Eliminar(Arbol *a);
void eliminarNodo(Arbol *a, int valor);
void menu(Arbol *a);
void aleatorios(Arbol *a);
void datosManuales(Arbol *a);
// void arbol_grafico(Arbol *a);
// Función principal
int main(int argc, char *argv[])
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
//
void Buscar(Arbol *a)
{
    system("cls");
    Nodo *aux;
    int n;
    printf("\n------------- Buscar nodo ------------\n");
    printf("\nNodo a localizar:");
    scanf("%d", &n);
    aux = buscarNodo(a, n);
    if (aux != NULL)
    {
        printf("\n\nNodo Localizado %d", aux->dato);
    }
    else
    {
        printf("\n\nNodo no se localiza");
    }
}
// Función que calcula la altura del nodo
int alturaNodo(Nodo *n)
{
    if(n!=NULL)
    {
        int hi=alturaNodo(n->izquierda);
        int hd=alturaNodo(n->derecha);
        if (hi>hd)
        {
            return hi+1;
        }
        else
        {
            return hd+1;
        }
        
        
    }
    else
    {
        return 0;
    }
}

// Encontrar un nodo
Nodo *buscarNodo(Arbol *a, int valor)
{
    Nodo *aux = NULL;
    if (!estaVacioArbol(a))
    {
        aux = a->raiz;
        while (aux != NULL && aux->dato != valor)
        {
            if (valor < aux->dato)
            {
                aux = aux->izquierda;
            }
            else
            {
                aux = aux->derecha;
            }
        }
    }
    return aux;
}

// Función para encontrar el Hijo No null
Nodo *HijoNoNull(Nodo *nodo)
{
    if (nodo->izquierda != NULL)
    {
        return nodo->izquierda;
    }
    else
    {
        return nodo->derecha;
    }
}
// Función para eliminar Nodo
void eliminarNodo(Arbol *a, int valor)
{
    Nodo *aux = buscarNodo(a, valor);
    Nodo *aux2;
    Nodo *padre;
    if (aux != NULL)
    {
        padre = aux->padre;
        if (aux->izquierda == NULL && aux->derecha == NULL) // Caso 1
        {
            if (padre != NULL)
            { // No es la raiz
                if (aux->dato < padre->dato)
                {
                    padre->izquierda = NULL;
                }
                else
                {
                    padre->derecha = NULL;
                }
            }
            else
            {
                a->raiz = NULL;
            }
            free(aux);
        }
        else if (aux->derecha == NULL || aux->izquierda == NULL) // Caso 2 A
        {
            if (padre != NULL) // No es la raiz
            {
                if (aux->dato < padre->dato)
                {
                    padre->izquierda = HijoNoNull(aux);
                }
                else
                {
                    padre->derecha = HijoNoNull(aux);
                }
                // padre->izquierda = NULL;
            }
            else
            {
                a->raiz = HijoNoNull(aux);
            }
        }
        else // Caso 3
        {
            aux2 = aux->izquierda;
            while (aux2->derecha != NULL)
            {
                aux2 = aux2->derecha;
            }
            padre = aux2->padre;
            if (aux2->dato < aux->dato)
            {
                padre->izquierda = aux2->izquierda;
            }
            else
            {
                padre->derecha = aux2->izquierda;
            }
            aux->dato = aux2->dato;
            free(aux2);
        }
    }
}
// Menu de eliminar
void Eliminar(Arbol *a)
{
    // system("cls");
    int n;
    printf("\n--------------------- Eliminar Nodo -------------------");
    printf("\nNodo que desea eliminar: ");
    scanf("%d", &n);
    eliminarNodo(a, n);
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

// Función que los poner en preorden
void preorden(Nodo *n)
{
    if (n != NULL)
    {
        printf(" %d", n->dato); // 1
        preorden(n->izquierda); // 2
        preorden(n->derecha);   // 3
    }
}
// Imprime en preorden
void imprimirPreorden(Arbol *a)
{
    if (!estaVacioArbol(a))
    {
        preorden(a->raiz);
    }
}

// Función que los pone en enorden
void enorden(Nodo *n)
{
    if (n != NULL)
    {
        enorden(n->izquierda);  // 1
        printf(" %d", n->dato); // 2
        enorden(n->derecha);    // 3
    }
}

// Imprime enorden
void imprimirEnorden(Arbol *a)
{
    if (!estaVacioArbol(a))
    {
        enorden(a->raiz);
    }
}

// Función que los ponde en postorden
void postorden(Nodo *n)
{
    if (n != NULL)
    {
        postorden(n->izquierda); // 1
        postorden(n->derecha);   // 3
        printf(" %d", n->dato);  // 2
    }
}

//
void imprimirPostorden(Arbol *a)
{
    if (!estaVacioArbol(a))
    {
        postorden(a->raiz);
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
    // system("cls");
    printf("\n----------------------- Arbol ABB ----------------------");
    printf("\n1. Numeros Aleatorios\n2. Numeros elegidos\n3. Ver preorden\n4. Ver enorden\n5. Ver postorden");
    printf("\n6. Buscar Nodo \n7. Eliminar Nodo\n8. Salir");
    printf("\n--------------------------------------------------------");
    printf("\nOpcion: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        aleatorios(a);
        menu(a);
        break;
    case 2:
        datosManuales(a);
        menu(a);
        break;
    case 3:
        imprimirPreorden(a);
        printf("\n\n");
        // system("pause");
        menu(a);
        break;
    case 4:
        imprimirEnorden(a);
        printf("\n\n");
        // system("pause");
        menu(a);
        break;
    case 5:
        imprimirPostorden(a);
        printf("\n\n");
        // system("pause");
        menu(a);
        break;
    case 6:
        Buscar(a);
        printf("\n\n");
        // system("pause");
        menu(a);
        break;
    case 7:
        Eliminar(a);
        menu(a);
        break;
    case 8:
        exit(0);
        free(a);
        break;
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
    int n;
    printf("\nNumero de nodos: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int aux;
        printf("Valor [%i]: ", i + 1);
        scanf("%d", &aux);
        insertarNodo(a, crearNodo(aux));
    }
}