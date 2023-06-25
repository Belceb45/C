#include <stdio.h>
#include <stdlib.h>
// Escritura y lectura de archivos
/*Cuenta con 4 parametros y se usa la funcion fwrite:
  fwrite(void*apuntador,size_t_tamaño,size_t_cantidad,FILE archivo);
  Estos puntos aplican para fwrite y fread:
  1.-void*apuntador: Apuntador con la direccion la informacion que estamos guardando
  2.-size_t tamaño: Tamaño de cada elemento que será escrito
  3.-size_t cantidad: El número de elementos
  4.-FILE archivo: Apuntador con la dirección al archivo donde estamos guardando/escribiendo */

struct personalData
{
    char name[20];
    char lastName[20];
    int age;
};
int main()
{

    printf("Archivos - Guardar en un archivo\n");

    struct personalData person;

    FILE *archivo;
    //fopen("Nombre del archivo","parametro") [Se usa para abrir archivos]
    archivo = fopen("DatosPersonales001.dat", "wb");
    if (archivo != NULL)
    {
        fread(&person,sizeof(person),1,archivo);
        printf("Imprimir los datos \n");
        printf("Nombre: %s \n",person.name);
        printf("Apellidos: %s \n",person.lastName);
        printf("Edad: %i \n",person.age);

        fclose(archivo);

    }else{
        printf("No se ha podido crear el archivo");
    }

    return 0;
}