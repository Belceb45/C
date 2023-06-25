#include <stdio.h>
#include <stdlib.h>
// Rubio Haro
// Algoritmo 4: div and mod
// a tiene que ser entero y b entero positivo
int main()
{

    int a, d, r, q = 0;
    printf("Ingrese un numero entero: ");
    scanf("%i", &a);
    printf("Ingrese un numero entero positivo: ");
    scanf("%i", &d);
    if (d > 0 && a != 0)
    {
        if (a < 0)
        {
            r = -a;
            // printf("%i",-a);
        }
        else
        {
            r = a;
            // printf("%i",r);
        }

        while (r >= d)
        {
            /*por cada resta que se haga en r(dividendo), se 
              incrementará q en 1, de esta forma sabremos cuantas veces
              se tendría que sumar d(divisor) para llegar al dividendo, y 
              de esa forma obtener el cociente . */
            r = r - d;
            q = q + 1;
        }
        /*Se nos dice que a(el dividendo es negativo)
        En las clases pasadas vimos el algoritmo extendido de euclides, nos apoyamos
        de eso para entender este algoritmo.
        Se puede entender al dividendo de una operación(en nuestro caso a)
        como: la multiplicación del divisor por el cociente más el residuo
        Es decir: a=q(cociente)*d(divisor)+r(residuo)
        
        */
        if (a < 0 && r > 0)
        {
            /*Entonces, si a es negativo y r mayor que 0(no hay ningún caso en el que sea menor a cero)
              significa que -a=-(qd+r)-->-a=-qd-r*/
            
            //¿Qué significa r=d-r?? Restarle al divisor el residuo de la operación??, Por qué?
            r = d - r;
            q = -(q + 1);
        }
        return printf("q=%i,r=%i", q, r);
    }
}