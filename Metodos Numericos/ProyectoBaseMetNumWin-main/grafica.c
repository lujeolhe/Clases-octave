#include "cabecera.h"

/** \file grafica.c
 * \brief Funcion que inicia el proceso de graficacion determinando si se grafica
 * una expresion matematica o si se grafican datos leidos de un archivo.
 *
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
 *
 */

void Crea_grafica()
{
    struct GrafDat dt;                  /*Se declara un estructura tipo GrafDat */
    int resp = 4;

    do
    {
        Menu_graficacion(resp);         /* Imprime el menu de graficacion */
        printf("\n        Seleccione una Opcion: ");
        scanf("%d",&resp);

        switch(resp)
        {
        case 1:
            dt.tipo_gra='f';            /* se establece graficar una funcion*/
            Maneja_graficacion(&dt);    /* Se llama a la funcion manejadora enviando*/
            resp = 4;                   /* la direccion de la estructura dt*/
            break;
        case 2:
            dt.tipo_gra='p';            /* se establece graficar datos de un archivo*/
            Maneja_graficacion(&dt);    /* Se llama a la funcion manejadora enviando*/
            resp = 4;                   /* la direccion de la estructura dt*/
            break;
        case 3:
            dt.tipo_gra='a';            /* se establece graficar datos de un archivo*/
            Maneja_graficacion(&dt);    /* Se llama a la funcion manejadora enviando*/
            resp = 4;                   /* la direccion de la estructura dt*/
            break;
        case 0:
            break;
        default:
            resp = -1;
        }
    }
    while(resp != 0);
}

/** \brief Funcion que pide los datos necesarios para graficar
 *
 * \param *dtgrar apuntador a la estructura tipo GrafDat
 *
 * \return void
 *
 */

void Maneja_graficacion(struct GrafDat *dtgraf)
{
    float min, max;
    char expr[100];
    int err;

    if (dtgraf->tipo_gra == 'f')
    {
        do{
            Menu_graficacion(1);
            printf("\n         Ingrese la funcion a graficar: f(x)= ");

            fflush(stdin);
            scanf("%s",expr);

            err=Parser_error(expr);
        }while(err != 0);

        Parser_gnuplot(expr); /* Acondiciona la expresion cambiando el operador de exponenciacion */
        strcpy(dtgraf->funcion, expr);
    }
    if (dtgraf->tipo_gra == 'p')
    {
        Menu_graficacion(2);
        strcpy(dtgraf->archivo,"datos.txt");
    }
    if (dtgraf->tipo_gra == 'a')
    {
        do{
            Menu_graficacion(3);
            printf("\n         Ingrese la funcion a graficar: f(x)= ");

            fflush(stdin);
            scanf("%s",expr);

            err=Parser_error(expr);
        }while(err != 0);

        Parser_gnuplot(expr); /* Acondiciona la expresion cambiando el operador de exponenciacion */
        strcpy(dtgraf->funcion, expr);
        strcpy(dtgraf->archivo,"datos.txt");
    }
    strcpy(dtgraf->titulo, "Grafica de f(x)");
    strcpy(dtgraf->ejex, "x");
    strcpy(dtgraf->ejey, "f(x)");

    printf("\n         Ingrese el valor minimo en x: ");
    scanf("%f",&min);
    dtgraf->xmin=min;
    printf("\n         Ingrese el valor maximo en x: ");
    scanf("%f",&max);
    dtgraf->xmax=max;

    Grafica(dtgraf);/**< Se llama a la funcion que ejecuta la graficacion con gnuplot */
}

/** \brief Funcion que transforma la cadena f de caracteres con la expresion a graficar,
 *   al formato adecuado para gnuplot; en especifico cambia "^" por "**"
 * \param *g apuntador a la cadena con la expresion a graficar
 *
 * \return void
 *
 */

void Parser_gnuplot(char *g)
{
    int i=0,j=0;
    char G[100];


    while(g[i] != '\0')
    {
        if(g[i]=='^'){
            G[j]='*';
            j++;
            G[j]='*';
            j++;
        }
        else{
            G[j]=g[i];
            j++;
        }
        i++;
    }

    G[j]='\0';

    strcpy(g,G);
}

/** \brief Funcion que permite graficar una serie de puntos o una funcion matematica
 * con la configuracion contenida en el archivo config.gp
 * \param  *datos Apuntador a la estructura con la informacion a graficar
 *
 * \return void
 *
 */

void Grafica(struct GrafDat *datos)
{
    FILE *gnuplotPipe;

     gnuplotPipe = popen ("gnuplot -persistent", "w");

/********************************************//**
 *  ... Manda comandos a GNUPLOT, incluidas las
 *  ... configuraciones guardadas en el archivo
 *  ... config.gp
 ***********************************************/
    fprintf(gnuplotPipe, "set title \"Luis Pablo Gonzalez Galvez %s\"\n",datos->titulo);
    fprintf(gnuplotPipe, "load \"config.gp\"\n");
    fprintf(gnuplotPipe, "set xrange[%lf:%lf]\n",datos->xmin-0.3,datos->xmax+0.3);
    fprintf(gnuplotPipe, "set arrow from %f,0 to %f,0 as 5\n",datos->xmin-0.3,datos->xmax+0.3);
    fprintf(gnuplotPipe, "set xlabel \"%s\"\n",datos->ejex);
    fprintf(gnuplotPipe, "set ylabel \"%s\"\n",datos->ejey);

/********************************************//**
 *  ... Crea las graficas a partir de una funcion
 *  ... o de un archivo de puntos
 ***********************************************/
    if(datos->tipo_gra == 'f')
    {
        Parser_gnuplot(datos->funcion);
        fprintf(gnuplotPipe, "plot %s w l ls 9 \n",datos->funcion);
    }
    if(datos->tipo_gra == 'p')
    {
        fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w p ls 5 \n",datos->archivo);
    }
    if(datos->tipo_gra == 'a')
    {
        Parser_gnuplot(datos->funcion);
        fprintf(gnuplotPipe, "plot %s w l ls 7, \"%s\" using 1:2\n",datos->funcion,datos->archivo);
    }

/********************************************//**
 *  ... Cierra la tuberia
 ***********************************************/
    pclose(gnuplotPipe);
}
