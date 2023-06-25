// Rubio Haro Diego
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 30
#define MAX_SEX 7
// Estructuras
typedef struct persona
{
    char *name;
    char *sexo;
    int edad;
    int peso;
    float altura;

} PERSONAS;

// Prototipos
PERSONAS *structDinamic(int);
void mostrarPersonas(PERSONAS *, int);
void num_personas(int *);
void ingresarPersonas(PERSONAS *, int);
// Función principal
int main()
{
    PERSONAS *person;
    int num;
    num_personas(&num);
    person = structDinamic(num);
    ingresarPersonas(person, num);
    mostrarPersonas(person, num);
}
// Struct dinamico
PERSONAS *structDinamic(int n)
{
    PERSONAS *p;
    int i;
    p = (PERSONAS *)malloc(n * sizeof(PERSONAS));
    if (p == NULL)
    {
        puts("\n\nNO FUE POSIBLE ASIGNAR LA MEMORIA");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        p[i].name = (char *)malloc(MAX_NAME + 1 * sizeof(char));
        if (p[i].name == NULL)
        {
            puts("\n\nNO FUE POSIBLE ASIGNAR LA MEMORIA\n");
            exit(0);
        }
        p[i].sexo = (char *)malloc(MAX_SEX + 1 * sizeof(char));
        if (p[i].sexo == NULL)
        {
            puts("\n\nNO FUE POSIBLE ASIGNAR LA MEMORIA\n");
            exit(0);
        }
    }

    return p;
}
// Ingresar personas
void ingresarPersonas(PERSONAS *persona, int n)
{
    printf("\n\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Persona[%i]\n", i + 1);
        printf("Nombre: ");
        
        getchar();
        scanf(" %30[^\n]%*[^\n]%*c", persona[i].name);
        getchar();
        printf("Sexo: ");
        scanf("%s", persona[i].sexo);
        printf("Edad: ");
        scanf("%i", &persona[i].edad);
        printf("Peso: ");
        scanf("%i", &persona[i].peso);
        printf("Altura: ");
        scanf("%f", &persona[i].altura);
        printf("\n\n");
    }
}
// Mostrar Personas
void mostrarPersonas(PERSONAS *persona, int n)
{

    int i;
    for (i = 0; i < n; i++)
    {

        printf("\n\nPersona[%i]\n", i + 1);
        printf("\nNombre: %s", persona[i].name);
        printf("\nSexo: %s", persona[i].sexo);
        printf("\nEdad: %i", persona[i].edad);
        printf("\nPeso: %ikg", persona[i].peso);
        printf("\nAltura: %.2fm", persona[i].altura);
    }
}
// Ingresar la cantidad de personas
void num_personas(int *n)
{
    printf("\nNumero de personas: ");
    scanf("%i", n);
}
