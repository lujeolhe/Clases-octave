FM=1000 %Frecuencia de Muestreo de la Simulacion
%Teorema de Nyquis o Teroema de Muetreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
t=0:1/FM:.2;


A=1;
f=1;
ph=0;
V_x=A*sin(2*pi*f*t-ph);

A2=1;
f2=200;
ph2=pi/2;
c_CD=1
V2_x=A2*sin(2*pi*f2*t-ph2)+c_CD;

V3_x=c_CD*ones(1,length(t));
plot(t,V_x,t, V2_x,t,V3_x);
grid on
