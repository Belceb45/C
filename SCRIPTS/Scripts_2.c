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
        //fflush sirve para limpiar el buffer de informacion
        fflush(stdin);

        printf("Leer los datos:\n");

        printf("Ingrese el nombre:\n");
        gets(person.name);

        printf("Ingrese el apellido:\n");
        gets(person.lastName);

        printf("Ingrese la edad:\n");
        scanf("%i", &person.age);

        printf("Imprimir datos:\n");
        printf("%s %s %i\n", person.name, person.lastName, person.age);

        fwrite(&person,sizeof(person),1,archivo);
        fclose(archivo);

    }else{
        printf("No se ha podido crear el archivo");
    }

    return 0;
}