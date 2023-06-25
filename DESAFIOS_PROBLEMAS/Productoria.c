#include <stdio.h>
/*Productoria: multiplicacion de una cantidad
arbitraria de elementos*/
int main()
{
    int n, condicion, productoria, i;
    condicion = 1;
    while (condicion == 1)
    {
        printf("Ingresa el numero maximo: ");
        scanf("%i", &n);
        if (n > 0)
        {
            productoria = 1;
            for (i = 1; i <= n; i++)
            {
                productoria = productoria * i;
            }
            printf("El resultado es: %i", productoria);
            condicion=0;
        }
    }
}
