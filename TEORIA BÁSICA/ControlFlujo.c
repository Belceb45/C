#include <stdio.h>
// Estructuras de control
// Concionales y Repetitivas:
// Repetitivas:
//   if, switch

// Ejemplo
int main()
{
    int a = 1;
    if (a == 1)
    {
        a = 2;
    }
    else
    {
        a = 3;
    }
    printf("El valor de a es: %i", a);
}

int two()
{
    int b = 1;
    switch (b)
    {
    case 1:
        b = 2;
        break;
    case 2:
        b = 3;
        break;
    }
    printf("El valor de b es: %i",b);
}