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
#include <time.h>

// Macros

#define RESOLUCION_X 720
#define RESOLUCION_Y 570
#define ASCI_FILAS 49         // Filas
#define ASCI_COLUMNAS 50      // Columnas
#define ASCI_CARAS 51         // Caras
#define ASCI_CUBO_COMPLETO 52 // Cubo completo

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

int menu();
void suma_filas();
void suma_columnas();
void suma_caras();
void suma_cubo();
void imprimir();
void CrearCubo();
int ObtenerDato(int, int, int);
void grafico();
void grafico_cara(int, int, int, int, int);
void intro();
// Función principal

int main()
{
  srand(time(NULL));
  initwindow(RESOLUCION_X, RESOLUCION_Y, "CUBO");
  intro();
  CrearCubo();
  int opt;
  opt = menu();
  // printf("\nTecla ASCII: %d", opt);
  printf("\n\n");
  imprimir();
  switch (opt)
  {
  case ASCI_FILAS:
    initwindow(RESOLUCION_X, RESOLUCION_Y);
    suma_filas();
    getch();
    cleardevice();
    grafico();
    getch();
    closegraph();
    break;

  case ASCI_COLUMNAS:
    initwindow(RESOLUCION_X, RESOLUCION_Y);
    suma_columnas();
    getch();
    cleardevice();
    grafico();
    getch();
    closegraph();
    break;

  case ASCI_CARAS:
    initwindow(RESOLUCION_X, RESOLUCION_Y);
    suma_caras();
    getch();
    cleardevice();
    grafico();
    getch();
    closegraph();
    break;

  case ASCI_CUBO_COMPLETO:
    initwindow(RESOLUCION_X, RESOLUCION_Y);
    suma_cubo();
    getch();
    cleardevice();
    grafico();
    getch();
    closegraph();
    break;

  default:
    break;
  }
}
int ObtenerDato(int x, int y, int cara)
{
  nodo *reco = raiz1;
  for (int i = 1; i < cara; i++)
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
          /*Se crea un nodo y se iguala a los nodos de raices incluyendo al auxiliar*/
          // printf("\nz: %d", z);
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->arriba = NULL;
          nuevo->adelante = NULL;
          nuevo->info = 1 + rand() % 100;
          nuevo->sig = NULL;
          raiz1 = nuevo;
          raiz2 = raiz1;
          raiz3 = raiz2;
          aux = raiz3;
          // printf("\nValor raiz3->info: %d", raiz3->info);
          // Se crea un nuevo nodo que será el siguiente del anterior creado
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = 1 + rand() % 100; // 1+1+1
          nuevo->sig = NULL;
          aux->sig = nuevo;
          aux = aux->sig;
          // Ahora raiz1, raiz2 y raiz3 tendrán un nodo siguiente el cual tiene un valor que siempre es el mismo 3
          // printf("\nValor raiz1->info: %d", raiz1->sig->info);
          // printf("\nValor aux->info: %d", aux->info);
        }
        else
        {
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = 1 + rand() % 100;
          nuevo->sig = NULL;
          aux->sig = nuevo;
          aux = aux->sig;
        }
      }
      nuevo = (nodo *)malloc(sizeof(nodo));
      nuevo->info = 1 + rand() % 100;
      nuevo->arriba = NULL;
      raiz3->arriba = nuevo;
      raiz3 = raiz3->arriba;
      aux = raiz3;
      if (y == 4)
      {
        for (int w = 1; w < 5; w++)
        {
          nuevo = (nodo *)malloc(sizeof(nodo));
          nuevo->info = rand() % 100;
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

// Función que inicia el modo gráfico y lo muestra
void grafico()
{

  initwindow(1720, 1080, "CUBO COMPLETO");
  setbkcolor(0);
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
    grafico_cara(i, 0, 100, 0, 100);
  }
  getch();
}

// Función para las filas
void suma_filas()
{
  int fila, suma = 0, cara;
  printf("\n\nFila:");
  scanf("%i", &fila);
  printf("Cara:");
  scanf("%i", &cara);
  for (int x = 1; x <= 5; x++)
  {
    suma = suma + ObtenerDato(fila, x, cara);
  }

  char t[10];
  gcvt(fila, 6, t);
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(60, 200, "SUMA  DE  FILA : ");
  outtextxy(380, 200, t);
  outtextxy(440, 200, "CARA : ");
  gcvt(cara, 6, t);
  outtextxy(600, 200, t);
  gcvt(suma, 6, t);
  //
  settextstyle(3, 0, 6);
  setcolor(RED);
  outtextxy(330, 300, t);

  printf("La suma es: %i\n", suma);
}

// Función para las columnas
void suma_columnas()
{
  int columna, cara, suma = 0;
  printf("\n\nColumna:");
  scanf("%i", &columna);
  printf("Cara:");
  scanf("%i", &cara);
  for (int x = 1; x <= 5; x++)
  {
    suma = suma + ObtenerDato(x, columna, cara);
  }
  char t[10];
  gcvt(columna, 6, t);
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(10, 200, "SUMA  DE  COLUMNA : ");
  outtextxy(450, 200, t);
  outtextxy(500, 200, "CARA : ");
  gcvt(cara, 6, t);
  outtextxy(600, 200, t);
  gcvt(suma, 6, t);
  settextstyle(3, 0, 6);
  setcolor(RED);
  outtextxy(330, 300, t);

  printf("La suma es: %i\n", suma);
}

// Función que suma caras
void suma_caras()
{
  int cara, suma = 0;
  printf("\n\nCara:");
  scanf("%i", &cara);
  for (int x = 1; x <= 5; x++)
  {
    for (int y = 1; y <= 5; y++)
    {
      suma = suma + ObtenerDato(x, y, cara);
    }
  }
  printf("La suma es: %i\n", suma);
  char t[10];
  gcvt(cara, 6, t);
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(10, 200, "SUMA  DE UNA CARA : ");
  outtextxy(450, 200, t);
  gcvt(suma, 6, t);
  settextstyle(3, 0, 6);
  setcolor(RED);
  outtextxy(330, 300, t);
}

// Función que suma el cubo completo
void suma_cubo()
{

  int suma = 0;
  for (int i = 1; i <= 5; i++)
  {

    for (int x = 1; x <= 5; x++)
    {
      for (int y = 1; y <= 5; y++)
      {
        suma = suma + ObtenerDato(x, y, i);
      }
    }
  }
  printf("La suma es: %d\n", suma);
  char t[10];
  gcvt(suma, 6, t);
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(10, 200, "SUMA  DEL CUBO: ");
  setcolor(RED);
  outtextxy(450, 200, t);
}

// Función que imprime cada cara
void grafico_cara(int n, int posx, int posy, int posxO, int posyO)
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

// Función intro cubo
void intro()
{
  int x = -130, y = 0;
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(230, 50, "EL CUBO 5x5x5");
  setcolor(BLUE);
  settextstyle(3, 0, 3);
  outtextxy(370, 170, "Rubio Haro Diego");
  outtextxy(435, 200, "2CM4");
  outtextxy(320, 270, "'Algotimos y Estructuras de Datos'");
  setcolor(RED);
  outtextxy(60, 450, "'PRESIONE CUALQUIER TECLA PARA CONTINUAR'");

  setcolor(MAGENTA);
  line(250 + x, 200 + y, 400 + x, 200 + y);
  line(250 + x, 200 + y, 250 + x, 350 + y);
  line(400 + x, 200 + y, 400 + x, 350 + y);
  line(250 + x, 350 + y, 400 + x, 350 + y);
  line(200 + x, 150 + y, 250 + x, 200 + y);
  line(350 + x, 150 + y, 400 + x, 200 + y);
  line(200 + x, 150 + y, 350 + x, 150 + y);
  line(350 + x, 300 + y, 400 + x, 350 + y);
  line(200 + x, 300 + y, 250 + x, 350 + y);
  line(200 + x, 300 + y, 350 + x, 300 + y);
  line(200 + x, 150 + y, 200 + x, 300 + y);
  line(350 + x, 150 + y, 350 + x, 300 + y);
  getch();
  cleardevice();
}

// Función Menu opciones
int menu()
{
  settextstyle(3, 0, 4);
  setcolor(CYAN);
  outtextxy(RESOLUCION_X / 3 + 50, 30, "MENU");
  outtextxy(100, 120, "1.- Filas");
  outtextxy(100, 170, "2.- Columnas");
  outtextxy(100, 220, "3.- Caras");
  outtextxy(100, 270, "4.- Cubo Completo");

  return getch();
}