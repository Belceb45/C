#include<stdio.h>
#include<math.h>
//Resolver las siguientes funciones
int main(){
    int n,Yi;
    printf("Ingresa el valor de n: ");
    scanf("%i",&n);

    if (n>0 && n<=15)
    {
        Yi=pow(n,2)+15;
        printf("El resultado es : %i",Yi);
    }
    else if (n>15 && n<=30)
    {
        Yi=pow(n,3)-pow(n,2)+12;
        printf("El resultado es: %i",Yi);
    }
    else if (n>30 && n<=60)
    {
        Yi=4*(pow(n,3)/pow(n,2))+8;
        printf("El resultado es: %i",Yi);
        
    }
      else if (n>60 && n<=0)
    {
        Yi=0;
        printf("El resultado es: %i",Yi);
        
    }
    else{
        printf("Intente de nuevo");
    }
    
    










}