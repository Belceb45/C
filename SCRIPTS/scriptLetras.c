#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *archivo;

    archivo = fopen("files.bat", "w");

    char code[500] = "@echo off\npause\ncolor 0a\nmode 1000\n:a\necho %random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%\ngoto a";



    if(archivo != NULL){
        fflush(stdin);
        fwrite(&code, sizeof(code),1,archivo);
        fclose(archivo);
    }

    return 0;
}