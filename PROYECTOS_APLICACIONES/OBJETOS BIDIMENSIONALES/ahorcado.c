#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Prototipo
void ahorcado();
void casos(int *pt1);
void animales(int *p1);
void dibujado(int *intentos);

int main()
{
    srand(time(NULL));
    int opcion;
    int *pt1;
    pt1 = &opcion;
    ahorcado();
    printf("\t\t\tElige una opcion: ");
    scanf("%i", &opcion);
    system("cls");
    casos(pt1);
}

void ahorcado()
{

    printf("\n|---------------------------> AHORCADO <---------------------------|\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|                            1.-Animales                           |\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|                            2.-Frutas                             |\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|                            3.-Verduras                           |\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|                            4.-Colores                            |\n");
    printf("|------------------------------------------------------------------|\n");
}
void casos(int *pt1)
{
    int intentos = 0;
    int *p1;
    p1 = &intentos;
    switch (*pt1)
    {
    case 1:
        printf("|---------------------------> Animales <---------------------------|");
        animales(p1);

        break;
    case 2:
        printf("|---------------------------> Frutas <---------------------------|");

        break;
    case 3:
        printf("|---------------------------> Verduras <---------------------------|");

        break;
    case 4:
        printf("|---------------------------> Colores <---------------------------|");

        break;

    default:
        break;
    }
}

void dibujado(int *intentos)
{

    switch (*intentos)
    {
    case 0:
        printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
        
        break;
    case 1:
        printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
        break;
    case 2:
        printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
        break;
    case 3:
        printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
        break;
    case 4:
        printf("\n     _______\n    |       |\n    |       0\n    |      /|");
        printf("\\");
        printf("\n");
        printf("    |\n    |\n    |\n ----------");
        break;
    case 5:
        printf("\n     _______\n    |       |\n    |       0\n    |      /|");
        printf("\\");
        printf("\n");
        printf("    |      /\n    |\n    |\n ----------");
        break;
    case 6:
        printf("\n     _______\n    |       |\n    |       0\n    |      /|");
        printf("\\");
        printf("\n");
        printf("    |      / ");
        printf("\\");
        printf("\n");
        printf("    |\n    |\n ----------");
        break;
    }
}

void animales(int *p1)
{

    int opt, tam;
    char animales[5][10] = {"perro", "gato", "conejo", "cucaracha", "raton"};
    opt = rand() % 5;
    tam = strlen(animales[opt]);
    char *palabra = (char *)malloc(10 + 1 * sizeof(char));
    strcpy(palabra, animales[opt]);
    printf("\n|Posicion[%i]=%s tam->%i\n", opt, palabra, tam);
    *p1 = 0;
    printf("|Numero de intentos: %i\n", 6 - *p1);
    dibujado(p1);
    printf("\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf(" _ ");
        }
    //
    printf("");
    char *prt = (char *)malloc(10 + 1 * sizeof(char));
    for (int i = 0; i < tam; i++)
    {
        int contador = 0;
        printf("");
        scanf("%s", &prt[i]);
        for (int j = 0; j < tam; j++)
        {
            if (prt[i] == palabra[j])
            {
                contador += 1;
            }
        }
        if (contador == 0)
        {
            printf("\nNO HAY COINCIDENCIAS\n");
            *p1 += 1;
        }

        printf("Letra [%c] se encuenta %i veces\n\n", prt[i], contador);
    }
}
