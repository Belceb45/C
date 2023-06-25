#include <stdlib.h>
#include<stdio.h>

//Tipo de dato String

int main(){
    char *name = "Diego";
    // Se usa %p para mostrar la dirección de memoria que ocupa
    printf("Nombre = %s,(%p)\n",name,name);
    for (int i = 0; i < 5; i++)
    {
        //Muestra cada carácter con su posición y muestra la dirección de memoria que este ocupa
        printf("name[%i](%p)=%c\n",i,name+i,name[i]);

    }
    
    return 0;
}