#include <stdio.h>

// Alias de tipos de datos
/* Mediante (typedef) podemos definir un alias para
un tipo de dato existente:*/

typedef int entero;

int main()
{
    entero edad1 = 12, edad2 = 17, edad3 = 11, edad4 = 18;
    printf("Las edades son:\nedad1=%i\nedad2=%i\nedad3=%i\nedad4=%i",edad1,edad2,edad3,edad4);
}
