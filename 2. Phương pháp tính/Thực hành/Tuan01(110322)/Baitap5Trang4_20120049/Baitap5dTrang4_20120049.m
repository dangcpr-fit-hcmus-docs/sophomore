clear all;clc;
x=-3:0.01:3;
k=@(x) (x.^2-1)+(2*x + 1);
kx=k(x);
plot(x,kx,'r-')