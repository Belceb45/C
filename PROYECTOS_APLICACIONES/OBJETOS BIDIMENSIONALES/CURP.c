#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de dato para el numero de celular
// typedef struct CURP
// {
//     int numeros;
// } CURP;

// Estructura de dato para los datos del individuo
typedef struct Persona
{
    char nombre_pila[10];
    char apellido_1[10];
    char apellido_2[10];
    int fecha_dia;
    int fecha_mes;
    int fecha_year;
    char sexo[6];
    char entidad[5];

} Persona;

void entidad()
{

    printf("ingresa la clave de tu entidad federativa\n");
    printf("AGUASCALIENTES-AS\n");
    printf("BAJA CALIFORNIA-BC\n");
    printf("BAJA CALIFORNIA SUR-BS\n");
    printf("CAMPECHE-CC\n");
    printf("COAHUILA-CL\n");
    printf("COLIMA-CM\n");
    printf("CHIAPAS-CS\n");
    printf("CHIHUAHUA-CH\n");
    printf("DISTRITO FEDERAL-DF\n");
    printf("DURANGO-DG\n");
    printf("GUANAJUATO-GT\n");
    printf("GUERRERO-GR\n");
    printf("HIDALGO-HG\n");
    printf("JALISCO-JC\n");
    printf("MEXICO-MC\n");
    printf("MICHOACAN-MN\n");
    printf("MORELOS-MS\n");
    printf("NAYARIT-NT\n");
    printf("NUEVO LEON-NL\n");
    printf("OAXACA-OC\n");
    printf("PUEBLA-PL\n");
    printf("QUERETARO-QT\n");
    printf("QUINTANA ROO-QR\n");
    printf("SAN LUIS POTOSI-SP\n");
    printf("SINALOA-SL\n");
    printf("SONORA-SR\n");
    printf("TABASCO-TC\n");
    printf("TAMAULIPAS-TS\n");
    printf("TLAXCALA-TC\n");
    printf("VERACRUZ-VZ\n");
    printf("YUCATAN-YN\n");
    printf("ZACATECAS-ZS\n");
    printf("\nNACIDO EN EL EXTRANJERO-NE\nR:");
}

int main()
{

    // Programa para generar CURPS
    int n;
    printf("Este es un programa que genera CURP's de las personas ingresadas");
    printf("\nIngresa la cantidad de personas a registrar\nR: ");
    scanf("%i", &n);
    if (n > 0)
    {

        Persona person[n];

        // CURP Diego: RUHD030829HDFBRGA2
        /*Creamos un arreglo person del tipo de dato
          estructurado "Persona", este arreglo estará dado
          por el usuario*/
        for (int i = 0; i < n; i++)
        {

            printf("\nNombre de pila\nR: ");
            scanf("%s", &person[i].nombre_pila);
            printf("\nPrimer apellido\nR: ");
            scanf("%s", &person[i].apellido_1);
            printf("\nSegundo apellido\nR: ");
            scanf("%s", &person[i].apellido_2);
            printf("\nEn que a%co naciste?\nR: ",164);
            scanf("%i", &person[i].fecha_year);
            printf("\nEn que mes naciste?\nR: ");
            scanf("%i", &person[i].fecha_mes);
            printf("\nEn que dia naciste?\nR: ");
            scanf("%i", &person[i].fecha_dia);
            printf("\nSexo: (Hombre) o (Mujer)\nR: ");
            scanf("%s", &person[i].sexo);
            entidad();
            scanf("%s", &person[i].entidad);
        }
        for (int i = 0; i < n; i++)
        {
            printf("\n\n\6-----------------------------------------------\6");
            printf("\nNombre de pila[%i]=%s", i, person[i].nombre_pila);
            printf("\nPrimer Apellido[%i]=%s", i, person[i].apellido_1);
            printf("\nSegundo Apellido[%i]=%s", i, person[i].apellido_2);
            printf("\nFecha de nacimiento %i/%i/%i", person[i].fecha_dia, person[i].fecha_mes, person[i].fecha_year);
            if (stricmp(person[i].sexo, "Mujer") == 0)
            {
                printf("\nTu sexo: Mujer");
            }
            else if(stricmp(person[i].sexo,"Hombre")==0)
            {
                printf("\nTu sexo: Hombre");
            }

            printf("\nEntidad Federativa=%s\n", person[i].entidad);
        }
        printf("\n\6-----------------------------------------------\6");

    }
    else
    {
        printf("\nNo se admiten negativos, vuelve a intentar");
    }
}
