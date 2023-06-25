#include <stdio.h>
#include <stdlib.h>

// Punteros a una función
/* SINTAXIS

    <Tipo de dato devuelto>(*identificador)(lista de parametros);

    Ejemplo
    int(*operacion)(int,int);
*/
float suma(float);

int main(int argc, char *argv[])
{

    float (*ptr)(float);
    float x = 2.5, x1, x2 = 5.2;

    x1 = suma(x);
    printf("\nResultado de suma 1 de %0f: %2f", x, x1);

    ptr = suma;
    x2 = ptr(x);
    printf("\nResultado de suma 2 de %0f: %2f", x, x2);
    return 0;
}

float suma(float x)
{
    return x + 10 * 2;
}