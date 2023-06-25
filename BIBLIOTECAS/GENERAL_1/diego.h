#ifndef _diego
#define _diego

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class MEMORIA DINAMICA
**/
// Función Crear matriz N (Enteros)
int *matz_I(int);
// Función Crear matriz N (Decimales)
float *matz_F(int);
// Función Crear matriz N (Doubles)
double *matz_D(int);
// Función Crear matriz N aleatorios (Enteros)
int *matz_Irand(int);
// Función Crear matriz N aleatorios (Decimales)
float *matz_Frand(int);
// Función Crear matriz N aleatorios (Decimales)
double *matz_Drand(int);
// Función Crear matriz N Caracteres (String)
char *matz_C(int);
// Función Crear Matriz NXM (Enteros)
int **matzz_I(int, int);
// Función Crear Matriz NXM (Decimales)
float **matzz_F(int, int);
// Función Crear Matriz NXM (Doubles)
double **matzz_D(int, int);
// Función Crear Matriz con Numeros aleatorios NXM (ENTEROS)
int **matzz_Irand(int, int);
// Función Crear Matriz con Numeros aleatorios NXM (DECIMALES)
float **matzz_Frand(int, int);
// Función Crear Matriz con Numeros aleatorios NXM (DECIMALES)
double **matzz_Drand(int, int);
/**/

/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class MATH
**/
// Función Máximo común divisor (MCD)
int mcd(int, int);
// Función Mínimo común múltiplo (MCM)
int mcm(int, int);
// Función Factorial de un número (factorial)
int factorial(int);
// Función Fibonacci hasta n
int fibonacci(int n);
// Suma de matrices
int **sum_mtz(int **, int **, int, int);
// Resta de matrices
int **rest_mtz(int **, int **, int, int);
// Multiplicacion de matrices MxN
int **mult_mtz(int **, int **, int, int, int, int);
// Determinante de una matriz
double det_mtz(double **, int);



/**
 * @author Rubio Haro Diego
 * @date 04/02/23
 * @class ESTRUCTURAS
**/


#endif