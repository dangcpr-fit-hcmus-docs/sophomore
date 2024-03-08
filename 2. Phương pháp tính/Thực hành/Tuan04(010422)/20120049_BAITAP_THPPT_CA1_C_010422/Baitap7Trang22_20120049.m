clear all;clc;
format long;

syms x;

f=2^x+3^x-10*x-30
DayCung(f,-5,-3,10^-3)
disp('----')
DayCung(f,-4,-2,2*10^-3)
disp('----')
DayCung(f,2,4,3*10^-3)
