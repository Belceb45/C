
#include <stdio.h>
#include <stdlib.h>

/*Solo se admite el retorno de un entero a puntero, no se pueden
  retornar arreglos*/
void muestra(int *p, int t);

int main()
{

    int a[] = {1, 2, 3, 4, 45, 67, 5, 4};
    int t = sizeof(a) / sizeof(int);
    muestra(a,t);
    return 0;
}

void muestra(int *p, int t){
    printf("\n");
    int i;
    for ( i = 0; i <t; i++)
    {
        printf("\narray[%i]=%i",i,p[i]);
    }
    

}