#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const float dolar = 0.0504509;
const float peso = 19.8212;

// Platzi: Relaizar un programa que cambie de dolares a pesos y viceversa

void casos(char opcion[12])
{
    float a, resultado;
    int condicion = 1;
    if (stricmp(opcion, "MXN a USD") == 0)
    {
        while (condicion == 1)
        {
            printf("\nUsted eligio la opcion: MXN a USD ");
            printf("\nIngrese el monto (MXN): ");
            scanf("%f", &a);
            if (a > 0)
            {
                resultado = a * dolar;
                printf("%f", resultado);
                condicion=0;
            }
            else
            {
                printf("\nNo se admiten numeros menores o iguales a cero, intenta de nuevo :");
            }
        }
    }
    if (stricmp(opcion, "USD a MXN") == 0)
    {
        while (condicion == 1)
        {
            printf("\nUsted eligio la opcion: USD a MXN ");
            printf("\nIngrese el monto (USD): ");
            scanf("%f", &a);
            if (a > 0)
            {
                resultado = a * peso;
                printf("%f", resultado);
                condicion=0;
            }
            else
            {
                printf("No se admiten numeros menores o iguales a cero, intenta de nuevo");
            }
        }
    }
}
int main()
{
    char opcion[100];

    printf("\nHola, elige la opcion de cambio");
    printf("\n1.-MXN a USD\n2.-USD a MXN\nR: ");
    // Usamos gets debido a que si admite espacios a la hora de leer
    gets(opcion);
    // Mandamos a llamar a la funcion casos
    casos(opcion);
}
