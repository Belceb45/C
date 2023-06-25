#include<stdio.h>
/*Rutina: Conjuntos de instrucciones que se ejecutan 
con cierta periodicidad*/
/*Rutinas;
  Procedimiento--- o ---Rutinas  (En C solo hay Función)*/

/*Definición de funciones:
 -Valor retornado
 -Nombre
 -Lista de argumentos
 -Conjunto de instrucciones */

/*Existen 3 tipos de variables en las funciones:
  1.- Locales
  2.- Globales
  3.- Estáticas*/

/*La funcion regresará un dato entero*/int /*Nombre de la funcion*/f/*Declarar argumentos*/(int a){
    return (a+2*3);
}

int main(){
    //Duelve un número entero
    return f(2);

}