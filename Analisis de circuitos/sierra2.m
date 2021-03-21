function s=sierra2(a)
  aux=floor(a/(2*pi));%%Es para volver la funcion periodica
  a=a-aux*2*pi;%%es para hacer la funcion periodica
  s=1/(pi)*a-1;
endfunction