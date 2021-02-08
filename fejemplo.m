%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
%limpiar el workspace
function b=fejemplo(a,k,m)
  v=2:(length(a)-k+1);
  v_aux=v;
  
  if m==1
    b=a(v,v);
  endif
  
   if m==1
    b=a(v,v);
  endif
  if m<4
    for c=2:m
      v_aux;
      v_aux(mod(c-1,length(a)))=v_aux(mod(c-1,length(a)))-1;
      b=a(v_aux,v_aux);
    end
  else 
   for c=2:m
    c;
    v_aux
    if mod(c,2)==0
      v_aux(mod(c,length(a)))=v_aux(mod(c,length(a)))+1
      b=a(v_aux,v_aux)
      
    else 
      v_aux(mod(c-2,length(a)))=v_aux(mod(c-2,length(a)))-1
      b=a(v_aux,v_aux)
    endif
   end

  endif
endfunction
