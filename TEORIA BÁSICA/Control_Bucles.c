#include <stdio.h>

// Control de flujo con el While

/*While: Para entrar al while se tiene que cumplir la condicion
  para poder entrar, y se tiene que actualizar para poder salir
  del mismo, o de otra forma se quedaria infinitamente ahí*/

// Rubio Haro Diego
//Con break salimos del bucle
//Continue es lo contrario
int a = 0, b = 1, c = 0, cont = 0;
int Es_primo(int numero)
{
    int contador_2=0;
    for (int i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
            contador_2++;
    }
    if (contador_2 == 2)
        return 1;
    else
        return 0;
}
int main()
{

    while (cont < 30)
    {
        c = a + b;
        
        if(Es_primo(c)==0){
            printf("%i, ",c);
        }
        
        cont++;
        a = b;
        b = c;
    }
}
