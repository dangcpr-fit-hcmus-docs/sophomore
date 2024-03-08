clear all;clc;
format long;

Lap(@(x) x-x/2-1/x,1,@(x) x/2+1/x,10^-3)
Lap(@(x) x-x/2-1/x,2,@(x) x/2+1/x,3*10^-3)
Lap(@(x) x-x/2-1/x,-2,@(x) x/2+1/x,10^-2)