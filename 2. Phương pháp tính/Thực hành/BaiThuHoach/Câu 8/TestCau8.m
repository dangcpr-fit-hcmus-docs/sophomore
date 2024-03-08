clear all; clc;
format short;
syms x;
F = 6*pi*(x^2)*(6-x);
xx = [0, 0.2, 0.4, 0.6, 0.8, 1, 1.2];
yy = [double(subs(F,xx))];

[S1,S2,S3]=Spline(xx(:,1:4),yy(:,1:4))
W = Simpson38(xx,yy)