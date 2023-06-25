#include <stdio.h>
#include <string.h>
void funcion(char *cadena);

int main(int argc, char *argv[])
{
    if (argc > 1)         // Validar paso de parámetros del usuario
        funcion(argv[1]); // Llama a funcion y le envía parámetros del usuario

    printf("Entrada estandar menor o igual a 8 caracteres\n");
}

void funcion(char *cadena)
{
    char buffer1[8];         // Genera buffer con espacio para 8 caracteres
    strcpy(buffer1, cadena); // Copia al buffer la entrada de usuario
}