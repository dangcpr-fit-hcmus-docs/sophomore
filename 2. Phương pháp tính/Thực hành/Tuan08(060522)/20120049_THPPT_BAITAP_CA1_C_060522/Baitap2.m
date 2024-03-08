clear all; clc;

xx1=[1;2;3;4;5;6;7];
yy1=[4;-6;-14;-14;0;34;94];
df1=0.5403;I1=42;

syms t; f=exp(t);a=2;b=4;I=int(f,t,2,4);

HinhThang(xx1,yy1,I1)
Simpson38(xx1,yy1,I1)
Gauss(f,t,a,b,I)