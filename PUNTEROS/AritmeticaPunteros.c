#include <stdlib.h>
#include <stdlib.h>

//Aritmética de punteros

/*Recapitulando; Los punteros son variables que 
contienen datos numericos adentrom sin embargo no
son lo mismo que cualquier otro numero entero, debido a
que son direcciones de memoria o identificadores de 
memoria */

// Operaciones de incremento y decremento con punteros

int main(){
    int n=5;
    int *pi=&n;
    char c='A';
    char *pc=&c;
    printf("Antes pi = %p y pc = %p\n",pi,pc); 
    pi++;
    pc++;
    printf("Despues pi = %p y pc = %p\n",pi,pc); 
    /* Hay un clara diferencia entre el cambio de pi de antes
    y despues en comparacion con la de pc que es de tipo 
    char, esto se debe a que int que es para enteros ocupa
    4 bytes, es decir que cada pocision apuntada
     por pi ocupa
    4 bytes y pc que es char solo 1 byte  */
    /* OPERACIONES CON PUNTEROS
    int *p=&n;
    int *p2=&n2;
    - p++
    - p--
    - p + n
    - p -n
    - p == NULL
    - p != NULL
    - p <R> p2
    - p = p2
    - p = void
    
    */
    /* EXPRESIONES CON PUNTEROS
    
    int *ip=&n;
    - ip+10; Crea otro puntero
    - int y=*ip+10; Añade 10 al objeto *ip (objeto referenciado por ip) y lo asigna a y
    - *ip +=1; Incrementa en 1 el valor referenciado
    - ++*ip; Al igual que el anterior incremente en 1 el valor referenciado
    - ++ip; Crea otro puntero que es igual a ip= ip+1, es decir, incremente el valor del puntero
    - ip++; Igual que el anterior
    - (*p)++; Incrementa en 1 el valor del objeto referenciado por ip
    - 

    */
}