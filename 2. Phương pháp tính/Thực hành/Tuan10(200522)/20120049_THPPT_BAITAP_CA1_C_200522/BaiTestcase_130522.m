clear all;clc;

syms x y;
f = x+y;
f2=@(x,y) x+y;
a = 0; b=0.4; delta = 0.1/100; h0=0.1;y0=1;
Lap(f,x,y,a,b,delta)
EulerCaiTien(f2,a,b,h0,y0)
RungeKutta(f2,a,b,h0)