/**
 * @file Cubo.cpp
 * @author {Rubio Haro Diego} ({rubiodiego001@gmail.com})
 * @brief
 * @version 0.1
 * @date 2023-06-18
 *
 *
 */
// Librerias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>

// Estructuras

struct nodo
{
  int info;
  struct nodo *sig;
  struct nodo *adelante;
  struct nodo *arriba;
} Nodo;

nodo *raiz1 = NULL, *raiz2 = NULL, *raiz3 = NULL;

// Prototipos

void imprimir();
void CrearCubo();
int ObtenerDato(int, int, int);
void grafico();
void cara(int, int, int, int, int);

// Función principal

int main()
{
  int opcion, suma = 0, fila, columna, cara;

  CrearCubo();
  printf("\nCUBO COMPLETO\n\n1.- Sumar Filas\n2.- Sumar Columnas\n3.- Sumar Caras\n4.- Imprimir valores (terminal)\n5.- Ver Cubo\n");
  printf("\nR: ");
  scanf("%d", &opcion);

  if (opcion == 1)
  {
    printf("\nFila:");
    scanf("%i", &fila);
    printf("Cara:");
    scanf("%i", &cara);
    for (int x = 1; x <= 5; x++)
    {
      suma = suma + ObtenerDato(fila, x, cara);
    }
    printf("La suma es: %i\n", suma);
  }
  else if (opcion == 2)
  {
    printf("\nColumna:");
    scanf("%i", &columna);
    printf("Cara:");
    scanf("%i", &cara);
    for (int x = 1; x <= 5; x++)
    {
      suma = suma + ObtenerDato(x, columna, cara);
    }
    printf("La suma es: %i\n", suma);
  }
  else if (opcion == 3)
  {
    printf("\nCara:");
    scanf("%i", &cara);
    for (int x = 1; x <= 5; x++)
    {
      for (int y = 1; y <= 5; y++)
      {
        suma = suma + ObtenerDato(x, y, cara);
      }
    }
    printf("La suma es: %i\n", suma);
  }
  else if (opcion == 4)
  {
    // system("clear");
    imprimir();
  }
  else if (opcion == 5)
  {
    grafico();
  }
  else
  {
    printf("\nLa opción que seleccionó no es válida.\n");
  }
}
int ObtenerDato(int x, int y, int z)
{
  nodo *reco = raiz1;
  for (int i = 1; i < z; i++)
  {
    reco = reco->adelante;
  }
  for (int i = 1; i < x; i++)
  {
    reco = reco->arriba;
  }
  for (int i = 1; i < y; i++)
  {
    reco = reco->sig;
  }

  return reco->info;
}
void imprimir()
{
  nodo *reco = raiz1;
  raiz3 = raiz1;
  raiz2 = raiz1;
  while (raiz2 != NULL)
  {
    while (raiz3 != NULL)
    {

      while (reco != NULL)
      {
        printf("| %i ", reco->info);
        reco = reco->sig;
      }

      raiz3 = raiz3->arriba;
      reco = raiz3;
      printf("| \n");
    }

    raiz2 = raiz2->adelante;
    raiz3 = raiz2;
    reco = raiz3;
    printf("\n");
  }
}
void CrearCubo()
{
  nodo *nuevo, *aux;

  for (int x = 1; x < 6; x++)
  {
    for (int y = 1; y < 5; y++)
    {

      for (int z = 1; z < 5; z++)
      {
        if (raiz1 == NULL)
        {
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->arriba = NULL;
          nuevo->adelante = NULL;
          nuevo->info = 5;
          nuevo->sig = NULL;
          raiz1 = nuevo;
          raiz2 = raiz1;
          raiz3 = raiz2;
          aux = raiz3;

          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = x + y + z;
          nuevo->sig = NULL;
          aux->sig = nuevo;
          aux = aux->sig;
        }
        else
        {
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = x + y + z;
          nuevo->sig = NULL;
          aux->sig = nuevo;
          aux = aux->sig;
        }
      }
      nuevo = (nodo *)malloc(sizeof(nodo));
      nuevo->info = x + y;
      nuevo->arriba = NULL;
      raiz3->arriba = nuevo;
      raiz3 = raiz3->arriba;
      aux = raiz3;
      if (y == 4)
      {
        for (int w = 1; w < 5; w++)
        {
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = x + y + w;
          nuevo->sig = NULL;
          aux->sig = nuevo;
          aux = aux->sig;
        }
      }
    }
    if (x == 5)
    {
    }
    else
    {
      nuevo = (nodo *)malloc(sizeof(nodo));
      nuevo->info = x;
      nuevo->adelante = NULL;
      raiz2->adelante = nuevo;
      raiz2 = raiz2->adelante;
      raiz3 = raiz2;
      aux = raiz3;
    }
  }
}

//Función que inicia el modo gráfico y lo muestra
void grafico()
{

  initwindow(1720, 1080, "CUBO COMPLETO");
  setbkcolor(15);
  cleardevice();

  setcolor(BLUE);
  settextstyle(4, 0, 3);
  outtextxy(1200, 300, "RUBIO HARO DIEGO");
  outtextxy(1200, 400, "ESTRUCTURAS DE DATOS");
  outtextxy(1200, 500, "2CM4");

  for (int i = 1; i <= 5; i++)
  {
    setcolor(BLACK);
    settextstyle(4, 0, 3);
    cara(i, 0, 0, 0, 0);
  }
  getch();
}

// Función que imprime cada cara
void cara(int n, int posx, int posy, int posxO, int posyO)
{

  char resultado[20];
  setfillstyle(2, n + 3);
  setbkcolor(n + 3);
  for (int x = 1; x < 6; x++)
  {

    fillellipse(posxO + (200 + (100 * x) + (50 * n)), posyO + (200 - (40 * (n - 1))), 20, 20);
    /*Funcion gcvt-> convierte numero a una cadena de caracteres ASCII con la mínima longitud 
    posible, acabada en el carácter NUL, y guarda el resultado en buf.*/
    gcvt(ObtenerDato(1, x, n), 6, resultado);
    outtextxy(posx + (190 + (100 * x) + (50 * n)), posy + (190 - (40 * (n - 1))), resultado);

    fillellipse(posyO + (200 + (100 * x) + (50 * n)), posyO + (300 - (40 * (n - 1))), 20, 20);
    gcvt(ObtenerDato(2, x, n), 6, resultado);
    outtextxy(posx + (190 + (100 * x) + (50 * n)), posy + (290 - (40 * (n - 1))), resultado);

    fillellipse(posyO + (200 + (100 * x) + (50 * n)), posyO + (400 - (40 * (n - 1))), 20, 20);
    gcvt(ObtenerDato(3, x, n), 6, resultado);
    outtextxy(posx + (190 + (100 * x) + (50 * n)), posy + (390 - (40 * (n - 1))), resultado);

    fillellipse(posxO + (200 + (100 * x) + (50 * n)), posyO + (500 - (40 * (n - 1))), 20, 20);
    gcvt(ObtenerDato(4, x, n), 6, resultado);
    outtextxy(posx + (190 + (100 * x) + (50 * n)), posy + (490 - (40 * (n - 1))), resultado);

    fillellipse(posxO + (200 + (100 * x) + (50 * n)), posyO + (600 - (40 * (n - 1))), 20, 20);
    gcvt(ObtenerDato(5, x, n), 6, resultado);
    outtextxy(posx + (190 + (100 * x) + (50 * n)), posy + (590 - (40 * (n - 1))), resultado);
  }
}