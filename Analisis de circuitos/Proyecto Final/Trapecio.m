%Metodo de Integracion de Trapecio
h=1;
x=0:1:5
n=6;
A=0;
for i=1:n
  for j=i-1:i-1
    if i<=5
    b=-0.2018+sqrt(x(i+1).^2+9)/3
    a=-0.2018+sqrt(x(j+1).^2+9)/3
    A=(x(i+1)-x(j+1))+(b+a)/2
    endif
  end
end