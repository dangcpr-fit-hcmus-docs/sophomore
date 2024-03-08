clear all;clc;
format long;

syms x;

f=x+log(x+2)-10
df=diff(f,x)
TiepTuyen(f,df,7,10^-3)
TiepTuyen(f,df,9,2*10^-3)
TiepTuyen(f,df,5,5*10^-3)
TiepTuyen(f,df,3,5*10^-3)