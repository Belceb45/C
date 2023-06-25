#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,const char* argv[]){
    /* time_t es un tipo de dato definido para el almacenamiento
       de valores de tiempo del sistema, los valores se devuleven
       desde la función time()*/
    time_t oneDay=24*60*60,today=time(NULL),NEXT_date;
    //Con atoi convertimos los caracteres en números, o solo reconoce los números de un string
    NEXT_date=today+oneDay*atoi(argv[1]);
    // ctime: permite tomar una estructura de tipo (time_t) y convertirla en string
    printf("%s\n",ctime(&NEXT_date));
    return 0;
}