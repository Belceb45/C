// Rubio Haro Diego
#include <stdio.h>
#include <stdlib.h>
// Estructura
typedef struct Perros
{
    char *raza;
    float peso;
    float altura;
    int edad;
    struct Nodo *sig;
} Perros;
// Prototipos
void agregarNodo(Perros **, int);
void mostrar(Perros *p);
void memoria_m(int ***, int);
void numNodos(int *);
// Funcion principal
int main(int argc, char *argv[])
{
    int num;
    Perros *p = NULL;
    numNodos(&num);
    agregarNodo(&p, num);
    mostrar(p);
}
// Funcion del numero de personas
void numNodos(int *num)
{
    int x = 0;
    printf("Numero de personas (1-20): ");
    scanf("%i", num);
    // printf("\nnum1: %i",*num);
    while (x == 0)
    {
        if (*num > 0 && *num <= 20)
        {
            x = 1;
        }
        else
        {
            printf("\nERROR, INTENTE DE NUEVO\nR: ");
            scanf("%i", num);
        }
    }
}

// Funcion Crear nodos
void agregarNodo(Perros **p, int num)
{
    system("cls");
    for (int i = 0; i < num; i++)
    {
        Perros *nuevo = (Perros *)malloc(sizeof(Perros));
        nuevo->raza = (char *)malloc(50 * sizeof(char));
        nuevo->sig = NULL;
        if (*p == NULL)
        {
            *p = nuevo;
        }
        else
        {
            Perros *aux = (*p);
            while (aux->sig != NULL)
            {
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
        printf("\n\nNombre de la raza: ");
        scanf(" %[^\n]%*c", nuevo->raza);
        printf("Edad: ");
        scanf("%i", &nuevo->edad);
        printf("Peso: ");
        scanf("%f", &nuevo->peso);
        printf("Altura: ");
        scanf("%f", &nuevo->altura);
    }
}
// Funcion Mostrar
void mostrar(Perros *p)
{
    system("cls");
    Perros *aux = p;
    int cont = 1;
    while (aux->sig != NULL)
    {
        printf("\n\nPerro[%i]", cont);
        printf("\nRaza: %s", aux->raza);
        printf("\nEdad: %i", aux->edad);
        printf("\nPeso: %f", aux->peso);
        printf("\nAltura: %f", aux->altura);
        aux = aux->sig;
        cont++;
        if (aux->sig == NULL)
        {
            printf("\n\nPerro[%i]", cont);
            printf("\nRaza: %s", aux->raza);
            printf("\nEdad: %i", aux->edad);
            printf("\nPeso: %f", aux->peso);
            printf("\nAltura: %f", aux->altura);
        }
    }
}