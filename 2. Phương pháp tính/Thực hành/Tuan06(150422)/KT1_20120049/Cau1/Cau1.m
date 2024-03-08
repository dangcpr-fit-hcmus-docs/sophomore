clear all;clc;
format long;

syms x;
E=50000;I=30000;L=600;w0=2.5;d=10^-3;
w=w0*(-x^5+2*L^2*x^3-L^4*x)/(120*E*I*L);

dw=diff(w,x)
hold on
ezplot(dw,[0,L])

a=200;b=400;k=1;
while(1)
    c=a-(b-a)/(subs(dw,x,b)-subs(dw,x,a))*subs(dw,x,a);
    rEc=abs((c-a)/a);
    fc=subs(dw,x,c);
    if(abs(fc)<=d) break;
    end
    dau = sign(subs(dw,x,a)*subs(dw,x,c));
    if(dau>0)a=c;
    elseif (dau<0) b=c;
    end
    k=k+1;
end

if(subs(w,x,0)>subs(w,x,c)) subs(w,x,0)
elseif(subs(w,x,L)>subs(w,x,c)) subs(w,x,L)
else subs(w,x,c)
end