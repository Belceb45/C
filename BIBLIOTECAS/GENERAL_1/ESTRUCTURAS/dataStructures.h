#ifndef _dataStructures
#define _dataStructures
#define MAX_ELEMENTOS 100
/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class ESTRUCTURAS
 * @category Pilas Estáticas
 **/

// Estructura ya definida (PILA)
typedef struct pila
{
    int indice;
    int total;
    int datos[MAX_ELEMENTOS];
} Pila;

// Función que crea la pila
Pila *crearPila();
// Función para saber si la pila está vacía
int vacia(Pila);
// Función para saber si la pila está llena
int llena(Pila);
// Función para agregar (push)
int push(Pila *, int);
// Función para eliminar (pop)
int pop(Pila *);

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class ESTRUCTURAS
 * @category Pilas Dinamicas
 **/

// Estructuras definidas para la pila dinamica (PILA DINMAICA)
typedef struct coche
{
    char matricula[10];
    int modelo;
    int color;
    int marca;
} Coche;
// Estructura de nodo
typedef struct nodo_p
{
    // El dato del nodo
    Coche *dato;
    // Apuntador el siguiente coche (nodo)
    struct nodo_p *siguiente;
} Nodo_p;
// Estructura de la pila
typedef struct pilaD
{
    Nodo_p *tope;
    int total;
} PilaD;

// FUNCIONES PARA PILAS DINAMICAS

// Función que crea un coche
Coche *crearCoche(char[10], int, int, int);
// Función que crea un nodo para el coche
Nodo_p *crearNodoD(Coche *);
// Función que crea la pila
PilaD *crearPilaD();
// Función que determina si está vacía la pila
int vaciaD(PilaD *);
// Función para insertar los elementos
void pushP(PilaD *, Nodo_p *);
// Función para eliminar elemento
Nodo_p *popP(PilaD *);
//Función para vaciar la pila
void vaciarP(PilaD *);
// Función para imprimir
void imprimirP(PilaD *);

#endif