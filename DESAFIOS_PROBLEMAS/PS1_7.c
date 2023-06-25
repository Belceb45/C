#include <stdio.h>

int main()
{

    char cadena[8];
    int condicion;
    condicion = 1;
    // Impresora de Caracteres
    while (condicion == 1)
    {
        printf("Ingresa la palabra que quieras imprimir");
        scanf("%s", cadena);

        if (!strcmp(cadena, "suma"))
        {
            printf("\nIngrese un numero: ");
            scanf("%f", &var1);
            printf("\nIngrese otro numero: ");
            scanf("%f", &var2);
            result = var1 + var2;
            printf("\nEl resultado es:%f ", result);
        }
    }
}