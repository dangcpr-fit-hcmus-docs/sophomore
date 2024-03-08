clear all;clc;
format long;

syms x
a=8
b=3
delta=3*10^-3;
k=1
f=x^2-sin(x)-50;
if (subs(f,x,a)*subs(f,x,b)<0)
    c=a-(b-a)/(subs(f,x,b)-subs(f,x,a))*subs(f,x,a)
    while abs(subs(f,x,c)) >= delta
        if(subs(f,x,a)*subs(f,x,c)>0) a=c
        else b=c
        end
        k=k+1
        c=a-(b-a)/(subs(f,x,b)-subs(f,x,a))*subs(f,x,a)
    end
else
    disp('a va b khong thoa DK')
end
disp('Nghiem cua phuong trinh la: ');double(c)