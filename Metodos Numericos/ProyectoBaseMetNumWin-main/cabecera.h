#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tinyexpr.h"

/** \file cabecera.h
 *
 *  o     o          o  o    o                 .oPYo.
 *  8b   d8          8  8b   8                 8   `8
 *  8`b d'8 .oPYo.  o8P 8`b  8 o    o ooYoYo. o8YooP' .oPYo. .oPYo. .oPYo.
 *  8 `o' 8 8oooo8   8  8 `b 8 8    8 8' 8  8  8   `b .oooo8 Yb..   8oooo8
 *  8     8 8.       8  8  `b8 8    8 8  8  8  8    8 8    8   'Yb. 8.
 *  8     8 `Yooo'   8  8   `8 `YooP' 8  8  8  8oooP' `YooP8 `YooP' `Yooo'
 *
 *  @copyright 2021 Enrique Martinez Roldan
 *  @license   https://github.com/kique/ProyectoBaseMetNumWin/blob/main/LICENSE
 *  @version   0.01
 *  @link      https://github.com/kique/ProyectoBaseMetNumWin
 *
 *  @author Enrique Martinez Roldan (metodos@e-roldan.net)
 *  @author Jose Antonio Sixto Berrocal(jsixto@ipn.mx)
 *  @author Manuel Torres Sabino
 *  @author Javier E. Aviles Nunez
 *
 *  \brief Estructura de datos para la matrices
 */

typedef struct{
    int f; /**< Numero de filas de la matriz */
    int c; /**< Numero de columnas de la matriz */
    int e; /**< Almacena el error */
    double **a; /**< Apuntador a apuntador para la matriz dinamica */

}mat;

/** \brief Estructura de datos que contiene la configuracion de la grafica para gnuplot
 *
 */

 struct GrafDat{
    char funcion[100]; /**< Arreglo que almacena la expresion matematica (funcion) a analizar*/
    char archivo[100]; /**< Arreglo que contiene el nombre del archivo a graficar */
    char titulo[100];  /**< Titulo de la grafica */
    char ejex[100];    /**< Leyenda para el eje x */
    char ejey[100];    /**< Leyenda para el eje y */
    char tipo_gra;     /**< Variable que indica si se grafica una funcion o un archivo de datos */
    float xmin;        /**< Valor minimo del eje x */
    float xmax;        /**< Valor maximo del eje x*/
};

/*
 * Prototipos de las funciones de los menus
 */

void Menu_main(int m);
void Menu_graficacion(int m);
void Menu_mensaje(int m);
void Menu_creditos(void);

/*
 * Prototipos de las funciones de graficacion
 */
void Crea_grafica();
void Maneja_graficacion(struct GrafDat *dtgraf);
void Grafica(struct GrafDat*);

/*
 * Prototipos de las funciones de analisis de expresiones y tabulacion
 */

void Parser_gnuplot(char *g);
double fx(char *f,double xf);
int Parser_error(char *f);
int Tabula_funcion(double xi, double xf, double inc, char *ap_expr,int archivo);
void Maneja_tabulacion();

/*
 * Prototipos de las funciones de localizacion de raices
 */

void LeeDatos_Biseccion(void);
void Biseccion(char *f,double Xa,double Xb,int cifras,int maxit);

/*
 * Prototipos de las funciones de tangente
 */
void LeeDatos_tangente(void);
void tangente(char *f,double Xa,double Xb,int cifras,int maxit);
/*
 * Prototipos de las funciones de manejo de matrices
 */

mat Crea_Matriz(int Filas,int Columnas);
void Libera_Matriz(mat Matriz);
mat Suma_Mat(mat A,mat B);
mat Resta_Mat(mat A,mat B);
mat Multiplica_Mat(mat A,mat B);
mat Copia_Mat(mat A,mat B);
double Mat_Determinante(mat A);


#endif // CABECERA_H_INCLUDED
