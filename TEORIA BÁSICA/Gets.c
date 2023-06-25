#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*La biblioteca estandar de nos provee las funciones para
  introducir datos a nuestros programas, estas son;
  1.- scanf:Es la más versatil debido a que puede leer
            distintos tipos de datos (cadenas,enteros,reales,etc)
            según el formato que le especifiques
  2.- gets:Solo leen las cadenas de caracteres
  3.- fgets:Solo leen las cadenas de caracteres, pero a esta
            le podemos pasar un parametro de lectura de caracteres*/

int main(){

    char name[50];
    int size;

    printf("Ingresar el nombre con gets: \n");
    //gets guarda el valor en el arreglo name
    gets(name);
    //Imprime "El nombre es:" 
    printf("El nombre es: ");
    //puts imprime todo lo que esté adentro del arreglo de caracteres
    puts(name);
    //Guardamos el valor de la longuitud del arreglo de caracteres en size
    size=strlen(name);
    printf("\nEl tamaño del string es: %i\n",size);
    size;
    //Reto: Imprimir de forma invertida los caracteres del arreglo

    for (int i = size; i>=0;i-- )
    {
        printf("%c",name[i]);
    }
    
}        