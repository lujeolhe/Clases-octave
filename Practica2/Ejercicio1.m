%Ejercicio 1
clc; %limpiar pantalla
clear all;%limpiar wokspace
close all;%cerrar las figuras

menores4;%esta linea no es necesaria en matlab, se usa en octave para definir la funcion

M=[1,2,3,4;5,6,7,8;9,10,11,12;13,14,15,16]

for i=1:6
  menores4(M,2,i)
endfor
