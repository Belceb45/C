// Rubio Haro Diego
// Grafico de objetos geometricos
/*
    Este programa puede graficar objetos geometricos
    con base a los paramétros dados por el usuario
*/
// Librerias
#include <stdio.h>
#include <stdlib.h>
// Estructuras

// Prototipos
void menu(int *);
void crear();
void triangulo();
// Función Principal
int main()
{
    int option;
    menu(&option);
    return 0;
}
// Función de Menú
void menu(int *option)
{
    system("cls");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6------------------------------ OBJETOS BIDIMENSIONALES -----------------------------\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6-- 1.-Crear      2.-Ver       3.-Eliminar       4.-Modificar       5.-Eliminar --\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6-------------------------------- 6.Regresar ----------------------------------------\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\n\tSeleccione una opcion: ");
    scanf("%i", option);
    switch (*option)
    {
    case 1:
        crear();
        break;
    case 2:

        break;
    case 3:

        break;

    default:
        break;
    }
}

// Función Agregar Objeto
void crear()
{
    int poligono;
    system("cls");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6------------------------------ POLIGONOS REGULARES ---------------------------------\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6--       1.-Triangulo      2.-Cuadrado       3.-Pentagono      4.-Hexagono        --\6\n");
    printf("\t\6--       5.-Heptagono      6.-Octagono       7.-Eneagono       8.-Decagono        --\6\n");
    printf("\t\6--       9.-Endecagono     10.-Dodecagono                                         --\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\t\6------------------------------------------------------------------------------------\6\n");
    printf("\n\tElige un Poligono: ");
    scanf("%i", &poligono);
    switch (poligono)
    {
    case 1:
        triangulo();
        break;
    case 2:
        printf("\n\tERROR");
        break;
    case 3:
        printf("\n\tERROR");
        break;
    case 4:
        printf("\n\tERROR");
        break;
    case 5:
        printf("\n\tERROR");
        break;
    case 6:
        printf("\n\tERROR");
        break;
    case 7:
        printf("\n\tERROR");
        break;
    case 8:
        printf("\n\tERROR");
        break;

    default:
        printf("\n\tERROR, INGRESA UN PARAMETRO VALIDO");
        break;
    }
}

// Funcion Triangulo
void triangulo()
{
    int i,j,longitud;
    float altura;
    system("cls");
    do
    {
        printf("\n\tlongitud de lado: ");
        scanf("%i", &longitud);
        if (longitud<0 || longitud>15)
        {
            printf("\n\tIntente de nuevo");
        }
        
    } while (longitud<0 || longitud>15);
    printf("\n\tLongitud: %i",longitud);
    altura=longitud/2.0;
    
    
}