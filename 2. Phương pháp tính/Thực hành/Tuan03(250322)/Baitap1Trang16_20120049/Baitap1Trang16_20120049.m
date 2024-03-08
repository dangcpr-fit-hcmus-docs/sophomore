clear all; clc;
format long

f=@(x) x+sin(x)-2
a=1.0;b=1.4;c=(a+b)/2;
deltaf = 10^-3
k=0
while(abs(f(c))>deltaf)
    if f(a)*f(c) > 0
        a=c;
    else
        b=c;
    end
    c=(a+b)/2;
    k=k+1
end
disp("Nghiem cua phuong trinh la: ");c