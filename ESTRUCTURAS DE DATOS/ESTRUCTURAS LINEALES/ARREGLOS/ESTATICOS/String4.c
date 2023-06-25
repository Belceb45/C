#include<stdio.h>
#include<string.h>
//Usar una funcion de la libreria string.h para copiar strings
int main(){
    //Se usa el strcpy
    char src[9]="Mauricio";
    char dst[20]="No veras esto nunca";
    // strcpy(variable destino, string a copiar)
    strcpy(dst,src);
    printf("dst=%s\n",dst);
    
 
}