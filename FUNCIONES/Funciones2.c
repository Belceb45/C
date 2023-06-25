#include <stdio.h>

int a,b;
int suma(void){

    return (a+b);
}
void main (void){

    int resultado;
    printf("Ingresa el valor de a: ");
    scanf("%d",&a);
    printf("Ingresa el valor de b: ");
    scanf("%d",&b);
    resultado=suma();
    printf("El resultado de la suma es: %i",resultado);

}
