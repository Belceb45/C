#include <stdlib.h>
#include <stdio.h>
//Como recibir información desde el S.O
/*  argc: Es de tipo int y contiene el numero que se 
          pasa al ejecutar el programa
    argv: Su variable es de tipo array, contiene array
          de punteros y caracteres*/
int main(int argc,char *argv[]){
    
    char argv1=0;
    for (int i = 0; i < argc; i++)
    {
        printf("Argumento %i = %s\n",i,argv[i]);
        

    }
    
} 
