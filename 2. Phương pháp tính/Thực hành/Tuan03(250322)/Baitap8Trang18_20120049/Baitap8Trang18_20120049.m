clear all; clc;
format long;

%Phuong phap chia doi: 9a, 8b
ChiaDoi(@(x) exp(x)+2^-x+2*cos(x)-6,0,2,10^-3) %a=0;b=2
ChiaDoi(@(x) log(x-1)+cos(x-1),1.2,2,10^-3) %a=1.2;b=2

%Phuong phap lap: 8c, 8d
Lap(@(x) (x-2)^2-log(x),3,@(x) sqrt(log(x))+2,10^-3)
Lap(@(x) sin(x)-exp(-x),0.5,@(x) asin(exp(-x)),10^-3)