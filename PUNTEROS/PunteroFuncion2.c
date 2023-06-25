#include <stdio.h>
#include <stdlib.h>

//Prototipos
float suma(float, float);
float resta(float, float);
float mult(float, float);
float divide(float, float);

//Punteros a función a través de arreglos

int main(void)
{
    float (*operaciones[4])(float, float) = {suma, resta, mult, divide};

    char op[] = {'+', '-', 'x', '/'};
    float a = 45, b = 12, c;

    printf("\nOperaciones\n");

    for (int i = 0; i < 4; i++)
    {
        c = operaciones[i](a, b);
        printf(" %.0f  %c  %.0f= %6.2f\n", a, op[i], b, c);
    }
    return 0;
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
