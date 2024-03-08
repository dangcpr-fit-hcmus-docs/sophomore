clear all;clc;
format long;

syms x
f=x^2-sin(x)-50
df=diff(f,x)
delta=10^-3

x0=2
k=1
x0=x0-subs(f,x,x0)/subs(df,x,x0)
while abs(subs(f,x,x0))>=delta
    k=k+1
    x0=x0-subs(f,x,x0)/subs(df,x,x0)
end

disp('Nghiem cua phuong trinh la: ');double(x0)