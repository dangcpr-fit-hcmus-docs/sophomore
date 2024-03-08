clear all;clc; 

f = @(x,y) abs(x) + 2*abs(y)
fsurf(f) 
xlabel('x') 
ylabel('y') 
title('Do thi ham so') 
grid on