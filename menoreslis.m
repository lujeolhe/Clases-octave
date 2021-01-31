%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
 %limpiar el workspace
close all %cerrar toda las figuras
function menoreslis(a)
  %%1
  b=a(2:3,2:3);
  c1=det(b);
  %%7
  b=a(1:2,2:3);
  c7=det(b);
  %%2
  b=a(2:3)';
  d=a(2:3,3);
  e=horzcat(b,d);
  c2=det(e);
  %%8
  b=a(1:2)';
  d=a(1:2,2);
  e=horzcat(b,d);
  c8=det(e);
  %%3
  b=a(2:3,1:2);
  c3=det(b);
  %%9
  b=a(1:2,1:2);
  c9=det(b);
  %%4
  d=a(1,2:3);
  b=a(3,2:3);
  e=[d;b];
  c4=det(e);
  %%5
  b=a(1,1);
  c=a(1,3);
  d=horzcat(b,c);
  e=a(3,1);
  f=a(3,3);
  g=horzcat(e,f);
  h=[d;g];
  c5=det(h);
  %%6 
  d=a(1,1:2);
  b=a(3,1:2);
  e=[d;b];
  c6=det(e);
  fprintf('Lista de menores principales \n')
  lis=[c1 c5 c9]
   end