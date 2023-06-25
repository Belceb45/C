#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Programa de aplicación de temas vistos

// Calculadora avanzada
int main(int argc, const char *argv[])
{
    int a, b, resultado;
    if (argc < 3 && argc > 1)
    {
        /* strcasecmp hace lo mismo que strcmp pero ignora
           las mayusculas y minusculas*/
        int *puntero_A = &a;
        int *puntero_B = &b;
        int *puntero_resultado = &resultado;
        if (strcasecmp(argv[1], "suma") == 0)
        {
            printf("\nIngresa un numero: ");
            scanf("%i", &a);
            printf("Ingresa otro numero: ");
            scanf("%i", &b);
            resultado=(a+b);
            printf("\nLa direccion de memoria de A = %p y de B = %p y el resultado es = %i", puntero_A, puntero_B,*puntero_resultado);
        }
        else if (strcasecmp(argv[1], "resta") == 0)
        {
            printf("\nIngresa un numero: ");
            scanf("%i", &a);
            printf("Ingresa otro numero: ");
            scanf("%i", &b);
            printf("El resultado es = %i", resultado = (a - b));
            printf("\nLa direccion de memoria de A = %p y de B = %p", puntero_A, puntero_B);
        }
        else if (strcasecmp(argv[1], "multiplicacion") == 0)
        {
            printf("\nIngresa un numero: ");
            scanf("%i", &a);
            printf("Ingresa otro numero: ");
            scanf("%i", &b);
            printf("El resultado es = %i", resultado = (a * b));
            printf("\nLa direccion de memoria de A = %p y de B = %p", puntero_A, puntero_B);
        }
        else if (strcasecmp(argv[1], "division") == 0)
        {
            printf("\nIngresa un numero: ");
            scanf("%i", &a);
            printf("Ingresa otro numero: ");
            scanf("%i", &b);
            if (b > 0)
            {
                printf("El resultado es = %i", resultado = (a / b));
                printf("\nLa direccion de memoria de A = %p y de B = %p", puntero_A, puntero_B);
            }
            else
            {
                printf("La división entre cero no es valida, intente de nuevo");
            }
        }
    }
    else
    {
        printf("No se aceptan mas o menos argumentos, intente de nuevo");
    }

    // struct
    // {
    //     int a;
    //     char b[100];
    // } Tipo1;
    // printf("Hola");

    return 0;
}