#include<stdio.h>
#include"dataStructures.h"

int main(int argv, char *argc[])
{
    PilaD *p;
    p=crearPilaD();

    // Coche *c1,*c2;
    // Nodo_p *n,*n2;
    // //Crea la pila
    // //Crea un elemento
    // c1=crearCoche("AB1",2021,1,2);
    // //Lo inserta en la pila
    // n=crearNodoD(c1);
    // pushP(p,n);//Ingresa el nodo AB1
    // c2=crearCoche("AB2",2019,2,1);
    // n2=crearNodoD(c2);
    // pushP(p,n2);//Ingresa el nodo AB1

    //Otra forma de agregar un elemento es la siguiente
    pushP(p,crearNodoD(crearCoche("AB1",2023,2,2)));
    pushP(p,crearNodoD(crearCoche("AB2",2018,1,2)));
    pushP(p,crearNodoD(crearCoche("AB3",2021,1,2)));
    pushP(p,crearNodoD(crearCoche("AB4",2023,2,1)));
    
    //Imprime la pila
    imprimirP(p);
    popP(p);
    popP(p);
    imprimirP(p);
    vaciarP(p);
    imprimirP(p);


}