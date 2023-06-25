#include <stdio.h>
#include <stdlib.h>

/*Hacer un programa que sea capaz de regresar el
cambio de un producto de una maquina expendedora*/
int main()
{
    // n es el producto elegido
    int condicion, n, costo, money;
    condicion = 1;
    while (condicion == 1)
    {
        printf("\n 10-Coca600mL($10)    11-Fanta600mL($9)         12-SidralMundet600mL($9) ");
        printf("\n 13-DoritosNacho($12) 14-SabritasAdobadas($11)  15-TostitosNachos($10");
        printf("\n 16-DonasBimbo($15)   17-Mantecadas($14)        18-ChocoDonas($6");
        printf("\n Elige tu producto: ");
        scanf("%i", &n);

        switch (n)
        {
        case 10:
            costo = 10;
            printf("CocaCola 600mL $10\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;
        case 11:
            costo = 9;
            printf("Fanta 600mL $9\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;

        case 12:
            costo = 9;
            printf("Sidral Mundet 600mL $9\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;

        case 13:
            costo = 13;
            printf("Doritos Nacho $13\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;
        case 14:
            costo = 11;
            printf("Sabritas Adobadas $11\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;
        case 15:
            costo = 10;
            printf("Tostitos Nacho $10\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;

        case 16:
            costo = 15;
            printf("Donas Bimbo $15\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;

        case 17:
            costo = 14;
            printf("Mantecadas $14\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;

        case 18:
            costo = 6;
            printf("Choco Donas $6\n Ingrese el efectivo: ");
            scanf("%i", &money);
            if (money > costo)
            {
                money = money - costo;
                printf("Su cambio es de: $%i", money);
                printf("\nRetire su producto \nCompre pronto :)");
            }
            else if (money == costo)
            {
                printf("Retire su producto\n Compre pronto :)");
            }
            else if (money < costo)
            {
                costo = costo - money;
                printf("%iFaltan: $", costo);
            }

            break;
        }
        printf("\n¿Desea seguir comprando (1-si,0-no)?: ");
        scanf("\n%i", &condicion);
    }

    return 0;
}