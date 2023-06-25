#include <stdio.h>
#include <stdlib.h>

// Funciones con arreglos
void funcion(int n)
{
    int i,contador=0;
    int matriz[n];
    for (i = 0; i < n; i++)
    {
        matriz[i] = 1 + rand() % 10;
        printf("\narray[%i]=%i", i, matriz[i]);
    }
    int resultado;
    for (i = 0; i < n; i++)
    {
        resultado=(matriz[i] * matriz[i]);
        contador+=resultado;
        // printf("\narray[%i]=%i", i, matriz[i]);
        }
    printf("\nLa suma de los cuadrados es: %i",contador);
}

int main()
{

    int n;
    printf("Ingresa la longitud de tu arreglo: ");
    scanf("%i", &n);
    funcion(n);
    return 0;
}
