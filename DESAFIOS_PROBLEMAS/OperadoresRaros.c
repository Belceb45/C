#include<stdio.h>
//Operador Ternario
int main(){
    //Declaramos la variable
    int x;
    //Ordenamos que ingrese un numero
    printf("Ingresa un numero: ");
    //Asignamos el dato en la variable x
    scanf("%i",&x);
    //Hacemos la impresion de la operacion ternaria
    /*Si la condicional es verdadera, o sea x menor a 10
    entonces sale un 1, y si es mayor sale un 2    */
    printf("%s",x<10 ? "Hola":"2");

}