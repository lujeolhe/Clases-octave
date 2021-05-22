%Ejercicio 3
%Ejercio donde aplicamos metodo de Euler para resolver EDO en un circuito RC
%
FM=10000; %Frecuencia de Muestreo de la Simulacion

%Teorema de Nyquis o Teroema de Muestreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.05;

A=10;
A1=9;

f=50;

w=2*pi*f;
%Corriente alterna
V_x=A*sin(2*pi*f*t);


R1=1;
C1=0.001;




Vr1=((-A*w*R1*C1)/((w^2*R1^2*C1^2)+1))*exp(-t/(R1*C1))+((A*w^2*R1^2*C1^2)/((w^2*R1^2*C1^2)+1))*sin(w*t)+((A*w*R1*C1)/((w^2*R1^2*C1^2)+1))*cos(w*t);
Vc1=((A*w*R1*C1)/((w^2*R1^2*C1^2)+1))*exp(-t/(R1*C1))+((A)/((w^2*R1^2*C1^2)+1))*sin(w*t)-((A*w*R1*C1)/((w^2*R1^2*C1^2)+1))*cos(w*t);
Vsum=Vr1+Vc1;

figure 1
plot(t,V_x,t,Vr1,t,Vc1);
title('Señales de Voltajes')

xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R1}','V_{C1}','Vt(t)');

%Calculo de Respuesta por metodo de Euler
V_x=A*parabola(2*pi*f*t);

q_t=zeros(1,length(t));
dq_t=zeros(1,length(t));

q_t(1,1)=0.2*A; %carga inicial
dq_t(1,1)=(V_x(1,1)-q_t(1,1)/C1)/R1; %corriente inicial

for i=2:length(t)
  q_t(1,i)=q_t(1,i-1)+1/FM*dq_t(1,i-1);
  dq_t(1,i)=(V_x(1,i)-q_t(1,i)/C1)/R1;
endfor

figure 2

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ok

plot(t,V_x,t,q_t/C1,t,dq_t*R1,t, -V_x+q_t/C1+dq_t*R1);
title('Señales de Voltajes Euler')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{C1}','V_{R1}');






%Hacer la integral del valor eficas a mano pendiente 
%hacer lo de el excel ok
%Vrms ok
%%Triangular grafica igual que la cuadrada y diente de sierra ok
%