clear all;clc;
x=1:0.01:5;
h=@(x) (x+1).*exp(x-1);
hx=h(x);
plot(x,hx,'r-')