#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, n;
    printf("Ingresa la longitud de tu arreglo: ");
    scanf("%d", &n);
    if (n > 0)
    {

        int array[n];
        int mayor = 0;
        int menor = 1000;

        for (i = 0; i < n; i++)
        {
            printf("\nIngresa tu numero: ");
            scanf("%d", &array[i]);
            if (array[i] > mayor)
            {
                mayor = array[i];
                printf("Es mas grande que 0");
            }
            if (array[i] < menor)
            {
                menor = array[i];
                printf("\nEs menor");
            }
        }

        printf("\nEl valor mas grande es = %d", mayor);
        printf("\nEl valor mas peque es =%i", menor);
        // printf("El valor de la posicion [2]=%c y el str es =%s", array[2], array);
    }

    return 0;
}
