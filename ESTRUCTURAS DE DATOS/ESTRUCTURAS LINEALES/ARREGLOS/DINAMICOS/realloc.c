#include <stdio.h>
#include <stdlib.h>

// realloc

/* El método "realloc()" o reasignación en C se utiliza para cambiar dinamicamente
   la asignación de memoria de una memoria previamente asignada. Es decir, se usa
   para redimensionar el espacio de memoria que ocupa un bloque de memoria

   Sintaxis:
   ptr=realloc(ptr,newSize);
*/

int main()
{
    // Declaramos las variables y nuestro puntero a entero
    int n = 5,p=0, i, *ptr;
    // Asignamos el tamaño de memoria para ptr
    ptr = (int *)calloc(n, sizeof(int));
    
    p=n;
    if (ptr == NULL)
    {
        printf("\nMemoria no asignada");
        /* exit(): finaliza todo el programa desde donde lo llames.
                   Esto después de vacíar los búferes de stdio, etc.*/
        exit(0);
    }
    else
    {
        printf("\nArreglo de 5 elementos: \n");
        //Se le ingresan valores a ptr
        for (i = 0; i < p; i++)
        {
            ptr[i] = i + 1;
            printf("%d, ", ptr[i]);
        }
        //Se redimensiona la memoria
        n=10;
        //Se extiende su memoria a 5 bytes
        ptr=realloc(ptr,n*sizeof(int));
        printf("\nSe modifico a 10 elementos: \n");

        for (i = p; i < n; i++)
        {
            ptr[i] = i + 1;
            printf("%d, ", ptr[i]);
        }
    }
    return 0;
}