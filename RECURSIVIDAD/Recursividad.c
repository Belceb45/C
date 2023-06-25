#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursividad
/*--La recursividad es el proceso de definir algo en términos
    de sí mismo y a veces se llama definición circular

  --Un método recursivo es un método que se llama así mismo

Reglas: Recursividad
1.- Tener al menos una condicion de corte
2.- Al menos una llamada recursiva
3.- En cada llamada recursiva, se produce un acercamiento a la condicion de corte*/
int factorial(int n)
{
    printf("Entra a la funcion factorial (n vale: %i)\n", n);
    if (n>1)
    {
        printf("\nLa funcion se llamara asi misma otra vez\n");
        return n*factorial(n-1);
    }else{
        printf("n es igual a 1 o menos, termina la recursividad\n");
        return 1;
    }
    
}

int main()
{
    printf("Recursividad\n");
    int result=/*Llamamos a la funcion factorial con el numero 5 como parametro*/factorial(5);
    printf("\nEl resultado es: %i",result);
    return 0;
}
