#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro de personas
typedef struct nodo
{
    char *nombre;
    char *direccion;
    int edad;
    struct nodo *sig;
} Personas;
// Prototipos
Personas *ListaPersonas(Personas *listas);
Personas *elminar(Personas *listas, char *nom);
Personas *agregar_personas(Personas *listas);
// Personas *elminar_primero(Personas *listas, char *nom, int *ptr);
// Personas *elminar_intermedios(Personas *listas, char *nom, int *ptr);
// Personas *elminar_ultimo(Personas *listas, char *nom);
void mostrar(Personas *listas);
//

/*------------------------------------------------------------------------------------------*/
// Funcion principal
int main(int argc, char *argv[])
{
    int opcion;
    Personas *listas = ListaPersonas(listas);

    printf("\n\t\6------------------------ REGISTRO DE PERSONAS -------------------------\6");
    printf("\n\t\6-----------------------------------------------------------------------\6");
    printf("\n\t\6           1.- Agregar personas  2.- Eliminar personas                 \6");
    printf("\n\t\6-----------------------------------------------------------------------\6");
    printf("\n\t\6-----------------------------------------------------------------------\6");

    printf("\n\t\6 %cQue desea hacer?: ", 168);
    scanf("%i", &opcion);
    if (opcion == 1)
    {
        int n;
        printf("\t%cCuantas personas deseas agregar?: ", 168);
        scanf("%i", &n);
        system("cls");
        for (int i = 1; i <= n; i++)
        {
            printf("\n\tPersona %i\n", i);
            listas = agregar_personas(listas);
        }
    }
    else if (opcion == 2)
    {
    }

    mostrar(listas);
    system("\tpause");
}
//
/*------------------------------------------------------------------------------------------*/
// Funcion Eliminar Personas
Personas *elminar(Personas *listas, char *nom)
{
    Personas *borrar = NULL, *primero = listas;
    int num_personas;
    printf("¿Cuantas personas desea agregar?: ");
    scanf("%i", &num_personas);
    while (listas != NULL)
    {
        // PRIMER CASO
        if (listas != NULL && stricmp(listas->nombre, nom) == 0)
        {

            borrar = listas;
            listas = listas->sig;
            free(borrar);
            return listas;
        }
        // CASO INTERMEDIO
        if (listas->sig->sig != NULL && stricmp(listas->sig->nombre, nom) == 0)
        {
            borrar = listas->sig;
            listas->sig = listas->sig->sig;
            free(borrar);
            return primero;
        }

        // CASO FINAL
        if (listas->sig->sig == NULL && stricmp(listas->sig->nombre, nom) == 0)
        {

            borrar = listas->sig;
            listas->sig = NULL;
            free(borrar);
            return primero;
        }
        listas = listas->sig;
    }
}

// Funcion de listas
Personas *ListaPersonas(Personas *listas)
{
    listas = NULL;
    return listas;
}
// Funcion de Agregar personas al principio
Personas *agregar_personas(Personas *listas)
{
    Personas *nueva_persona, *aux;
    if (nueva_persona != NULL)
    {
        nueva_persona = (Personas *)malloc(sizeof(Personas));
        nueva_persona->nombre = (char *)malloc(1000 * sizeof(char));
        nueva_persona->direccion = (char *)malloc(1000 * sizeof(char));
        // fflush(stdin);
        printf("\tNombre: ");
        scanf("%s", nueva_persona->nombre);
        // fgets(nueva_persona->nombre, 20, stdin);

        printf("\tDireccion: ");
        scanf("%s", nueva_persona->direccion);
        // fgets(nueva_persona->nombre, 20, stdin);

        printf("\tEdad: ");
        scanf("%i", nueva_persona->edad);
        printf("\n");

        nueva_persona->sig = NULL;

        if (listas == NULL)
        {
            listas = nueva_persona;
            printf("\nSe creo un nodo\n");
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
    }
    else
    {
        printf("\nMemoria RAM llena\n");
    }
    

    return listas;
}

// Mostrar Lista
void mostrar(Personas *listas)
{
    system("cls");
    printf("\n\t\6------------------------ PERSONAS ------------------------------------\6");

    if (listas == NULL)
    {
        printf("\nLista vacia");
    }
    else
    {
        while (listas != NULL)
        {
            printf("\n\t\6----------------------------------------------------------------------\6");
            printf("\n\t|Nombre: %s\t\t\t\t\t       ", listas->nombre);
            printf("\n\t|Direccion: %s\t\t\t\t\t       ", listas->direccion);
            printf("\n\t|Edad: %i\t\t\t\t\t\t\t       ", listas->edad);

            listas = listas->sig;
        }
        printf("\n\t\6----------------------------------------------------------------------\6\n");
    }
}