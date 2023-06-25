#include<stdio.h>
#include<stdlib.h>

/*
void memoria(int ***matriz, int filas, int columnas)
{
    (matriz) = (int *)malloc(filas * sizeof(int *));
    (*matriz)[0]= (int *)malloc(columnas * sizeof(int));
    for (int i =1; i < filas; i++)
    {
       (*matriz)[i]= (int *)malloc(columnas * sizeof(int));
    }
   
}

int main(int argc, char *argv[])
{
	int **gmatriz;
	memoria(&gmatriz,3,3);
	gmatriz[0][0]=2;
	
	printf("Valor: %d",gmatriz[0][0]);
	
}
//
int main(int argc, char *argv[])
{
    int **matriz, num = 2;
    memoria_m(&matriz, num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            matriz[i][j] = 2;
            printf("\n[%i][%i]= %i", i, j, matriz[i][j]);
        }
    }
    matriz[1][1] = 5;
    printf("\n%i",matriz[1][1]);
}
// Memoria
void memoria_m(int ***matriz, int num)
{
    *matriz = (int **)malloc(num * sizeof(int *));
    for (int i = 1; i < num; i++)
        (*matriz)[i] = (*matriz)[i - 1] + ((num) + 1);
    // for (int i = 0; i < 2; i++)
    // {
    //     *matriz[i]=(int*)malloc(2*sizeof(int));
    // }
}
*/