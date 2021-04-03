#include "cabecera.h"

/** \file menus.c
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
 * \brief Funcion que imprime el menu principal
 * \param void
 * \return void
 */

void Menu_main(int m)
{
    system("cls");
    printf("        +------------------------------------------------------------+\n");
    printf("        |             MENU GENERAL DE METODOS NUMERICOS              |\n");
    printf("        +------------------------------------------------------------+\n");
    printf("        |                                                            |\n");
    printf("        | 1.- Graficacion                                            |\n");
    printf("        | 2.- Evaluar una Funcion Matematica                         |\n");
    printf("        | 3.- Localizar Raices                                       |\n");
    printf("        | 4.- Metodo de la tangente                                  |\n");
    printf("        | 0.- Salir                                                  |\n");
    printf("        +------------------------------------------------------------+\n");

    if(m > 5 || m < 0){
        printf("        |          WARNING:     !!!  Opcion Incorrecta  !!!          |\n");
        printf("        +------------------------------------------------------------+\n");
    }
    if(m == 1){
        printf("        |                                                            |\n");
        printf("        +------------------------------------------------------------+\n");
    }
    if(m == 2){
        printf("        |          SE EJECUTA:          Eval. de Funcion             |\n");
        printf("        +------------------------------------------------------------+\n");
    }
    if(m == 3){
        printf("        |          SE EJECUTA:            Localiza Raices            |\n");
        printf("        +------------------------------------------------------------+\n");
    }
    if(m == 4){
        printf("        |          SE EJECUTA:            Metodo de la tangnete      |\n");
        printf("        +------------------------------------------------------------+\n");
    }
}

/** \brief Funcion que imprime el menu para graficacion
 *
 * \param void
 * \return void
 *
 */

void Menu_graficacion(int m)
{
    system("cls");
    printf("        +-------------------------------------------------------------+\n");
    printf("        |                     MENU GRAFICACION                        |\n");
    printf("        +-------------------------------------------------------------+\n");
    printf("        |                                                             |\n");
    printf("        | 1.- Graficar una Expresion Matematica                       |\n");
    printf("        | 2.- Graficar datos desde un archivo                         |\n");
    printf("        | 3.- Graficar una Expresion Matematica y datos de un Archivo |\n");
    printf("        |                                                             |\n");
    printf("        | 0.- Salir                                                   |\n");
    printf("        +-------------------------------------------------------------+\n");

    if(m > 4 || m < 0){
        printf("        |          WARNING:     !!!  Opcion Incorrecta  !!!           |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 1){
        printf("        |          SE EJECUTA:      Graf. Expresion Matematica        |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 2){
        printf("        |          SE EJECUTA:             Graf. Datos                |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 3){
        printf("        |          SE EJECUTA:         Graf. Datos y Funcion          |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 4){
        printf("        |                                                             |\n");
        printf("        +-------------------------------------------------------------+\n");
    }

}
void Menu_tangente(int m)
{
    system("cls");
    printf("        +-------------------------------------------------------------+\n");
    printf("        |                     MENU GRAFICACION                        |\n");
    printf("        +-------------------------------------------------------------+\n");
    printf("        |                                                             |\n");
    printf("        | 1.- Graficar una Expresion Matematica                       |\n");
    printf("        | 2.- Graficar datos desde un archivo                         |\n");
    printf("        | 3.- Graficar una Expresion Matematica y datos de un Archivo |\n");
    printf("        |                                                             |\n");
    printf("        | 0.- Salir                                                   |\n");
    printf("        +-------------------------------------------------------------+\n");

    if(m > 4 || m < 0){
        printf("        |          WARNING:     !!!  Opcion Incorrecta  !!!           |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 1){
        printf("        |          SE EJECUTA:      Graf. Expresion Matematica        |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 2){
        printf("        |          SE EJECUTA:             Graf. Datos                |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 3){
        printf("        |          SE EJECUTA:         Graf. Datos y Funcion          |\n");
        printf("        +-------------------------------------------------------------+\n");
    }
    if(m == 4){
        printf("        |                                                             |\n");
        printf("        +-------------------------------------------------------------+\n");
    }

}

void Menu_creditos(void)
{
system("cls");
printf("\n.######..#####...##..##.                                                         ");
printf("\n...##....##..##..###.##.                                                         ");
printf("\n...##....#####...##.###.                                                         ");
printf("\n...##....##......##..##.                                                         ");
printf("\n.######..##......##..##.                                                         ");
printf("\n........................                                                         ");
printf("\n.######...####...######..##...##..######..........######...####....####..........");
printf("\n.##......##........##....###.###..##.................##...##..##..##..##.........");
printf("\n.####.....####.....##....##.#.##..####..............##....######..##.............");
printf("\n.##..........##....##....##...##..##...............##.....##..##..##..##....##...");
printf("\n.######...####...######..##...##..######..........######..##..##...####.....##...");
printf("\n.................................................................................");
printf("\n                                                                                 ");
printf("\n PROYECTO BASE DE METODOS NUMERICOS Version 0.01                                 ");
printf("\n                                                                                 ");
printf("\n                    AUTORES:                                                   \n");
printf("\n            Enrique Martinez Roldan                                              ");
printf("\n            Jose A. Sixto Berrocal                                               ");
printf("\n            Manuel Torres Sabino                                                 ");
printf("\n            Javier E. Aviles Nunez                                               ");
printf("\n\n       Software libre con licencia GPLv3                                   \n\n");
}
