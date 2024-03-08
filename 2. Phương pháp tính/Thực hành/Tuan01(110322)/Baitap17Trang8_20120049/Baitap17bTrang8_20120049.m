clear all; clc;

%Cau b
syms x
y=(x^2+1)/(x+1);
dy=diff(y,x)
ddy=diff(dy,x)
ddy1=subs(ddy,x,1)
Fy=int(y,x)
Fy1=int(y,x,1,-1)
