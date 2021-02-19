%Ejercicio 1
FM=1000; %Frecuencia de Muestreo de la Simulacion
%Teorema de Nyquis o Teroema de Muetreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
t=0:1/FM:.1;
A=12;
f=60;
V_x=A*sin(2*pi*f*t);

R1=100;
R2=200;
R3=20;
Req=R1+R2+R3;
i_x=V_x/Req;
Vr1=i_x*R1;
Vr2=i_x*R2;
Vr3=i_x*R3;
%Ley de Kirchhoff
Vt=Vr1+Vr2+Vr3;

plot(t,V_x,t,Vr1,t,Vr2,t,Vr3,t,Vt);
grid on
