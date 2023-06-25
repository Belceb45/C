#include<stdio.h>

int main(){

    //While: Se usa cuando no sabemos cuantas veces se va a repetir
        // int n=1, acum=10;
        // while (acum<10)
        // {
        //     acum =+n;
        //     n++;

        // }
        // return acum;

    //Do while: No necesita revisar la condición antes para entrar al cilco
    // int n=1, acum=10;
    // do
    // {
    //     acum+=n;
    //     n++;
    // } while (acum<10);

    // return acum;

    //For: Se usa cuando sabemos de ante mano el numero de veces que se va a repetir
    int i,acum=0;
    //La i o el principio es la condición de inicio
    //Luego la condición de continuación
    //Y por último la condición de incremento
    for ( i = 0; i < 10; i++)
    {
       acum+=i;
    }
    return acum;

}