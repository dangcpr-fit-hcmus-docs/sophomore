clear all; clc;
format long
p_e1 = pi
p_a1 = round(p_e1,3)
aEp1a = abs(p_e1-p_a1)
rEp1a = abs((p_e1-p_a1)/p_e1)
p_b1 = floor(p_e1*10^3)/10^3;
aEp1b = abs(p_e1-p_b1)
rEp1b = abs((p_e1-p_b1)/p_e1)

p_e2 = exp(1)
p_a2 = round(p_e2,3)
aEp2a = abs(p_e2-p_a2)
rEp2a = abs((p_e2-p_a2)/p_e2)
p_b2 = floor(p_e2*10^3)/10^3;
aEp2b = abs(p_e2-p_b2)
rEp2b = abs((p_e2-p_b2)/p_e2)

p_e3 = log(2)
p_a3 = round(p_e3,3)
aEp3a = abs(p_e3-p_a3)
rEp3a = abs((p_e3-p_a3)/p_e3)
p_b3 = floor(p_e3*10^3)/10^3;
aEp3b = abs(p_e3-p_b3)
rEp3b = abs((p_e3-p_b3)/p_e3)

p_e4 = sqrt(2)
p_a4 = round(p_e4,3)
aEp4a = abs(p_e4-p_a4)
rEp4a = abs((p_e4-p_a4)/p_e4)
p_b4 = floor(p_e4*10^3)/10^3;
aEp4b = abs(p_e4-p_b4)
rEp4b = abs((p_e4-p_b4)/p_e4)

p_e5 = sin(1)
p_a5 = round(p_e5,3)
aEp5a = abs(p_e5-p_a5)
rEp5a = abs((p_e5-p_a5)/p_e5)
p_b5 = floor(p_e5*10^3)/10^3;
aEp5b = abs(p_e5-p_b5)
rEp5b = abs((p_e5-p_b5)/p_e5)