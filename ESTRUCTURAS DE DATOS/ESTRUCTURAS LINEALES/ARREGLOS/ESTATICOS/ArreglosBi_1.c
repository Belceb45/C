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
    int  /*X y Y son del arreglo*/x,y,/*a, b y c son de la serie fibonacci*/a=0,b=1,c;

    
    // printf("Arreglo bidimensional");
    // printf("\nIngresa la longitud de las filas: ");
    // scanf("%ld",&x);
    // printf("Ingresa la longitud de las columnas: ");
    // scanf("%ld",&y);
    x=3;
    y=4;


    int array[x][y];
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        // c = a + b;
        // a = b;
        // b = c;
        
        array[i][j]=3;
        printf("(%i, %i): %ld \n",i,j,array[i][j]);
      }
       
    }
    // for (int i = 0; i < x; i++)
    // {
    //   for (int j = 0; j < y; j++)
    //   {
    //     printf("(%i, %i): %ld \n",i,j,array[i][j]);
    //   }
       
    // }
    
}
