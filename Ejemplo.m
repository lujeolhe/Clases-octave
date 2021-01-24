%%
%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
clear all %limpiar el workspace
close all %cerrar toda las figuras


x=-1:.01:1;
y=x;
y2=x+1;
y3=2*x;
y4=2*x+1;
%figure 1
subplot(2,2,1)
plot(x,y);
title('y=x')
xlabel('x')
ylabel('y')
%figure 2
subplot(2,2,2)
plot(x,y2);
title('y=x+1')
xlabel('m')
ylabel('t')
%figure 3
subplot(2,2,3)
plot(x,y3);
title('y=2x')
xlabel('m')
ylabel('t')
%figure 4
subplot(2,2,4)
plot(x,y4);
title('y=2x+1')
xlabel('m')
ylabel('t')

%%
%Esta es la seccion 2 (Notacion matlab)
y5=-y;
figure 2
hwnd=plot(x,y,x,y2,x,y3,x,y4,x,y5)
##title('Operaciones sobre funciones')
##xlabel('x')
##ylabel('y')
ponerTituloyEjes('Operaciones sobre funciones','x','y')



