#include <stdio.h>


/*La función permutar intetna permutar los valores de 
  los argumentos que recibe como paarametros. Veremos que
  aunque la funcion modifica sus valores luego, al retornar
  al programa principal, las variables que le pasamos a la
  función mantienen sus valores originales.*/


// prototipo de la funcion permutar
void permutar(int, int);

// programa principal
int main(){
    int a = 5, b = 10;
    // muestro los valores de a y b
    printf("en main: a=%d, b=%d\n", a, b);
    // invoco a la funcion para permutar los valores de a y b
    permutar(a, b);
    // muestro los valores de a y b
    printf("en main: a=%d, b=%d\n", a, b);
    return 0;
}
void permutar(int x, int y)
{
    int aux;
    // muestro los valores de x e y
    printf("...en permutar: x=%d, y=%d\n", x, y);
    // permuto los valores de los argumentos
    aux = x;
    x = y;
    y = aux;
    // muestro los valores de x e y
    printf("...en permutar: x=%d, y=%d\n", x, y);
}