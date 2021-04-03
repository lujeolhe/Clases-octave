#include "cabecera.h"

/** \file raices.c
 * \brief Funcion que lee datos de entrada para llamar a la funcion de
 *  Biseccion
 * \param void
 * \return void
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
 */

void LeeDatos_Biseccion(void)
{
    char expr[300];    /// *expr  apuntador a la cadena que contendra la expresion matematica
    int err;            /// err    variable que indica si ubo error en la expresion leida
    int cifras;         /// cifras Numero de cifras significatovas
    int maxit;          /// maxit  Numero maximo de iteraciones
    double xa;          /// xa     Valor inicial del intervalo
    double xb;          /// xb     Valor finl del intervalo
    int c,length;

    do{
        Menu_main(3);
        printf("\n         Ingrese la ecuacion f(x)=  ");

        fflush(stdin);
        scanf("%s",expr);

        err=Parser_error(expr);
    }while(err != 0);


    printf("\n         De el numero de cifras significativas n: ");
    scanf("%d",&cifras);
    printf("         De el numero maximo de iteraciones: ");
    scanf("%d",&maxit);
    printf("         De el valor inicial del intervalo xa: ");
    scanf("%lf",&xa);
    printf("         De el valor inicial del intervalo xb: ");
    scanf("%lf",&xb);

    Biseccion(expr,xa,xb,cifras,maxit);

    printf("\n\n");
    system("pause");
}

/** \brief Metodo de la biseccion
 *
 * \param *f Apuntador a la cadena con la expresion a analizar
 * \param Xa Valor inicial del intervalo
 * \param Xb Valor final del intervalo
 * \param cifras Numero de cifras significativas consideradas
 * \param maxit Numero maximo de iteraciones
 * \return void
 *
 */

void Biseccion(char *f,double Xa,double Xb,int cifras,int maxit)
{
    double Xr, Xrant=0, Ea, tol;
    int iter = 0,err = 0;

    tol = 0.5 * pow(10,(2 - cifras));


    if(fx(f,Xa) * fx(f,Xb) > 0.0){
        printf("\n         Error: Prueba con otro intervalo...");
        err = -1;
        return -1;
    }

    do{
        Xr = (Xa + Xb) / 2.0;
        if(fx(f,Xa) * fx(f,Xr) < 0.0){
            Xb = Xr;
        }
        else{
            Xa = Xr;
        }
        Ea = fabs((Xr - Xrant) / Xr) * 100;
        Xrant = Xr;
        iter = iter + 1;

        printf("\n         |La raiz es: %10.3lf en %3d iteraciones y un error = %10.3lf\t|",Xr,iter,Ea);

    }while(Ea > tol && iter < maxit);

}

