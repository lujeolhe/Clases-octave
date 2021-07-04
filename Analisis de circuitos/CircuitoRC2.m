%Circuito RC en DC
FM=1000; %Frecuencia de Muestreo de la Simulacion
t=0:1/FM:1;
f=10;
V=5;
R1=100;
R2=10;
C=0.02;
Vc=-(V*R2)/(R1+R2)*exp(((R1+R2)/(C*R1*R2))*t)+(V*R2)/(R1+R2);
I1=(V-Vc)/R1;
Vr1=I1*R1;
VT=Vr1+Vc-V;
V_x=V*ones(1,length(t));
plot(t,V_x,t,Vr1,t,Vc,t,VT);
title('Señales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C}');
%Circuito RC en DA
figure 2
t2=0:1/FM:0.5;
K=(R1+R2)/(C*R2*R1);
w=2*pi*f;
V2=5*sin(w*t2);
a=(5*w)/(K^2+w^2);
b=(5*K)/(K^2+w^2);
Vc2=a*exp(-K*t2)+b*sin(w*t2)-b*cos(w*t2);
I2=(V2-Vc2)/R1;
Vr1_2=R1*I2;
VT2=Vr1_2+Vc2-V2;
plot(t2,V2,t2,Vr1_2,t2,Vc2);
title('Señales de Voltajes')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C}');

