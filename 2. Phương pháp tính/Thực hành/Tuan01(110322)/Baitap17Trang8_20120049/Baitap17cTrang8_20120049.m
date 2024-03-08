clear all; clc;

%Cau c
syms x
y=sin(2*x);
dy=diff(y,x)
dy1=subs(dy,x,0)
Fy=int(y,x)
%F(inf)-F(0)=-(F(0)-F(inf)
Fy1=-int(y,x,0,Inf)
