#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Reto 1:Calcular la potencia de un numero
1.- Ingresar un valor base
2.- Ingresar un valor de exponente
3.- Dento de una funcion calcular el exponente del numero de base
4.- Imprimir el resultado */

int potencia(int a, int b){
    
    int resultado=1;
    
    for (int i = 0; i<a; i++)
    {
        resultado*=b;
    }
    return resultado;
}
int main(){
    int a,b;
    printf("Ingresa el valor de la base: ");
    scanf("%i",&b);
    printf("Ingresa el valor del exponente: ");
    scanf("%i",&a);
    printf("El resultado es: %i",potencia(a,b));
}

