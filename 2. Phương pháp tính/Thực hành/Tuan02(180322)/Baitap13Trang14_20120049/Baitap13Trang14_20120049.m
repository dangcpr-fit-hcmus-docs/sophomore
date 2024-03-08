clear all; clc;
format long;

disp('Cau a:') 
SaiSo(@(x,y) log(2*y+x^2),1.976,0.532); %Cau a
disp('Cau b:') 
SaiSo(@(x,y) y*exp(x)-x^2,1.675,1.073); %Cau b
disp('Cau c:') 
SaiSo(@(x,y) x*tan(y)+(x+y)^2,-1.395,1.643); %Cau c