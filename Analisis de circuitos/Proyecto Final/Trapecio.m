%Metodo de Integracion de Trapecio
close all
h=1;
x=0:h:5;
y=zeros(1,length(x)-1);
y_x=zeros(1,length(x));
n=length(x);
A=0;
y_x(1)=0.1679+exp(0);
for i=1:n
    if i<n
    b=x(i+1)/(x(i+1).^2+9);
    x(i+1)
    b
    a=x(i)/(x(i).^2+9);
    x(i)
    a
    A=A+(x(i+1)-x(i))*((b+a)/2)
    endif
  if i>1
    y_x(i)=0.1679+exp(-A);
  endif
end
figure 1
x_2=0:1/1000:5;
  y_2=3./sqrt(x_2.^2+9)+0.1679;
  plot(x,y_x,x_2,y_2);
  %%hold on
  y0=zeros(1,length(x));
  yp=zeros(1,length(x));
  title('Metodo del Trapecio')
  xlabel('x')
  ylabel('y')
  legend('Trapecio','S.Analitica');
%%Metodo de Euler
  y0(1)=1.16794;
  yp(1)=-x(1)/(x(1).^2+9)*(y0(1));
  for i=2:n
    y0(i)=y0(i-1)+h*yp(i-1) 
    yp(i)=-x(i)/(x(i).^2+9)*(y0(i));
  endfor
  figure 2
  plot(x,y0,x_2,y_2);
  title('Metodo de Euler')
  xlabel('x')
  ylabel('y')
  legend('Euler','S.Analitica');