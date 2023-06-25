#include<stdio.h>
//Programa que se salta un ciclo for usando (continue)
int main(){

    int n=10;
    int i;
    for (i = 0; i < n; i++)
    {
        if(i==6){
            continue;
        }
        printf("%i, ",i);
        
    }
    // printf("%i",i);
}