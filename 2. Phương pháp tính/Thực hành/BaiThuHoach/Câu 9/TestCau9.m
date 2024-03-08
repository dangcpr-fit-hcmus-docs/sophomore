clear all; clc;
format short;

syms x1;
f1 = 2^x1 - 4*x1; delta = 10^-5; xBD=3;
Nghiem = double(TiepTuyen(f1,x1,xBD,delta))

f2 = @(x,y) 0.15*(x^2-y^2)*cos(y);
y = RungeKutta(f2,1,1.2,0.1)
