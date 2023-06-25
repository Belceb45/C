#include <stdio.h>
#include <stdlib.h>

// Prototipos
float suma(float, float);
float resta(float, float);
float mult(float, float);
float divide(float, float);
float Opera(float, float, float (*)(float, float));

//Función principal
int main(int argc, char *argv[])
{
    float a=45.3,b=12.3,c;
    printf("\nOperaciones");
    c=Opera(a,b,suma);
    printf("\nLa suma de %.1f con %.1f es: %.2f",a,b,c);
    c=Opera(a,b,resta);
    printf("\nLa resta de %.1f con %.1f es: %.2f",a,b,c);
    c=Opera(a,b,mult);
    printf("\nLa multiplicacion de %.1f con %.1f es: %.2f",a,b,c);
    c=Opera(a,b,divide);
    printf("\nLa division de %.1f con %.1f es: %.2f",a,b,c);
    return 0;

    /*Ejemplos de funciones que reciben como parámetro un puntero
      a funcion:

        - void qsort(void *datos,int numElem, int tamaño, int(*p)(const void*,const void*))
           

    */
}

float Opera(float x, float y, float (*f)(float, float))
{
    //El puntero f rebice la dirección de inicio de una función
    return f(x,y);
}

float suma(float x, float y)
{
    return x + y;
}

float resta(float x, float y)
{
    return x - y;
}

float mult(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}
