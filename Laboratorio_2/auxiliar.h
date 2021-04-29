#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int longitud( char *arreglo );

bool comparacion( int longi, char *ar1, char *ar2 );

int obtener_digitos( int num );

char convertira_caracter( int n_ent );

void imprimir_arreglos( char *a1 );

char *rellenar( char *ar, int n );

void eliminacion_impresion( char *ar );

void impresion_numeros( char *og );

void impresion_original( char *ar );

void impresion_texto( char *ar, char *ar_2 );

long int dividir_sumar( int veces , long long int n, char *ar );

char *ceros_func( char *ar, char *n_ar , int ceros, int l );

int valor_letra( char letra );

int val_fil( char letra );

int val_colum( char *ar, int n );

void imprimir_cuadro_magico( int *matriz, int elementos );

bool repeticion_m(int *mat, int elementos);

int recursiva( int fvert, int cvert, int n, int caminos);

int **matriz( int *mat, int elemntos );

void m_rotada_90( int *mat );

void m_rotada_180( int *mat );

void m_rotada_270( int *mat );

bool verif_mat( int *mA, int *mB );

void coordenadas_cruce( int *mA, int *mB, int *cruce );

long long int factorial( int n );

char *permutaciones( int y, int num );

void eliminar( char *p, int n );

int suma_divisores( int n );

int suma_sin_repetir( int *m, int num );

#endif // AUXILIAR_H

//Codigos para depuracion

//EJERCICIO #1

/*

  RESPUESTAS EJ#1

  1) La direccion de memoria del arreglo es (en mi pc) 0x61fdf0 y
     se usan 4 bytes para cada elemneto, ya que son enteros

  2) La direccion es &array[3] = 0x61fdfc y contiene: 3 y 6, antes y despues del cambio respectivamente

  3) La funcion B cambia o voltea los elemntos del arreglo


EJERCICIO #3

unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

RESPUESTAS:

  1)  b --> direccion de memoria (&b[0][0])
  2)  b+2 --> direccion de memoria (&b[2][0])
  3)  *(b+2) --> direccion de memoria (&b[2][0])
  4)  *(b+2) +1  --> direccion de memoria (&b[2][1])
  5)  *(*(b+2) +1) --> elemnto almacenado en (b[2][1] = 39)
  6)  b[3][1] -->  elemnto almacenado (3)
  7)  *b++ --> Operacion NO valida debido a cómo funcionan los arreglos


  *ENLACES EJERCICIOS-PROBLEMAS ARDUINO:

  Ejercicio #4
  https://www.tinkercad.com/things/i3rtield35k

  Ejercicio #5
  https://www.tinkercad.com/things/48CfIqFJLJT

  Problema #1
  https://www.tinkercad.com/things/jm85ex5LWc2

*/

//int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//fun_b(array, 10);


    //EJERCICIO #2

/*  double notas[3] = { 1.5, 2.5, 3.0 } ;
double promedio_notas, suma_notas ;

fun_c(notas,3,&promedio_notas,&suma_notas);     //Ejemplo verificacion

*/
