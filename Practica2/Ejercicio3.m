%Ejercicio 3
clc; %limpiar pantalla
clear all;%limpiar wokspace
close all;%cerrar las figuras

A=[3,4,-6,0,5;2,-12,0,0,1;-1,1,-14,1,1;0,10,10,-1,-3;2,-3,0,1,0]
B=[-8;10;20;6;-5]
fprintf('Valores de las variables B \n\n')
fprintf('Por medio de la division matricial: \n\n')
C=A\B
fprintf('Por medio de la inversa: \n\n')
C=inv(A)*B