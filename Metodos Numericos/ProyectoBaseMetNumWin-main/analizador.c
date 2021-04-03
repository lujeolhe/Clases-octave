#include "cabecera.h"

/** \file analizador.c
 * \brief Analizador de expresiones, esta funcion permite evaluar una función fx
 *         a partir de la cadena f
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
 */

double fx(char *f,double xf)
{
    int err;
    double Fx;
    double x;
    int num_vars=1;

    te_variable vars[] = {{"x", &x}}; /* Almacena nombres y apuntadores */
    x=xf;
    te_expr *expr = te_compile(f, vars, num_vars, &err);

    Fx=te_eval(expr);
    te_free(expr);
    return Fx;
}

/** \brief Funcion que muestra un mensaje de error al usuario en la cadena f
 *         que contiene la funcion
 *
 * \param *f
 * \return 0
 *
 */
 int Parser_error(char *f)
{
    double x;
    int num_vars=1;
    int err;

    te_variable vars[] = {{"x", &x}};
    te_expr *expr = te_compile(f, vars, num_vars, &err);

    if(err!=0)
    {
        printf("\n         Error cerca de aqui:");
        printf("\n\t\t%s",f);
        printf("\n\t\t%*s^\n", err-1, "");
        system("pause");
        return err;
    }
    else
        return 0;
}
