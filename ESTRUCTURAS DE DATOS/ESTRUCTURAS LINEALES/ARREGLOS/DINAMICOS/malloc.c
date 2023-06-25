#include <stdio.h>
#include <stdlib.h>

// MALLOC

/* El método "calloc" o "asignación contigua" en C se utiliza para asignar
   dinámicamente un único bloque grande de memoria con el tamaño especificado.
   Devuelve un puntero de tipo void que se puede convertir de cualquier forma.
   No inicializa la memoria en el momento de la ejecución, por lo que inicial-
   -mente inicializa cada bloque con el valor de basura predeterminado
   
   Sintaxis:
   (cast-type*) malloc(bytes-size);

   Ejemplo:

   char *ptr=(char*)malloc(100*size(char))
   
   --Dado que el tamaño por char es de 1 Byte, está declaración asignará 100
     bytes de memoria. Y el puntero prt contiene la dirección del primer byte
     en la memoria asignada                */

int main()
{
    // Declaramos las variables y nuestro puntero a entero
    int n = 10, i, *ptr;
    // Asignamos el tamaño de memoria para ptr
    ptr = (int *)malloc(n*sizeof(int));

    if (ptr == NULL)
    {
        printf("Memoria no asignada");
        /* exit(): finaliza todo el programa desde donde lo llames.
                   Esto después de vacíar los búferes de stdio, etc.*/
        exit(0);
    }
    else
    {
        // Si la memoria ha sido asignada

        for (i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
            printf("%i ", ptr[i]);
        }
    }
}