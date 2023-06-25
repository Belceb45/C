#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Arreglos Bidimensionales:
/*Los arreglos son también llamados tablas o matrices*/
/*Tienen dos índices: el primero indica el número de fila
  y el segundo el número de columna en que se encuentra
  el elemento*/

/*Declarar un arreglo bidimensional
  1.-Indicamos: Tipo de dato, nombre, filas y columnas
  Por ejemplo; Data_type name [size_fila][size_columna]*/

int main()
{
    long int  /*X y Y son del arreglo*/x=0,y=0,/*a, b y c son de la serie fibonacci*/a=0,b=1,c;

    
    printf("Arreglo bidimensional");
    printf("\nIngresa la longitud de las filas: ");
    scanf("%i",&x);
    printf("Ingresa la longitud de las columnas: \n");
    scanf("%i",&y);

    int array[x][y];
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        printf("Dato[%i][%i]:",i,j);
        scanf("%d",&array[i][j]);
      }
       
    }
    printf("\n");
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        printf("(%i, %i): %d \n",i,j,array[i][j]);
      }
       
    }
    
}
