#include <stdio.h>
#include <stdlib.h>

// Free

/* El método "free()" se usa para dinámicamentre de-asignar la memoria. La
   memoria asignada mediante las funciones malloc() y calloc() no se desa-
   -signan por sí solas. Por lo tanto, se utiliza el método free(), siempre
   que tenga lugar la asignación de memoria dinámica. Ayuda a reducir el
   desperdicio de memoria si se libera

   Sintaxis:
   free(ptr);
*/

int main()
{
    // Declaramos las variables y nuestro puntero a entero
    int n = 10, i, *ptr,*ptr1;
    // Asignamos el tamaño de memoria para ptr
    ptr = (int *)malloc(n*sizeof(int));
    ptr1 = (int *)calloc(n,sizeof(int));

    if (ptr == NULL||ptr1 == NULL)
    {
        printf("\nMemoria no asignada");
        /* exit(): finaliza todo el programa desde donde lo llames.
                   Esto después de vacíar los búferes de stdio, etc.*/
        exit(0);
    }
    else
    {
        printf("\nMemoria asignada");
        free(ptr);
        free(ptr1);
        printf("\nMEMORIA LIBERADA")
        
        
        
    }
    return 0;
}