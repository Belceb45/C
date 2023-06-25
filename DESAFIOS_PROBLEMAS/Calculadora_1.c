#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculadora
int main()
{ 
    float var1, var2, result;
    char cadena[8];
    int condicion;
    condicion=1;
    printf("Hola, Esta es una calculadora sencilla de las operaciones basicas\n Deberas ingresar los numeros que quieras");
    // strcmp compara una cadena con otra, y regresa 0 si son iguales.
    // Para usarla en el if negamos la expresion
    while (condicion==1)
    {
        printf("Ingresa la operacion que desea hacer:\n ");

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
        else if (!strcmp(cadena, "resta"))
        {
            printf("\nIngrese un numero: ");
            scanf("%f", &var1);
            printf("\nIngrese otro numero: ");
            scanf("%f", &var2);
            result = var1 - var2;
            printf("\nEl resultado es:%f ", result);
        }

        else if (!strcmp(cadena, "multiplicacion"))
        {
            printf("\nIngrese un numero: ");
            scanf("%f", &var1);
            printf("\nIngrese otro numero: ");
            scanf("%f", &var2);
            result = var1 * var2;
            printf("\nEl resultado es:%f ", result);
        }
        else if (!strcmp(cadena, "division"))
        {
            printf("\nIngrese un numero: ");
            scanf("%f", &var1);
            printf("\nIngrese otro numero: ");
            scanf("%f", &var2);
            if (var2 != 0)
            {
                result = var1 / var2;
                printf("\nEl resultado es: %f", result);
            }
            else
            {
                printf("La division entre cero no es valida");
            }
        }
            
        
    }

    return 0;
}