clear all; clc;

syms x;

x=0:pi/100:2*pi;
f1=(x.^2).*sin(x); %1
f2=(x.^3).*cos(x); %2

DoThi(f1,f2,x)