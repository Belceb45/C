#include <stdio.h>
// Arreglos:
/*Los arreglos son una estructura de datos
  Son una colección infinita, homogénea y ordenada
  de elementos.*/
/*Todo arreglo es un puntero, pero no todo puntero es 
un arreglo*/

/*Al hacer un arreglo estás haciendo lo siguiente:
  1.-Reservando memoria
  2.-Creando un puntero
  3.-Asignación del puntero
  Por ejemplo: a[5]=*(a+5)*/


int main()
{
    // Se crea un arreglo de n elmentos
    int i, n;
    printf("Ingresa el tamaño de tu arreglo: ");
    scanf("%i", &n);
    int array[n];

    // Se inicializa la variable de incremento en 0
    //Y la condición va más allá del tamaño de el arreglo
    for (i = 0; i < n; i++)
    {
    array[i] = i * 2;
    }
    //En la condición de le suma un 1 para desreferenciar
    //Estamos accediento a una pocisión de memoria de la cual
    //no tenemos control
    for (i = 0; i < n; i++)
    {
        printf("array[%d]=%d\n", i, array[i]);
    }
    array[6] = 101;
    
} 