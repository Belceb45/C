#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Realizar un programa que reciba cadenas de caracteres
  por la linea de comandos y emita la cadena más larga*/

int main(int argc,char *argv[])
{
  char  *comparacion="";
  

  for (int i = 1; i < argc; i++)
  {
    printf("Argumento %i = %s\n",i,argv[i]);
    if ( strlen(argv[i]) > strlen(argv[1]))
    {
      comparacion=argv[i];
    }
    
  }
  printf("El argumento mas grande es: %s\n",comparacion);

}
