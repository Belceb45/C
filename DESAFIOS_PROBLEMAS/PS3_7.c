#include <stdio.h>
#include <math.h>
// Resolver la siguiente serie:
// 1**1
int main()
{
    int j, n, i, a;
    a = 1;
    j=0;
    printf("Ingresa un numero para la serie: ");
    scanf("%i", &n); // n = 3
    for (i = 2; i <= n; i++) // [2-3] = 2
    {
        if (j==0)
        {
            a =a + pow(i, i);
            j=1;
        }
        else
        {
            a =a - pow(i, i);
            j=0;
        }
        
    }
        printf("%i", a);
}