#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Esta es una calculadora de fibonacci
int main()
{
    int a, b, c, n, i;
    a = 0;
    b = 1;
    printf("Serie de Fibonacci");
    printf("\nIngrese el numero hasta el cual se realizara la serie de finbonacci: \n");
    scanf("\t%i", &n);
    printf("1,");
    for (i = 1; i < n ; i++)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%i,", c);
    }
}