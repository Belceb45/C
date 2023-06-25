#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int n=10;
    char *palabras;
    palabras=(char*)malloc(n+1*sizeof(char));
    char *pt1;
    pt1=(char*)malloc(n+1*sizeof(char));
    pt1="aaabbbjjrt";
    int t=strlen(pt1);
    printf("\npt1: %s",pt1);
    printf("\nstrlen: %i\n\n",t);
    for (int i = 0; i < t; i++)
    {   
        int contador=0;
        printf("ingresa un caracter[%i]: ",i);
        scanf("%s",&palabras[i]);
        for (int j = 0; j < t; j++)
        {
            if (palabras[i]==pt1[j])
            {
                contador+=1;
            }
            
        }
        if (contador==0)
        {
            printf("\nNO HAY COINCIDENCIAS\n");
        }
        
        printf("Letra [%c] se encuenta %i veces\n\n",palabras[i],contador);
        
    }
    // printf("\npalabra: %s",palabras);
    // printf("\npalabra[2]: %s",palabras[2]);
    // printf("\npalabra[9]: %s",palabras[9]);


    
}