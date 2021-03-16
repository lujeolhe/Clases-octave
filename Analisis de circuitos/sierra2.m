function s=sierra2(a)
  aux=floor(a/(2*pi));
  a=a-aux*2*pi;
  s=1/(2*pi)*a;
endfunction