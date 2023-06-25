#include <stdio.h>

// Control de flujo en C
/*Statement: Es simplemente una linea de codigo o un solo comando
  por ejemplo; printf("Hola mundo") es un statement*/

/*También existen los bloques de código y de statements, se identifican por tener
los corchetes o llaves*/

int main()
{
    int a = 1, b = 5;
    if (a > 0 && b > 0)
        printf("\nTus numeros son validos");
    else
        printf("Los numeros no son validos");
    printf("Si llega");
}