#include <stdio.h>

// Void quiere decir que la función no va a devolver nada
void duplicar(int /*Puntro hacía a*/ *a)
{
    /* a es una variable local que solo está definida en
    esta función*/
    *a *= 2;
}
/*Estamos modificando solamente una copia de la variable a
Esto se arregla pasando el contenido de la dirección de la
variable a*/
int main()
{
    int a = 5;
    printf("Antes de duplicar a = %i\n", a);
    duplicar(/*Dirección de a*/ &a);
    printf("Despues de duplicar a = %i\n", a);
    /*A lo que hicimos anteriormente se le conoce como pasaje
    por referencia, y se hace con punteros en C.
    Con esto lo que esta pasando es que en lugar de pasarle una
    copia de la variable (a), que existe dentro de la funcion
    main, le estamos pasando su direccion y la funcion duplicar
    ,esta señalando su direccion a la que tiene su valor y lo
    que hace es multiplicarla.*/
}