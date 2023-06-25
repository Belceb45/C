#include <stdio.h>
#include <string.h>

int main()
{
    
    // Como saber si dos strings son iguales
    // Esta es una forma:
    char *str1 = "Diego";
    char *str2 = "Diego";
    //Se usa strlen para devolver el número de carácteres de la cadena
    if (strlen(str1) == strlen(str2))
    {
        printf("Son iguales xd");
    }
    else
    {
        printf("No son iguales");
    }

    // Esta es otra forma de hacerlo:
    // Usando al operador ternario
    char *str3 = "Diego";
    char *str4 = "Mauricio";
    printf("%s", strlen(str3) == strlen(str4) ? "\nIguales" : "\nNo son iguales");

    // Otra forma de hacerlo es llamando a la función;
    /* strcmp, esta función las compara carácter a carácter usando en realidad comparaciones con
               su valor en código ASCII*/
    char *str5 = "Diego";
    char *str6 = "diego";
    //Esta sentencia "?"" sirve como una condicional o if.
    printf("\nLos nombres son %s\n", strcmp(str5, str6) == 0 ? "Iguales" : "Diferentes");
}