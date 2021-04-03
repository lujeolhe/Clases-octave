a=0;
b=3;
h=.001;
presicion=3;
x=-4:h:10;
f_x=x.^2-3;%funcion a evaluar
plot(x,f_x)
for i=1:100
m=(((h+b)^2-3)-(b^2-3))/h;%pendiente de la tangente
d=(b^2-3)-m*b;%%punto b de la recta tangente
p1=d/m;%%punto que se aproxima
y=m*x+d;%%expresion de la recta tengente
n=b*10^presicion
n1=abs(p1*10^presicion)
if floor(n)==floor(n1)
  i
  break;
  endif
b=p1;
hold on
plot(x,y)
endfor