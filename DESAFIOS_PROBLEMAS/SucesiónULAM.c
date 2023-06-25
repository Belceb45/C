#include <stdio.h>
#include <stdlib.h>

/*Este es el algoritmo de ULAM
  Consiste en:
  Si el inicial es par, dividirlo entre2
  Si es impar multiplicarlo por 3 e incrementarlo en 1.
  Repetir el proceso hasta que la sucesion llegue a 1 */

void main()
{
    int x, condicion;
    condicion = 0;
    while (condicion == 0)
    {

        printf("\nDigite un numero: ");
        scanf("%i", &x);
        while (x != 1)
        {
            if (x > 1)
            {
                if (x % 2 == 0)
                {
                    x = x / 2;
                    printf("%i,", x);
                    

                }
                else
                {
                    x = x * 3 + 1;
                    printf("%i,", x);
                }
            }

            else
            {
                printf("No son posibles los numeros negativos.\n¿Desea volver a intentarlo?");
                scanf("%i", &condicion);
            }

        }
        printf("\n¿Desea continuar?: ");
        scanf("%i", &condicion);
    }
}