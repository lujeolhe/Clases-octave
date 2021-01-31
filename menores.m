%Esta es la seccion 1 (Notacion matlab)
%Esto es un comentario
 %limpiar el workspace
close all %cerrar toda las figuras
function menores(a,k)
    if k==1
      b=a(k+1:k+2,k+1:k+2)
      c1=det(b)
      else if k==7
      b=a(k-6:k-5,k-5:k-4)
      c2=det(b)
      endif
    endif
  if k==2
     b=a(k:k+1)';
     d=a(k:k+1,k+1);
     e=horzcat(b,d)
     c3=det(e)
    else if k==8
     b=a(k-7:k-6)';
     d=a(k-7:k-6,k-5);
     e=horzcat(b,d)
     c4=det(e)
     endif
   endif
   if k==3
      b=a(k-1:k,k-2:k-1)
      c5=det(b)
      else if k==9
      b=a(k-8:k-7,k-8:k-7)
      c6=det(b)
      endif
   endif
  if k==4
     d=a(k-3,k-2:k-1);
     b=a(k-1,k-2:k-1);
     e=[d;b]
     c7=det(e)
    else if k==5
     b=a(1,1);
     c=a(1,3);
     d=horzcat(b,c);
     e=a(k-2,k-4);
     f=a(k-2,k-2);
     g=horzcat(e,f);
     h=[d;g];
     c8=det(h);
     else 
      d=a(k-5,k-5:k-4);
      b=a(k-3,k-5:k-4);
      e=[d;b];
      c9=det(e);
    endif
  endif
  lis=[c1 c8 c9]
   end