clear all;clc;
format long;

ChiaDoi(@(x) exp(x)-x-3,0,3,10^-3)
ChiaDoi(@(x) exp(x)-x-3,0,2,5*10^-3)
ChiaDoi(@(x) exp(x)-x-3,-3,-1,10^-4)