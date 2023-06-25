#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Reto: Variables locales y globales
char nombre[50];
int calificacion;

void aprovacion(){
    if (calificacion>=7)
    {
        printf("El alumno %s ha aprovado la materia con %i",nombre,calificacion);
    }

}
int main(){
    printf("Ingresa tu nombre: ");
    //Lee la los caracteres aunque tenga espacios
    gets(nombre);
    printf("Ingresa tu calificacion: ");
    scanf("%i",&calificacion);
    //Mandamos a llamar a la funcion calificacion
    aprovacion(calificacion);
}
