%Ejercicio 2
FM=1000; %Frecuencia de Muestreo de la Simulacion
%Teorema de Nyquis o Teroema de Muetreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.1;
A=12;
f=60;
%V_x=A*sin(2*pi*f*t);
V_x=A*ones(1,length(t));

R1=100;
R2=220;
R3=120;
R4=1000;
R5=2200;
R6=1000;

Req1=1/(1/R2+1/R4+1/R5)
Req2=1/(1/R3+1/R6)
ReqT=Req1+Req2+R1
I_x=V_x/ReqT;
Vr1=I_x*R1;

VReq2=I_x*Req2;
VReq1=I_x*Req1;

Vt_x=Vr1+VReq1+VReq2;
%figure 1
subplot(2,2,1)
plot(t,V_x);
title('Señal de voltaje normal')
xlabel('t')
ylabel('V_x')
%figure 2
subplot(2,2,2)
plot(t,Vr1);
title('Señal del voltaje de R1')
xlabel('t')
ylabel('Vr1')
%figure 3
subplot(2,2,3)
plot(t,Vt_x);
title('Señal de voltaje suma')
xlabel('t')
ylabel('Vt_x')
%figure 4
subplot(2,2,4)
plot(t,VReq1);
title('Señal de Voltaje de R5')
xlabel('t')
ylabel('VReq1')

figure 2
plot(t,V_x,t,Vr1,t,Vt_x,t,VReq1);
title('Señales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_T','V_{Req1}');

%%Calculo de la potencia en el resistor 1
Pr1=Vr1.^2/R1;
figure 3
plot(t,Pr1)
xlabel('t')
ylabel('P_R1')
max(Pr1)

%%Calculo del VRMS
figure 4
plot(t,V_x.^2);
kernel=V_x.^2*1/FM;
figure 5
plot(t,kernel);
intV=sum(kernel)
divV=intV/.1
Vrms=sqrt(divV)


%%Poner detalles a las graficas
%%Cada una separada
%Vrms