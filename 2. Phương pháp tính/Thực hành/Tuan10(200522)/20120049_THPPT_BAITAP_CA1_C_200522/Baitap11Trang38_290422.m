clear all;clc;

xx1=[0;1;2;3];
yy1=[1.5;2;3.5;6];
xc1=4;

xx2=[1;2;3;4];
yy2=[2;2*(2^1.3);2*(3^1.3);2*(4^1.3)];
xc2=4;
BPNNBac2ThieuB(xx1,yy1,xc1)
BPNNMu(xx2,yy2,xc2)