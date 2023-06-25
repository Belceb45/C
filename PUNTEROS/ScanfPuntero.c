#include<stdio.h>

int main(int number){
    printf("Ingrese un numero: ");
    /*Se puede definir a "scanf" como un complemento
    del "printf", lee un dato y lo asocia a una dirección
    de memoria*/
    scanf("%i",&number);
    int *puntero_number=&number;
    printf("El numero ingresado fue: %p, %i",puntero_number,*puntero_number);

}