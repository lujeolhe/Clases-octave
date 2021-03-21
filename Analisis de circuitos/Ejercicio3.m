%Ejercicio 3
FM=1000; %Frecuencia de Muestreo de la Simulacion
%Teorema de Nyquis o Teroema de Muestreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.1;
A=120;
A1=9;
f=20;
w=2*pi*f;
%Corriente alterna
V_x=A*sin(2*pi*f*t);

R1=1000;
C1=0.00001;


Vr1=((A*C1*R1)/((w^2*R1^2*C1^2)+1))*(-w*exp(-t/(R1*C1))+w*cos(w*t)+(w^2*R1*C1)*sin(w*t));
Vc1=((A)/((w^2*R1^2*C1^2)+1))*(w*R1*C1*exp(-t/(R1*C1))+sin(w*t)-(w*R1*C1)*cos(w*t));
Vt_x=Vr1+Vc1;

plot(t,V_x,t,Vr1,t,Vc1);
title('Señales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C1}','Vt(t)');

figure 2
%Corriente directa
V_x1=A1*ones(1,length(t));

Vr1D=A1*exp(-t/(R1*C1));
Vc1D=A1*(1-exp(-t/(R1*C1)));

plot(t,V_x1,t,Vr1D,t,Vc1D);
title('Señales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C1}');
%Hacer la integral del valor eficas a mano
%hacer lo de el excel
%Vrms
%%Triangular grafica igual que la cuadrada y diente de sierra
%