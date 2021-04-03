#include "cabecera.h"

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
        m=(fx(f,Xb+h))-fx(f,Xb)))/h;
        b=fx(f,Xb)-m*Xb;
        Xr=b/m;
        if (floor(Xb*pow(10,cifras))==floor(fabs(Xr*pow(10,cifras))){
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
        }
        Ea = fabs((Xr - Xrant) / Xr) * 100;
        Xrant = Xr;
        iter = iter + 1;*/

        printf("\n         |La raiz es: %10.3lf en %3d iteraciones y un error = %10.3lf\t|",Xr,iter,Ea);

    }while(Ea > tol && iter < maxit);

}
