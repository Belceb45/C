#include <stdio.h>
#include <string.h>

int main()
{

    char condicion[5];
    float numero1, numero2;
    int a,b,c,r;
    printf("Que reto deseas ejecutar?\nR:");
    gets(condicion);
    if (stricmp(condicion, "Reto 4") == 0)
    {
        printf("Ingresa un numero\nR:");
        scanf("%f", &numero1);
        printf("Ingresa otro numero\nR:");
        scanf("%f", &numero2);
        printf("%3f+%3f=%.3f", numero1, numero2, numero1 + numero2);
    }
    else if (stricmp(condicion, "Reto 5") == 0)
    {
        printf("Ingresa un numero\nR:");
        scanf("%i", &a);
        printf("Ingresa otro numero\nR:");
        scanf("%i", &b);
        printf("Ingresa otro numero\nR:");
        scanf("%i", &c);
        r=a+b;
        r=r*c;
        printf("%i",r);
    }
    else
        printf("Ingrese una opcion valida");
    
}