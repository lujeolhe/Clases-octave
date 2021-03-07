function s=cuad(a)
  aux=floor(a/(2*pi));
  a=a-aux*2*pi;
  s=2*(a<=pi)-(a<2*pi)-(a<=0);
endfunction
