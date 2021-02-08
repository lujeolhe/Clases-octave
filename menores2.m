%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
%limpiar el workspace
 
close all %cerrar toda las figuras
function b=menores2(a,k,m)
  if m==1
  b=a(length(a)-k+1:length(a),length(a)-k+1:length(a));
endif
 if m==2
  b=a(length(a)-k:3,length(a)-k:length(a)-1);
  endif
  end