#include<stdio.h>
#include<stdlib.h>

/*Solo se admite el retorno de un entero a puntero, no se pueden
  retornar arreglos*/
int muestra(int p[][0], int t,int f,int c,int *suma);

int main()
{   
    int f,c,suma=0;
    printf("Numero de filas: ");
    scanf("%i",&f);
    printf("Numero de columnas: ");
    scanf("%i",&c);
    int m[f][c];
    int t = sizeof(m) / sizeof(int);
    printf("Capacidad de la matriz: %i",t);
    muestra(m,t,f,c,&suma);
    printf("\nLa suma es: %i",suma);
    return 0;
}

int muestra(int p[][0], int t,int f,int c,int *suma){
    printf("\n");
    int i,j;
    for ( i = 0; i <f; i++)
    {
        for ( j = 0; j < c; j++)
        {
            p[i][j]=1+rand()%t;
            printf("\narray[%i][%i]=%i",i,j,p[i][j]);
            *suma+=p[i][j];
        }
        
    }
    // printf("\nSuma de todos los valores: %i",suma);
    // return suma;
}