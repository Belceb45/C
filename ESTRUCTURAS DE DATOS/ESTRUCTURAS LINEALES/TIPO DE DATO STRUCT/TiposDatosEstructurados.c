#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Tipos de datos estructurados
int main(int argc, const char *argv[])
{
    // Struct nos permite definir un tipo de dato estructurado
    struct
    {
        char name[100];
        int age;
    } person1;
    if (argc < 3)
    {
        printf("Indique nombre y edad por favor\n");
        // Usamos un return para terminar el programa aquí
        return 1;
        
    }
    /*Si la longitud de argv es menor a 100
      el contenido de (argv) se copia en la variable (name)*/
    if (strlen(argv[1]) < 100)
    {
        strcpy(person1.name, argv[1]);
    }
    /*La función atoi se usa para convertir una cadena de 
      texto en un entero*/
    person1.age = atoi(argv[2]);
    printf("Name = %s, age = %d", person1.name, person1.age);
    return 0;
}