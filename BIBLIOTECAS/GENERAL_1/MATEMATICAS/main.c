#include <stdio.h>
#include <time.h>
#include "memory.h"
#include "math2.h"

int main()
{
    // srand(time(NULL));
    double **A, **B, **C = NULL;
    int filasA = 3, columnasA=3, filasB = 2, columnasB = 2;
    // Memoria A
    A=matzz_D(filasA,columnasB);
    
    for (int i = 0; i < filasA; i++)
    {
        for (int j = 0; j < columnasA; j++)
        {
            *(*(A + i) + j) = 1+rand()%50;
            
        }
    }

    // Memoria B
    B =matzz_D(filasB,columnasB);

    for (int i = 0; i < filasB; i++)
    {
        for (int j = 0; j < columnasB; j++)
        {
            *(*(B + i) + j) = 1+rand()%50;
            
        }
    }
    // C=rest_mtz(A,B,filasA,columnasA);
 
    //Mostrar las dos
    printf("\nMATRIZ A\n");
    for (int i = 0; i < filasA; i++)
    {
        for (int j = 0; j < columnasA; j++)
        {
            printf("\nA[%i][%i]: %f",i,j,*(*(A + i) + j));
        }
    }
    printf("\n\nMATRIZ B\n");
    for (int i = 0; i < filasB; i++)
    {
        for (int j = 0; j < columnasB; j++)
        {
            printf("\nB[%i][%i]: %f",i,j,*(*(B + i) + j));
        }
    }
    float det=det_mtz(A,filasA);
    printf("\n\nDET A: %f\n",det);
    det=det_mtz(B,filasB);
    printf("\nDET B: %f\n",det);
    // printf("\n\nMATRIZ C\n");
    // for (int i = 0; i < filasA; i++)
    // {
    //     for (int j = 0; j < columnasB; j++)
    //     {
    //         printf("\nC[%i][%i]: %i",i,j,*(*(C + i) + j));
    //     }
    // }
    

}