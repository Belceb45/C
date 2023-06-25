#include <stdio.h>

/*Realizar un programa en que al recibir
como datos N numeros naturales, determine
cuantos son posivitos, negativos o nulos*/

int hi()
{
  int n, i, condicion, numero, positivo, negativo, nulo;
  condicion = 1;
  while (condicion == 1)
  { 
    
    printf("\n Ingrese la cantidad de numeros: ");
    scanf("%i", &n);
    printf("\n Vas a ingresar: %i", n);
    positivo = 0;
    negativo = 0;
    nulo = 0;
    condicion = 0;
    if (1000 > n &&  n > 0)
    {
      for (i = 0; i < n; i++)
      {
        printf("\nIngresa un numero: ");
        scanf("%i", &numero);

        if (numero > 0)
        {
          positivo++;
        }
        else if (numero < 0)
        {
          negativo++;
        }
        else
        {
          nulo++;
        }
      }
      printf("\nNumero positivos: %i", positivo);
      printf("\nNumero negativo: %i", negativo);
      printf("\nNumero nulo: %i", nulo);
      printf("\n¿Desea volver a intentarlo (1-si,0-no)?: ");
      scanf("%i", &condicion);
    }
    else
    {
      
      return -1;
    }
  }
  return n;
} 


void main()
{
  int cantidad;
  cantidad = hi();
  if (cantidad==-1)
  {
    printf("\nNo se aceptan caracteres");
  }
  else{

  printf("Ingresaste estos numeros: %i", cantidad);
  }
}