%Ejercicio 4 
%Ejercio donde aplicamos metodo de Euler para resolver EDO en un circuito RC
%
FM=1000; %Frecuencia de Muestreo de la Simulacion

%Teorema de Nyquis o Teroema de Muestreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.2;

V=10;
R=1;
L=0.01;
C=0.001;
f=50;
%V_t=V*ones(1,length(t));
V_t=V*sin(2*pi*f*t);

q_t=zeros(1,length(t));
dq_t=zeros(1,length(t));
d2q_t=zeros(1,length(t));

q_t(1)=0;
dq_t(1)=0;
d2q_t(1)=(V_t(1)-dq_t(1)*R-q_t(1)/C)/L;

for i=2:length(t)
  q_t(i)=q_t(i-1)+1/FM*dq_t(i-1);
  dq_t(i)=dq_t(i-1)+1/FM*d2q_t(i-1);
  
  d2q_t(i)=(V_t(i)-dq_t(i)*R-q_t(i)/C)/L;
endfor

figure 1
plot(t,V_t,t,R*dq_t,t,L*d2q_t,t,q_t/C)

title('Señales de Voltajes  con Metodo de Euler')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R}','V_{L}','V_{C}');