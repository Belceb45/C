#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // se usa (rand()) para generar un número aleatorio
    // entre 0 y RAND_MAX.
    /* RAND_MAX es un número entero definido en stdlib.h
       que está relacionado con el sistema*/



    // (srand) pertenece a la libreria stdlib
    /*Cambia el valor de la semilla. La semilla es
      la secuencia de número pseudoaleatoria provista por
      el sistema.
      De este modo el parametro para la semilla puede ser
      por ejemplo time.*/
    
    int rad=0;
    // %x se usa para valores Hexadecimales, en este caso el de RAND_MAX
    printf("\nRAND_MAX=0x%x",RAND_MAX);
    //Mostramos el valor del tiempo en el momento en que se ejecuta
    printf("\n\ntime(0)=%i\n",(int)time(0));
    srand(time(NULL));
    //Generar 15 números aleatorios
    // Numero_minimo_valores + rand() % Numero_maximo_valores
    for (int i = 0; i < 15; i++)
    {
        printf("\nValor[%i]: %d",i,1+rand()%100);
    }
    





}