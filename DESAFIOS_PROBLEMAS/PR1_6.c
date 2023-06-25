#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Formula de Herón
int main()
{
    /*Lo primero que debemos hacer es declarar las
    variables del triangulo*/
    int a, b, c, condicion;
    float area, s;
    condicion = 1;
    /*Usamos un while para volver a calcular si así lo desea el usuario*/
    while (condicion == 1)
    {
        printf("\nEsta es la calculadora de Heron");
        printf("\nIngresa el lado a: ");
        scanf("%i", &a);
        printf("Ingresa el lado b: ");
        scanf("%i", &b);
        printf("Ingresa el lado c: ");
        scanf("%i", &c);
        if (a && b && c > 0)
        {
            s = (a + b + c) / 2;
            area = sqrt(s * (s - a) * (s - b) * (s - c));
            printf("\nEl semiperimetro del triangulo es: %f", s);
            printf("\nEl area del triangulo es: %f", area);
            printf("\n¿Desea calcular de nuevo?: ");
            scanf("%i", &condicion);
        }
        else
        {
            printf("No hay longitudes negativas o con valor de cero, vuelve a intentarlo");
        }
    }

    return 0;
}