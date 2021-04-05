#include "cabecera.h"
/** \file Metodo_de_la_tangente.h
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
void tangente(char *f,double Xa,double Xb,int cifras,int maxit)
{
    double Xr, Xrant=0, Ea, tol, b, m, h=0.001;
    int iter = 0,err = 0;

    tol = 0.5 * pow(10,(2 - cifras));


    if(fx(f,Xa) * fx(f,Xb) > 0.0){
        printf("\n         Error: Prueba con otro intervalo...");
        err = -1;
        return -1;
    }

    do{
        m=(fx(f,Xb+h)-fx(f,Xb))/h;
        b=fx(f,Xb)-m*Xb;
        Xr=b/m;
        if ((floor(Xb*pow(10,cifras)))==(floor(fabs(Xr*pow(10,cifras))))){
          break;
        }
        iter++;
        Xb=-Xr;
        /*
        Xr = (Xa + Xb) / 2.0;
        if(fx(f,Xa) * fx(f,Xr) < 0.0){
            Xb = Xr;
        }
        else{
            Xa = Xr;
        }*/
        Ea = fabs((Xr - Xrant) / Xr) * 100;
        Xrant = Xr;


        printf("\n         |La raiz es: %10.3lf en %3d iteraciones y un error =  %10.3lf \t|",-Xr,iter, Ea);

    }while(Ea > tol && iter < maxit);

}
