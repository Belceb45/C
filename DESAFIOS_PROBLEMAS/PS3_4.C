#include<stdio.h>

/*Construye un diagrama de flujo y el correspondiente 
programa en C que calcule e imprima la productoria de 
los N primeros números naturales.*/
int main(){
    /*En este caso la operacion para la productoria
    será la siguiente: (i+1/i) */
    int condicion,n,i,j;
    condicion=1;
    float a;
    while (condicion==1)
    {
        printf("\nIngrese el numero donde terminara: ");
        scanf("%i",&n);
        printf("Ingrese el numero con el que inicia: ");
        scanf("%i",&j);
        a=1;
        if (n>0 && j>0)
        {
        for ( i = j; i <=n; i++)
        {
            a=a*(i+1.0)/i;
            
        }
        printf("%f",a);
        printf("\nDesea hacerlo de nuevo?: ");
        scanf("%i",&condicion);
        }
        else{
            printf("\nDatos incorrectos, intente de nuevo.");
        }
        
    }
    

}