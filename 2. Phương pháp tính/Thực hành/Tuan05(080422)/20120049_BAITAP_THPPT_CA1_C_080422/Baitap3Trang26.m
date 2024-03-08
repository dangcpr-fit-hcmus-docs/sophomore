clear all; clc;
format long;

a1 = [5 1 1;1 10 1;1 1 20];
c1 = [7;12;22];
df1=10^-3;
x1 = Lap3(a1,c1,df1)
x2 = Seidel3(a1,c1,df1)