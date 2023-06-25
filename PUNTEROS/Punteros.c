#include<stdio.h>
//Puntero:
/*El puntero es una variable que puede contener numeros
pero solamente puede contener numeros que correspondan a
una dirección de memoria*/

int main(){
    
    int number=109;
    /*Usamos * para decir que la variable no es 
    un entero, más bien un puntero a una variable de tipo 
    entero*/
    int *pointToNumber=&number;
    // %p: operador para punteros
    printf("%p,%i\n",pointToNumber,*pointToNumber);



}
