#include <stdio.h>
/*Aquí se genera un problema al momento de imprimir
el array*/
int main(){
    /*Se soluciona el problema tomando en cuenta el caracter
    /0*/
    char name[17]=/*El string tiene 16 caracteres */"Diego Rubio Haro";
    printf("Mi nombre es %s",name);
    return 0;
}