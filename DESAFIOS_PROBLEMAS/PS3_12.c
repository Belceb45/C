#include <stdio.h>

/*Realizar un programa que calcule todos los numeros
  primos anteriores a n*/

int main()
{
    int i, n, a, primo, contador = 0;
    printf("Ingresa el numero hasta donde se hara: ");
    scanf("%i", &n);
    printf("Ingresa el numero inicial: ");
    scanf("%i",&a);

    for (i = a; i <= n; i++)
    {
        primo = 1;
        contador = 2;

        while (contador <= i / 2 && primo)
        {
            if (i % contador == 0)
                primo = 0;

            contador++;
        }

        if (primo)
            printf("%d ", i);
    }
}