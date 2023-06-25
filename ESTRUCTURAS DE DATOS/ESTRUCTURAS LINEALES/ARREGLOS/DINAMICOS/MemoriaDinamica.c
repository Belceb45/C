#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Platzi
// Manejo dinamico de la memoria
// Malloc y Realloc
// Realloc: Reasignar memoria
// Malloc: Asginar memoria

int main()
{
    // float *a;
    // a=malloc(sizeof(float)); //Tamaño de una variable entera
    // *a=5.45;
    // printf("%.3f",*a);

    /*Si nuestros punteros tienen el valor NULL (En este caso el vector_din y el vector_din_6_lug)
      significa que no apuntan a nada */
    void *vector_din = NULL;
    void *vector_din_10_lugares = NULL;
    int *vector_convertido = NULL;
    // Asigno el espacio de memoria para mi puntero
    // Este espacio es de 5*(El espacio de memoria que ocupa un int)
    /*Al int se le asigna un espacio de 4 bytes, entonces 5*4 bytes= 20 bytes
      de espacio asignado en 5 celdas de 4 bytes*/
    vector_din = malloc(5 * sizeof(int));
    /*Esto lo hacemos comprobando que el puntero (vector_din)
      no esté apuntando a NULL (!=NULL), puesto que ya le asignamos
      hacía a donde apuntar con malloc*/
    if (vector_din != NULL)
    {
        /*Se cumplió la condición de que no apunte a NULL, entonces
          le asignamos el valor de vector_din al vector convertido*/
        /*También le damos valores a las posiciones para que sea más
          fácil ver el cambio de memoria con realloc*/
        vector_convertido = vector_din;
        vector_convertido[0] = 12;
        vector_convertido[1] = 24;
        vector_convertido[2] = 36;
        vector_convertido[3] = 48;
        vector_convertido[4] = 60;
    }
    else
    {
        // En caso de no cumpla la condicion el vector_din
        printf("\nNo se puedo asignar la memoria");
    }
    // Reasignar a 10
    /*Reasignamos el espacio que ocupaba el vector_din a
      10, o sea, ahora ocupará 10*(int)= 10*4bytes=40 bytes en 10 celdas de 4 bytes.
      Al realloc le damos el parametro del puntero vector_din, puesto que era el que ya
      tenía asignado un espacio de memoria, y después el valor de cambio.*/
    vector_din_10_lugares = realloc(vector_din, 10 * sizeof(int));
    // Hacemos la misma comprobación de antes
    if (vector_din_10_lugares != NULL)
    {
        /*Le volvemos a asginar al puntero (vector_convertido) un valor que será el de 
        la reasignacion (vector_din_10_lugares)*/
        vector_convertido = vector_din_10_lugares;
        /*Y les asignamos valores a los que faltaban, puesto que antes solo había lugar
          para 5 valores, y ahora hay para 10
          Todo esto se hizo sin modificar los valores que ya tenía el puntero (vector_convertido del 0 al 4)*/
        vector_convertido[5] = 72;
        vector_convertido[6] = 84;
        vector_convertido[7] = 96;
        vector_convertido[8] = 108;
        vector_convertido[9] = 120;
    }
    else
    {
        printf("\nNo se puedo asignar la memoria");
    }
    //Imprimimos los valores
    printf("El nuevo vector_convertido en el [3]: %i\n", vector_convertido[3]);
    printf("El nuevo vector_convertido en el [8]: %i", vector_convertido[8]);
    free(vector_din);
    free(vector_convertido);
    free(vector_din_10_lugares);
    return 0;
}