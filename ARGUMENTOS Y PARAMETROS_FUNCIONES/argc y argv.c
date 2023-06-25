#include <stdio.h>

int main(int argc,char *argv[]){
    if (argc>1){
        printf("Hola %s",argv[1]);
        return 0;
    }
        printf("Ha olvidado su nombre.\n");
        return 0;
}