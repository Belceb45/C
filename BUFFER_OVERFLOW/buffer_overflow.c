#include <stdio.h>
#include <string.h>

// Problema del buffer overflow

int main(int argc, const char *argv[])
{
    // Al momento de ejecutar tenemos que fabricar la cadena
    char buffer[10];
    char *buffer2 = "This will be overwritten";
    
    printf("Original buffer2: %s\n",buffer2);

    //Copia el parametro en terminal que pusiste al ejecutar a la variable buffer[20]
    strcpy(buffer, argv[1]);
    printf("New buffer2: %s\n", buffer);
    
    return 0;
}