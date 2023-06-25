#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Hacer un programa que imprima la suma de todos los
numeros pares que hay desde 1 hasta n, y que digas
cuantos numeros hay*/
int main()
{
    int a = 0, b = 0, n, i;
    printf("Ingresa el numero: ");
    scanf("%i", &n);
    for (i = 2; i <= n; i ++)
    {
        if (i % 2 == 0)
        {
            printf("%i",i);
            a=a+i;
        }
        printf("\nLa suma es: %i", a);
        printf("\nLa cantidad de numeros son: %i", i/2);
    }
    return 0;
}