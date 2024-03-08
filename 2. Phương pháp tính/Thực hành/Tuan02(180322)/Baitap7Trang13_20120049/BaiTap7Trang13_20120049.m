clear all; clc;

x1_a = 5; aEx1 = 0.03;
x2_a = 3; aEx2 = 0.06;
x3_a = 7; aEx3 = 0.04;
syms x1 x2 x3;
y = x1+ x2*x3;
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)

clear all; clc;

x1_a = 2; aEx1 = 0.05;
x2_a = 4; aEx2 = 0.02;
x3_a = 6; aEx3 = 0.03;
syms x1 x2 x3;
y = x1^2 + x2*x3^3;
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)

clear all; clc;

x1_a = 3; aEx1 = 0.05;
x2_a = 7; aEx2 = 0.07;
x3_a = 3; aEx3 = 0.02;
syms x1 x2 x3;
y = x3*sqrt(x1+x2);
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)


clear all; clc;

x1_a = 3; aEx1 = 0.08;
x2_a = 7; aEx2 = 0.03;
x3_a = 10; aEx3 = 0.1;
syms x1 x2 x3;
y = x1*x2/x3;
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)


clear all; clc;

x1_a = 8; aEx1 = 0.09;
x2_a = 4; aEx2 = 0.02;
x3_a = 3; aEx3 = 0.04;
syms x1 x2 x3;
y = x1*(x2+x3) - x2*x3;
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)

clear all; clc;

x1_a = 7; aEx1 = 0.05;
x2_a = 5; aEx2 = 0.02;
x3_a = 2; aEx3 = 0.03;
syms x1 x2 x3;
y = log(x1*x2-x3);
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)
clear all; clc;

x1_a = 8; aEx1 = 0.09;
x2_a = 4; aEx2 = 0.02;
x3_a = 3; aEx3 = 0.04;
syms x1 x2 x3;
y = x1*sin(x2) - cos(x3);
y_a = subs(y, [x1, x2, x3], [x1_a, x2_a, x3_a]);
dy1=diff(y,x1);
dy2=diff(y,x2);
dy3=diff(y,x3);
dy1_a=subs(dy1,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy2_a=subs(dy2,[x1,x2,x3],[x1_a,x2_a,x3_a]);
dy3_a=subs(dy3,[x1,x2,x3],[x1_a,x2_a,x3_a]);
aEy=abs(dy1_a)*aEx1 + abs(dy2_a)*aEx2 + abs(dy3_a)*aEx3
rEy=aEy/abs(y_a)