function s=parabola(a)
  aux=floor(a/(2*pi));
  a=a-aux*pi*2;
  %s=((2/pi)*a).*and(a>=0,a<pi/2)+((-2/pi)*a+2).*and(a>=pi/2,a<(3*pi/2))+((2/pi)*a-4).*and(a>=(3*pi/2),a<=2*pi);
  s=1/(pi^2)*( (a).^2.*and(a>=0,a<=pi)+ (a-2*pi).^2.*and(a>pi,a<=2*pi) );
endfunction
