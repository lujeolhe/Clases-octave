#include "cabecera.h"

/** \brief Funcion que pide los datos para llamar  a la funcion tabula_funcion()
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


void Maneja_tabulacion(void)
{
    double xa,xb,inc;
    int length,c,archivo;
    char expresion[100];

    Menu_main(2);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n         Ingrese la ecuacion f(x)=  ");
    fgets(expresion,30,stdin);

    length = strlen(expresion);

    if (length > 0 && expresion[length - 1] == '\n')
        expresion[length - 1] = '\0';

    printf("\n         Evaluando:\t%s\n", expresion);
    printf("\n         Ingrese el valor inicial en x: ");
    scanf("%lf",&xa);
    printf("         Ingrese el valor final en x: ");
    scanf("%lf",&xb);
    printf("         Ingrese el valor del incremento: ");
    scanf("%lf",&inc);
    printf("         Desea guardar la salida en un archivo? (1=si/0=no): ");
    scanf("%d",&archivo);

    Tabula_funcion(xa,xb,inc,expresion,archivo);
}

/** \brief Funcion que evalua  y tabula una expresion e imprime datos en pantalla
 *  o en un archivo.
 * \param xi Valor inicial del intervalo
 * \param xf Valor final del intervalo
 * \param inc Incremento en x
 * \param *ap_epr puntador a la expresion a evaluar
 * \param archivo Bandera para la salida a archivo
 * \return 0 o 1 indicando si hubo error
 *
 */


int Tabula_funcion(double xi, double xf, double inc, char *ap_expr,int archivo)
{
    double fx,x;
    FILE *pF;                                                   //Creamos un apuntador de tipo FILE

    if(archivo==1)
    {
        pF = fopen("datos.txt","w");                            //Abrimos el archivo en modo
                                                                //escritura
        if(pF == NULL)                                          //Verificamos si no fue posible abrir el archivo
        {
            puts("Error no se pudo crear el archivo");
            return(1);                                          // Si no fue posible se termina el programa
                                                                //con la senal 1
        }
    }

    x = xi;
    te_variable vars[] = {{"x",&x}};
    te_expr *n1;
    n1 = te_compile(ap_expr,vars,1,0);

    do
    {
        fx = te_eval(n1);
        printf("\n         %10.6lf | %10.6lf ",x,fx);
        if(archivo==1)
               fprintf(pF, "\n%lf  %lf ",x,fx);             //Se escribe en el archivo
                                                            //archivo la cadena
                                                            // usando el //apuntador pF
        x = x + inc;
    }
    while(x <= xf);

    if(archivo==1)
        fclose(pF);                                         // Cerramos el archivo

    te_free(n1);

    printf("\n\n");
    system("pause");

    return 0;

}
