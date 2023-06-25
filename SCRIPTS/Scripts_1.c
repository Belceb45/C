#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Archivos! Crear un archivo\n");
    FILE *archivo;
    /* fopen devuelve un puntero de tipo FILE*/
    // w abre el arcivo en modo binario para escritura 
    archivo=fopen("PRUEBA1.dat","w");
    //NULL (Puntero nulo)
    if(archivo!=NULL){
        printf("El archivo se ha creado exitosamente, comprobar en la carpeta");
        //Se usa fclose para cerrar el archivo creado
        fclose(archivo);
    }else{
        printf("El archivo no se ha creado");
    }

    
    
    return 0;
}