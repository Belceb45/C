#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_CARACTERES 50
// Registro de personas
typedef struct nodo
{

    char *nombre;
    char *direccion;
    int edad;
    int identificador;
    struct nodo *sig;
} Personas;
// Prototipos
Personas *ListaPersonas(Personas *listas);
Personas *Agregar(Personas *listas, int *contador);
Personas *elminar(Personas *listas,int *contador);
Personas *agregar_personas(Personas *listas, char *nombre, char *direccion, int edad, int *contador);
void interfaz(Personas *listas, int *contador);
void mostrar(Personas *listas, int *contador);
Personas *elminar_indice(Personas *listas,int *contador);

// Funcion principal
int main(int argc, char *argv[])
{

    Personas *listas = ListaPersonas(listas);
    int num = 1;
    int *contador = &num;
    interfaz(listas, contador);
}

/*------------------------------------------------------------------------------------------*/
void interfaz(Personas *listas, int *contador)
{
    system("cls");
    printf("\n\t\6------------------------ REGISTRO DE PERSONAS -----------------------------\6");
    printf("\n\t\6---------------------------------------------------------------------------\6");
    printf("\n\t\6    1.- Agregar personas  2.- Eliminar personas  3.- Salir  4.- Ver/Lista  \6");
    printf("\n\t\6---------------------------------------------------------------------------\6");
    printf("\n\t\6---------------------------------------------------------------------------\6");
    int opcion, p;
    fflush(stdin);
    printf("\n\t\6 %cQue desea hacer?: ", 168);
    p = scanf("%i", &opcion);
    while (!p)
    {
        printf("\n\tERROR, no es un numero, intentelo nuevamente\n\tR: ");
        fflush(stdin);
        p = scanf("%i", &opcion);
    }
    fflush(stdin);

    if (opcion == 1)
    {
        listas = Agregar(listas, contador);
        interfaz(listas, contador);
    }
    else if (opcion == 2)
    {
        listas = elminar(listas,contador);
        interfaz(listas, contador);
    }
    else if (opcion == 3)
    {
        exit(0);
    }
    else if (opcion == 4)
    {
        mostrar(listas, contador);
        interfaz(listas, contador);
    }

    else
    {
        printf("\n\tELIGE UNA OPCION VALIDA\n");
    }
}

// Funcion de listas
Personas *ListaPersonas(Personas *listas)
{
    listas = NULL;
    return listas;
}
// Agregar
Personas *Agregar(Personas *listas, int *contador)
{
    system("cls");
    printf("\n\t\6-----------------------------------------------------------------------\6");
    printf("\n\t\6           0.- REGRESAR                   1.- Agregar personas         \6");
    printf("\n\t\6-----------------------------------------------------------------------\6");
    int n, p;
    printf("\n\t%cCuantas personas deseas agregar?:  ", 168);
    p = scanf("%i", &n);
    // printf("p: %i",p);
    // system("pause");
    while (!p)
    {
        printf("\n\tERROR, no es un numero, intentelo nuevamente\n\tR: ");
        fflush(stdin);
        p = scanf("%i", &n);
        if (n < 0)
        {
            printf("\n\tNO SE ADMITEN NEGATIVOS");
            return listas;
        }
    }
    fflush(stdin);
    while (n < 0)
    {
        printf("\n\tNo se admiten negativos\n\tIntenta de nuevo: ");
        scanf("%i", &n);
    }

    if (n > 0)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            system("cls");
            printf("\n\n\tContador Persona %i", *contador);
            char *nombre = (char *)malloc(NUM_CARACTERES * sizeof(char));
            char *direccion = (char *)malloc(NUM_CARACTERES * sizeof(char));

            int edad;
            printf("\n\tNombre: ");
            fflush(stdin);
            fgets(nombre, NUM_CARACTERES - 1, stdin);
            printf("\tDireccion: ");
            fflush(stdin);
            fgets(direccion, NUM_CARACTERES - 1, stdin);
            fflush(stdin);
            printf("\tEdad: ");
            scanf("%i", &edad);
            fflush(stdin);
            listas = agregar_personas(listas, nombre, direccion, edad, contador);
        }

        return listas;
    }
    else if (n == 0)
    {
        return listas;
    }
}

// Funcion de Agregar personas al principio
Personas *agregar_personas(Personas *listas, char *nombre, char *direccion, int edad, int *contador)
{
    Personas *nueva_persona, *aux;
    nueva_persona = (Personas *)malloc(sizeof(Personas));
    nueva_persona->nombre = nombre;
    nueva_persona->direccion = direccion;
    nueva_persona->edad = edad;
    printf("\nValor contador: %i",contador);
    nueva_persona->identificador =*contador;
    printf("\nnueva_persona->identificador: %i",nueva_persona->identificador);
    *contador += 1;

    // printf("---------------------------------");
    // printf("\nNombre: %s",nueva_persona->nombre);
    // printf("Direccion: %s",nueva_persona->direccion);
    // printf("Edad: %i",nueva_persona->edad);
    // printf("\n---------------------------------");

    nueva_persona->sig = NULL;
    if (listas == NULL)
    {
        listas = nueva_persona;
    }
    else
    {
        aux = listas;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nueva_persona;
    }

    return listas;
}
//

// Funcion Eliminar Personas
Personas *elminar(Personas *listas,int *contador)
{
    system("cls");
    int opcion, p;
    printf("\n\t\6-----------------------------------------------------------------------\6");
    printf("\n\t\6           1.- INDICES       2.- TODOS      3.- SALIR                  \6");
    printf("\n\t\6-----------------------------------------------------------------------\6");
    if (listas != NULL)
    {
        fflush(stdin);
        printf("\n\tSelecciona una opcion: ");
        p = scanf("%i", &opcion);
        while (!p)
        {
            printf("\n\tSelecciona una opcion VALIDA: ");
            p = scanf("%i", &opcion);
        }

        if (opcion == 1)
        {
            Personas *borrar = NULL, *anterior, *primero;
            primero = listas;
            char delate[NUM_CARACTERES];
            fflush(stdin);
            printf("\n\t%cA quien desea eliminar?: ", 168);
            fgets(delate, NUM_CARACTERES - 1, stdin);
            printf("\tSi se encuentra se eliminara\n");

            while (listas != NULL)
            {

                printf("\nNOMBRE ACTUAL: %s", listas->nombre);
                if (listas != NULL && listas->sig == NULL && stricmp(listas->nombre, delate) == 0)
                {
                    // printf("\nEliminando primero\n");
                    borrar = listas;
                    listas = listas->sig;
                    free(borrar);
                    return listas;
                }
                else if (listas != NULL && listas->sig != NULL && stricmp(listas->nombre, delate) == 0)
                {
                    borrar = listas;
                    listas = listas->sig;
                    free(borrar);
                    return listas;
                }

                else if (listas->sig->sig == NULL)
                {
                    if (stricmp(listas->sig->nombre, delate) == 0)
                    {

                        borrar = listas->sig;
                        listas->sig = NULL;
                        free(borrar);
                        return primero;
                    }
                }
                // printf("\nBuscando N primero\n");
                if (listas->sig->sig != NULL)
                {
                    if (stricmp(listas->sig->nombre, delate) == 0)
                    {

                        borrar = listas->sig;
                        listas->sig = listas->sig->sig;
                        free(borrar);
                        return primero;
                    }
                }

                anterior = listas;
                listas = listas->sig;
            }
            printf("No se encontro al usuario, prueba con otro");
            return 0;
        }
        else if (opcion == 2)
        {
            listas = NULL;
            *contador=1;
            return listas;
        }
        else if (opcion == 3)
        {
            return listas;
        }
    }
    else
    {
        printf("\n\n\t NO PUEDES ELIMINAR USUARIOS DE UNA LISTA VACIA\n");
        system("pause");
        return 0;
        ;
    }
}
//
Personas *elminar_indice(Personas *listas,int *contador){

    // system("cls");
    // int *arreglo_indices=(int*)malloc((*contador)*sizeof(int)); 
    // puts("\nINGRESA LOS INDICES A BORRAR:");
    // mostrar(listas,contador);
    // while ()
    // {
    //     /* code */
    // }
    
    // printf("");


}

// Mostrar Lista
void mostrar(Personas *listas, int *contador)
{
    fflush(stdin);
    if (listas == NULL)
    {
        printf("\n\tLISTA VACIA (INTENTA DE NUEVO AGREGANDO USUARIOS :3 )\n\n");
        system("pause");
        interfaz(listas, contador);
    }
    else
    {
        system("cls");
        while (listas != NULL)
        {
            printf("-----------------------------------");
            printf("\nPERSONA: %i", listas->identificador);
            printf("\nNombre: %s", listas->nombre);
            printf("Edad: %i", listas->edad);
            printf("\nDireccion: %s", listas->direccion);
            
            printf("-----------------------------------\n");

            listas = listas->sig;
        }
    }
    printf("\n\n");
    system("pause");
}