%Frecuancia de Muentreo
FS=10000;
%REALES
x=1/2:1/FS:3;
y=x;

u=1./(2*x);
v=-1./(2*x);

figure 1;
subplot (1,2,1)
plot(x,y);
subplot (1,2,2)
plot(u,v);

%Complejos
z=x+x*i;
w=1./z;

figure 2;
subplot (1,2,1)
plot(real(z),imag(z));
subplot (1,2,2)
plot(real(w),imag(w));


