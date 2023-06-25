#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Argumentos y parametros
/*Muchas veces estos terminos se usan como sinonimos pero,
  en realidad, no lo son. Existe una diferencia sutil entre
  ellos
  --A la funcionle pasamos "argumentos"
  --La funcion "recibe parametros"*/

// Prototipo
long unificarFecha(int, int, int);
// Cabecera
long unificarFecha(int d, int m, int a)
{
    int d1,m1,al;
    // Invocacion de funcion
    int x = unificarFecha(d1, m1, al);
}

/*Podemos observar que cada argumento que le pasamos
  en la invocacion se corresponde con un parámetro de la
  funcion según su posición

  Dentro de la funcion, el parametro d toma el valor del
  argumento que le pasamos en primer lugar que, en este
  caso, es d1. El parametro m toma el valor del segundo
  argumento y el parametro a toma el valor del tercer y
  último argumento.
  Los nombres de los parametros no tienen porque coincidir
  con los nombres de los argumentos. Lo que importa es la
  posición*/
