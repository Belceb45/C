#include <stdio.h>
#include <stdlib.h>

/* Un numero perfecto es un numero entero positivo que es
igual a la suma de sus divisores propios positivos. Dicho de
otra forma, un número perfecto es aquel que es amigo de sí
mismo. */

int main()
{
    int num, suma = 0, i, c = 0;
    printf("Ingrese un numero: ");
    scanf("%i", &num);

    for (i = 1; i <= num; i++)
    {
        int j;
        for (j = 1; j <= (i / 2); j++)
        {
            if (i % j == 0)
            {
                suma += j;
            }
            j += 1;
            if (suma == i)
            {
                printf("%i Es un numero perfecto", i);
                c += 1;
            }
            i += 1;
        }
    }
    printf("%i Valor: ", i);
}