% Repaso
%Ejercio de Repaso de los temas del Curso
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Linea de Tiempo
FS=1000 %frecuencia de Muestreo de la Simulación de 1KHz
t=-1:1/FS:10;

x1_t=tri(t);
x2_t=sierra(t);
x3_t=sierra2(t);
x4_t=parabola(t);

plot(t,x1_t,t,x2_t,t,x3_t,t,x4_t)
legend("Triangular","Sierra","Sierra2", "Sierra Grande")