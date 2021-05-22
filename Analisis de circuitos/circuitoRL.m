%Ejercicio 4
%Ejercio donde aplicamos metodo de Euler para resolver EDO en un circuito RC
%
FM=1000; %Frecuencia de Muestreo de la Simulacion

%Teorema de Nyquis o Teroema de Muestreo:
%Para muetrear una señal de frecuencia f se requiere una frecuencia F de muetreo de almenos 2f, es decir F=2f
%Para muetrear una señal de periodo t, se requiere un tiempo de muetreo de alemnos t/2
%%Formulas 
%%V=IR

t=0:1/FM:.05;

V=10;
R=1;
L=0.01;
f=50;
%V_t=V*ones(1,length(t));
V_t=V*sin(2*pi*f*t);

i_t=zeros(1,length(t));
di_t=zeros(1,length(t));

i_t(1)=0;
di_t(1)=(V_t(1)-i_t(1)*R)/L;

for i=2:length(t)
  i_t(i)=i_t(i-1)+1/FM*di_t(i-1);
  di_t(i)=(V_t(i)-i_t(i)*R)/L;
endfor

figure 1
plot(t,V_t,t,R*i_t,t,L*di_t)

title('Señales de Voltajes  con Metodo de Euler')
xlabel('t')
ylabel('V_x')
legend('V(t)','V_{R}','V_{L}');