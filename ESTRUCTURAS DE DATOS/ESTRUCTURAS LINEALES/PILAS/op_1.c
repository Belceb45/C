#include <stdio.h>
#include <stdlib.h>
/**
 * @file op_1.c
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2022-11-27
 *
 Las pilas o stacks son estructuras de datos que tienen una característica,
 los elementos de la pila o stack se agregan y se sacan desde el tope de
 la misma y solo desde el tope, lo que desemboca en lo que llamaremos la
 política de la pila.

 "El último en entrar es el primero en salir"

 Operaciones básicas de una pila o stack:

    1. new: Crear una pila o stack
    2. Apilar o push
    3. Desapilar o pop
    4. isEmpy: Verificar si la pila o stack está vacía o no
    5. isFull: Verificar si la pila o stack está llena o no
    6. count: Contar el número de elementos de la pila o stack
    7. peek: Ver el elemento que está en el tope de la pila o stack
    8. change: Cambiar el valor del elemento que está en el tope de la pila o stack
    9. display: Mostrar los elementos de la pila o stack
    10. destroy: Eliminar la pila o stack



 */

/* PILAS ESTÁTICAS: Son aquellas que tienen un a las que se les define un
                    tamaño al momento de crearse y no puede ser cambiado*/


// ESTRUCTURAS CREADAS

// Estructura como elemento de la pila
struct elemento
{
    int x;
    int y;
};
// Estructura de la pila o stack
struct pila
{
    struct elemento *elementos;
    int contador;
    int tope;
};

// PROTOTIPOS DE FUNCIONES
// Principales
int crear_pila(struct pila *, int);
int isEmpty(struct pila);
int isFull(struct pila);
int push(struct pila *, struct elemento);
int pop(struct pila *, struct elemento *);


// Función principal
int main()
{
    // Creamos una estructura de tipo pila
    struct pila mipila;
    if (!crear_pila(&mipila, 10))
    {
        printf("La pila se creó correctamente con un tamaño de 10 elementos");
        return -1;
    }
    // Creamos una estructura de tipo elemento
    struct elemento e1;
    e1.x = 0;
    e1.y = 0;
    struct elemento e2;
    e2.x = 1;
    e2.y = 1;
    struct elemento e3;
    e3.x = 2;
    e3.y = 2;
    struct elemento e4;
    e4.x = 3;
    e4.y = 3;

    push(&mipila, e1);
    push(&mipila, e2);
    push(&mipila, e3);
    push(&mipila, e4);

    struct elemento e5;
    int result = pop(&mipila, &e5);
    printf("\nResultado: %d", result);
    return 0;
}

// FUNCIONES

// Función para crear una pila o stack y la retornamos para que el usuario la use

int crear_pila(struct pila *p, int num_elementos)
{
    if (num_elementos < 0)
    {
        return 0;
    }

    struct elemento arreglo_elementos[num_elementos];
    p->elementos = arreglo_elementos;
    p->tope = num_elementos - 1;
    p->contador = 0;
    return 1;
}
// Funcion push para agregar un elemento a la pila o stack
int push(struct pila *p, struct elemento e)
{
    // Validamos las entradas de la pila, la pla pila no puede ser nula
    if (p == NULL)
    {
        return -1;
    }
    /* Validamos que la pila no esté llena, si está llena no podemos agregar
     */
    if (isFull(*p) == 1)
    {
        return -2;
    }
    p->elementos[p->contador] = e;
    // Acabamos de introducir un elemento, por lo tanto el contador aumenta
    p->contador++;
    return 1;
}
// Función pop para sacar un elemento de la pila o stack
int pop(struct pila *p, struct elemento *e)
{
    // Validamos las entradas de la pila, la pla pila no puede ser nula
    if (p == NULL)
    {
        return -1;
    }
    /* Validamos que la pila no esté vacía, si está vacía no podemos sacar
     */
    if (isEmpty(*p))
        {
            return -2;
        }
    struct elemento resp = (*p).elementos[(*p).contador - 1];
    (*p).contador--;

    e->x = resp.x;
    e->y = resp.y;
    return 1;
}
// Función para verificar si la pila o stack está vacía o no
int isEmpty(struct pila p)
{
    // Comprobamos si la pila esta vacia.
    if (p.contador == 0)
    {
        return 1;
    }
    return 0;
}

// Función para verificar si la pila o stack está llena o no
int isFull(struct pila p)
{
    // Comprobamos si la pila esta llena.
    if (p.contador > p.tope)
    {
        return 1;
    }
    return 0;
}

// Funcion para ver cuantos elementos tiene la pila o stack
int count(struct pila p)
{
    return p.contador;
}
// Función para ver el elemento que está en el tope de la pila o stack
struct elemento peek(struct pila p)
{
    return p.elementos[p.contador - 1];
}
// Función para cambiar el valor del elemento que está en el tope de la pila o stack
int change(struct pila *p, struct elemento e)
{
    // Validamos las entradas de la pila, la pla pila no puede ser nula
    if (p == NULL)
    {
        return -1;
    }
    /* Validamos que la pila no esté vacía, si está vacía no podemos sacar
     */
    if (isEmpty(*p))
        {
            return -2;
        }
    p->elementos[p->contador - 1] = e;
    return 1;
}
// Función para mostrar los elementos de la pila o stack
void display(struct pila p)
{
    for (int i = 0; i < p.contador; i++)
    {
        printf("\nElemento %d: (%d, %d)", i, p.elementos[i].x, p.elementos[i].y);
    }
}

