#include <stdio.h>
#include <string.h>
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

  // // Arreglo de numeros enteros
  int n;
  // int arreglo_numeros[5];
  // arreglo_numeros[0] = 2;
  // arreglo_numeros[1] = 4;
  // arreglo_numeros[2] = 6;
  // arreglo_numeros[3] = 8;
  // arreglo_numeros[4] = 10;
  // printf("Elige la posicion que quieres ver (Es un arreglo de 5)\n N= ");
  // scanf("%d", &n);
  // if (n < 5 && n>=0)
  // {
  //   printf("El valor de la posicion [%d] es = %i", n, arreglo_numeros[n]);
  // }

  //Arreglos de caracteres (strings)
  //No olvidarse del caracter de limite '\0'
  char arreglo_letras[6];

  /*1*/arreglo_letras[0]='D';
  /*2*/arreglo_letras[1]='I';
  /*3*/arreglo_letras[2]='E';
  /*4*/arreglo_letras[3]='G';
  /*5*/arreglo_letras[4]='O';
  /*Caracter que delimita el final de la cadena, se debe de
    considerar, ya que ocupa un espacio de memoria 
    del arreglo*/
  /*6*/arreglo_letras[5]='\0';
  printf("%s",arreglo_letras);
  printf("\nPosicion 1 = '%c'",arreglo_letras[1]);
  
  


}