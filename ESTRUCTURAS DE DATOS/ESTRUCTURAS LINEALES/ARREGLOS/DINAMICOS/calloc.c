#include <stdio.h>
#include <stdlib.h>

// CALLOC

/* El método "calloc" o "asignación contigua" en C se utiliza para asignar
   dinámicamente el número especificado de bloques de memoria del tipo es-
   pecificado. Es muy similar a malloc() pero tiene dos puntos diferentes
   que son:
   - Inicializa cada bloque con un valor predeterminado '0'
   - Tiene dos parámetros o argumentos en comparación con malloc()

   Sintaxis:
   (cast-type*)calloc(n,element-size);

   Ejemplo:
   char *ptr=(char*)calloc(20,sizeof(char))                  */

int main()
{
    // Declaramos las variables y nuestro puntero a entero
    int n = 10, i, *ptr;
    // Asignamos el tamaño de memoria para ptr
    ptr = (int *)calloc(n, sizeof(int));

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