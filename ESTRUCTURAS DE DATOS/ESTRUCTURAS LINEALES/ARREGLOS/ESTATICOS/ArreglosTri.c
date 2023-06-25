#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Arreglos tridimensionales:

int main()
{
    long int /*X y Y son del arreglo*/ x = 0, y = 0, z = 0, /*a, b y c son de la serie fibonacci*/ a = 0, b = 1, c;
    char condicion[10] = "Si";
    // stricmp no diferencia las mayúsculas a diferencia de strcmp que si lo hace
    while (stricmp(condicion, "Si") == 0)
    {

        printf("\nArreglo bidimensional");
        printf("\nIngresa la longitud de las filas: ");
        scanf("%ld", &x);
        printf("Ingresa la longitud de las columnas: ");
        scanf("%ld", &y);
        printf("Ingresa la longitud de los planos: ");
        scanf("%ld", &z);

        long int array[x][y][z];
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    c = a + b;
                    a = b;
                    b = c;
                    array[i][j][k] = c;
                }
            }
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    printf("(%i, %i, %i): %ld \n", i, j, k, array[i][j][k]);
                }
            }
        }
        printf("\nQue valor desea buscar [x]? :");
        scanf("%i", &x);
        printf("\nQue valor desea buscar? [y]:");
        scanf("%i", &y);
        printf("\nQue valor desea buscar? [z]:");
        scanf("%i", &z);
        printf("\nEl valor de la posicion [%d][%d][%d] es = %ld",x,y,z, array[x][y][z]);
        printf("\n¿Desea volver a intentar?: ");
        scanf("%10s", &condicion);
    }
}
