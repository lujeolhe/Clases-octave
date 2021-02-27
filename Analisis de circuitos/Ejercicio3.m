%Ejercicio 3
FM=1000; %Frecuencia de Muestreo de la Simulacion
%Teorema de Nyquis o Teroema de Muetreo:
%Para muetrear una se�al de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una se�al de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.2;
A=120;
A1=9;
f=60;
%Corriente alterna
V_x=A*sin(2*pi*f*t);

R1=1000;
C1=0.001;

Vr1=A*exp(-t/(R1*C1));
Vc1=A*(1-exp(-t/(R1*C1)));

figure 1
plot(t,V_x,t,Vr1,t,Vc1);
title('Se�ales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C1}');

figure 2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ok
%Corriente directa
V1_t=A1*ones(1,length(t));

Vr1D=A1*exp(-t/(R1*C1));
Vc1D=A1*(1-exp(-t/(R1*C1)));

plot(t,V1_t,t,Vr1D,t,Vc1D);
title('Voltajes de R y C en corriente continua')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C1}');
%Hacer la integral del valor eficas a mano
%hacer lo de el excel
%Vrms