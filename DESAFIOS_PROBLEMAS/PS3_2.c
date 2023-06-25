#include <stdio.h>

int main()
{
    // Declaramos las variables a usar
    /* n es la variable de control, la de ingresa el usuario*/
    int condicion, n, i;
    float resultado;
    resultado = 0;
    printf("Esta es una serie");
    printf("\nIngresa un numero la para la sucesion: ");
    scanf("%i", &n);
    if (n > 0)
    {
        /* Iniciamos i en 1, mientras i sea menor 
        o igual a n se repite hasta que llegue a n y que
         se incremente en 1 la i para llegar a n*/
        for (i = 1; i <= n; i++)
        {
            resultado = resultado + (1.0 / i);
        }
        printf("El resultado de la serie es: %f", resultado);
        
    }

    

    return 0;
}