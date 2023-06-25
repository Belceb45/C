#include <stdio.h>
#include <string.h>

/*Realizar un programa que calcule el promedio de peso y
altura de las mujeres y hombres mayores o iguales a 18 años*/
int main()
{

    int condicion, i, n, edad, numero_h, numero_m;
    char sexo;
    float alturas[10];
    float altura_promedio, peso, altura, peso_promedio;
    condicion = 1;
    numero_h = 0;
    numero_m = 0;
    altura = 0;
    peso = 0;

    while (condicion == 1)
    {
        printf("Ingrese el numero de personas a estudiar: ");
        scanf("%i", &n);
        if (n > 0)
        {
            for (i = 1; i <= n; i++)
            {
                printf("Hombre o Mujer: ");

                scanf("%c", &sexo);
                scanf("%c", &sexo);
                if (sexo == 'H' || sexo == 'h')
                {

                    numero_h++;
                    printf("Ingresa tu edad: ");
                    scanf("%i", &edad);
                    if (edad >= 18)
                    {
                        printf("Ingresa tu peso: ");
                        scanf("%f", &peso);
                        peso_promedio += peso;
                        printf("Ingresa tu altura: ");
                        scanf("%f", &altura);
                        altura_promedio += altura;
                    }
                }
                else if (sexo == 'M' || sexo == 'm')
                {
                    numero_m++;
                    printf("Ingresa tu edad: ");
                    scanf("%i", &edad);
                    if (edad >= 18)
                    {
                        printf("Ingresa tu peso: ");
                        scanf("%f", &peso);
                        peso_promedio += peso;
                        printf("Ingresa tu altura: ");
                        scanf("%f", &altura);
                        altura_promedio += altura;
                    }

                    printf("\nSeleccionaste %c\n", sexo);
                }
                altura_promedio = altura_promedio / numero_h;
                altura_promedio = altura_promedio / numero_m;
                peso_promedio = peso_promedio / numero_h;
                peso_promedio = peso_promedio / numero_m;
                printf("%f %f", peso_promedio, altura_promedio);
                condicion = 0;
            }
        
        }
        else{
            printf("No es posible que sea cero o negativo, vuelve a intentarlo");
        }
    }
}
