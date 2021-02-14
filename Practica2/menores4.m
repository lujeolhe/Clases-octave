%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
%limpiar el workspace
 
close all %cerrar toda las figuras
function b=menores4(a,k,m)
  v=1:length(a)-k;
  v_aux=v;
  if m==1
    b=a(v,v);
  endif
  if m<4
   for c=2:m
      v_aux;
      if mod(c,2)==0
        v_aux(mod(c,length(a)))=v_aux(mod(c,length(a)))+1;
        b=a(v_aux,v_aux);
      else 
        v_aux(mod(c-2,length(a)))=v_aux(mod(c-2,length(a)))+1;
        b=a(v_aux,v_aux);
      endif
    end
  else 
    f=3;
    e=0;
    for c=2:m
      v_aux;
      if c<4
        v_aux(mod(c-e,length(a)))=v_aux(mod(c-e,length(a)))+1;
        e++;
        b=a(v_aux,v_aux);
      else 
        if c<m
        v_aux(mod(c-f,length(a)))=v_aux(mod(c-f,length(a)))+1;
        f++;
        b=a(v_aux,v_aux);
        endif
      endif
    end
  endif
 end
