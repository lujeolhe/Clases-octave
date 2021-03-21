%Frecuancia de Muentreo
FS=10000;
%%Recta 1 a)
x=0:1/FS:1;
y=x;
u=1./(2*x);
v=-1./(2*x);
figure 1;
subplot (1,2,1)
plot(x,y);
title('Plano Z')
xlabel('x')
ylabel('y')
subplot (1,2,2)
plot(u,v);
title('Plano w')
xlabel('u')
ylabel('v')

%%Recta 2 b)
x=1/2:1/FS:3;
z=x+x*i;
w=1./z;
figure 2;
subplot (1,2,1)
plot(real(z),imag(z));
title('Plano Z')
xlabel('x')
ylabel('y')
subplot (1,2,2)
plot(real(w),imag(w));
title('Plano W')
xlabel('u')
ylabel('v')


%%Circulo 1 c)
r=2;
a=0:1/FS:2*pi;
z=r*(cos(a)+i*sin(a));
w=1./z;

figure 3;
subplot (1,2,1)
plot(real(z),imag(z));
title('Plano Z')
xlabel('x')
ylabel('y')
subplot (1,2,2)
plot(real(w),imag(w));
title('Plano W')
xlabel('u')
ylabel('v')

%%Circulo 2 d)
r=1;
a=horzcat(0:1/FS:pi-(1/FS),pi+(1/FS):1/FS:2*pi);
z=r*(cos(a)+i*sin(a))+1;
w=1./z;
figure 4;
subplot (1,2,1)
plot(real(z),imag(z));
title('Plano Z')
xlabel('x')
ylabel('y')
subplot (1,2,2)
plot(real(w),imag(w));
title('Plano W')
xlabel('u')
ylabel('v')
