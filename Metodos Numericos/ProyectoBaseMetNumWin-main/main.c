#include "cabecera.h"

/** @file main.c
 *  @brief Funcion principal con el menu general
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


int main(void)
{
    int resp = 1;

    do
    {
        Menu_main(resp);
        printf("\n        Seleccione una Opcion: ");
        scanf("%d",&resp);

        switch(resp)
        {
        case 1:
            Crea_grafica();
            break;
        case 2:
            Maneja_tabulacion();
            resp = 1;
            break;
        case 3:
            LeeDatos_Biseccion();
            resp = 1;
            break;
        case 4:
            LeeDatos_tangente();
            resp = 1;
            break;
        case 0:
            Menu_creditos();
            exit(0);
        default:
            resp = -1;
        }
    }
    while(resp != 0);

    return 0;
}

void LeeDatos_tangente(void)
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

    tangente(expr,xa,xb,cifras,maxit);

    printf("\n\n");
    system("pause");
}

