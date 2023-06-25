#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cambio(int *p,int n);
int main()
{
    int n, i;
    char condicion[5];
    printf("ingresa el tama%co del arreglo: ", 164);
    scanf("%i", &n);
    int *matriz = (int *)malloc(n * sizeof(int));
    printf("\nLongitud de memoria: %i bytes",(n*sizeof(int)));
    for (i = 0; i < n; i++)
    {
        matriz[i] = 1 + rand() % 50;
        printf("\narray[%i]=%i", i, matriz[i]);
    }
    printf("\n\n%cDesea cambiar el tama%co del arreglo?: ",168,164);
    scanf("%s", &condicion);
    if (stricmp(condicion, "si") == 0)
    {
        cambio(matriz,n);
    }
    else if (stricmp(condicion, "no") == 0)
    {
    }
    else
    {
        printf("Ingresa una opcion valida");
    }

    free(matriz);
    return 0;
}

void cambio(int *p,int n){
    int a;
    printf("\nFuncion cambio\n");
    printf("Ingresa el nuevo tama%co: ",164);
    scanf("%i",&a);
    if (a>n)
    {
        
    }
    
    printf("Longitud de memoria: %i",longitud);
    // p=(int*)realloc();
    // for (int i = 0; i < n; i++)
    // {
    //     printf("\narray[%i]=%i",i,p[i]);
    // }
    
    
}