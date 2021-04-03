#include "cabecera.h"

/**  \file arreglos.c
 * \brief Funcion que crea una matriz dinamica
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
 * \param Filas  Numero de filas de la matriz
 * \param Columnas  Numero de columnas de la matriz
 * \return matriz  Devuelve una estructura de datos timpo mat
 *
 */

mat Crea_Matriz(int Filas,int Columnas)
{
    mat matriz;
    int i;

    matriz.a = (double **)malloc (Filas*sizeof(double *));

    for (i=0;i<Filas;i++)
        matriz.a[i] = (double *) malloc (Columnas*sizeof(double));

	if (matriz.a == NULL)
	{
		matriz.e=-1;
        return matriz;
	}
	else
        matriz.e = 0;

	matriz.f=Filas;
	matriz.c=Columnas;

	return matriz;
}

/** \brief Funcion que libera la memoria ocupada por una matriz dinamica
 *
 * \param Matriz Esturctura de datos tipo mat
 *
 * \return void
 *
 */


void Libera_Matriz(mat Matriz)
{
    int i;

    for(i=0; i<Matriz.f; i++) {
        free(Matriz.a[i]);
    }

    free(Matriz.a);

    Matriz.a= NULL;
}

/** \brief Funcion que suma dos matrices A+B
 *
 * \param A Estructura de datos tipo mat para la matriz A
 * \param B Estructura de datos tipo mat para la matriz B
 * \return S Estructura de datos tipo mat con la suma de A+B
 *
 */

mat Suma_Mat(mat A,mat B)
{
    mat S;
    int i,j;

    S=Crea_Matriz(A.f,A.c);

    if(A.f!=B.f || A.c!=B.c)
    {
		S.e=-1;
        return S;
    }

    for(i=0;i<A.f;i++)
    {
        for(j=0;j<A.c;j++)
        {
            S.a[i][j]=A.a[i][j]+B.a[i][j];
        }
    }

    return S;
}

/** \brief Funcion que resta dos matrices A-B
 *
 * \param A Estructura de datos tipo mat para la matriz A
 * \param B Estructura de datos tipo mat para la matriz B
 * \return S Estructura de datos tipo mat con la suma de A-B
 *
 */

mat Resta_Mat(mat A,mat B)
{
    mat R;
    int i,j;

    R=Crea_Matriz(A.f,A.c);

    if(A.f!=B.f || A.c!=B.c)
    {
		R.e=-1;
        return R;
    }

    for(i=0;i<A.f;i++)
    {
        for(j=0;j<A.c;j++)
        {
            R.a[i][j]=A.a[i][j]-B.a[i][j];
        }
    }

    return R;
}

/** \brief Funcion que multiplica dos matrices A*B
 *
 * \param A Estructura de datos tipo mat para la matriz A
 * \param B Estructura de datos tipo mat para la matriz B
 * \return S Estructura de datos tipo mat con la suma de A*B
 *
 */

mat Multiplica_Mat(mat A,mat B)
{
    mat M;
    int i,j,k;

    M=Crea_Matriz(A.f,B.c);

    if(A.c!=B.f)
    {
		M.e=-1;
        return M;
    }

    for(i=0;i<A.f;i++){
        for(j=0;j<B.c;j++){
            M.a[i][j]=0.0;
            for(k=0;k<A.c;k++){
                    M.a[i][j]=M.a[i][j]+A.a[i][k]*B.a[k][j];
            }
        }
    }

    return M;
}

/** \brief Funcion que copia la matriz A en la matriz B
 *
 * \param A Estructura de datos tipo mat para la matriz A
 * \param B Estructura de datos tipo mat para la matriz B
 * \return
 *
 */

mat Copia_Mat(mat A,mat B)
{
    int i,j;

    for(i=0;i<A.f;i++){
        for(j=0;j<A.c;j++){
            B.a[i][j]=A.a[i][j];
        }
    }
}


