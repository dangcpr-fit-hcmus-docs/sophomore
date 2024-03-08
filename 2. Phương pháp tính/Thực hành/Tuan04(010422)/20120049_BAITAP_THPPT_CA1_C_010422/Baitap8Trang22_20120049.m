clear all;clc;
format long;

syms x;
f=exp(x)+2^-x+2*cos(x)-6
df=diff(f,x)
TiepTuyen(f,df,1.5,10^-3)

f=log(x-1)+cos(x-1)
df=diff(f,x)
TiepTuyen(f,df,1.5,10^-3)

f=sin(x)-exp(-x)
DayCung(f,0,1,10^-3)

f=exp(x)+2^-x+2*cos(x)-6
TiepTuyen(f,df,1.5,10^-3)
