clear all;clc;
format long

f=@(x) x+sin(x)-2
phi=@(x) 2-sin(x)
x=1.05;deltaf=10^-3;
k=0
while(abs(f(x))>=deltaf)
    k=k+1
    x=phi(x);
end
disp("Nghiem cua phuong trinh la: ");x