clear all; clc;

p_t1 = 15.932
p_e1 = 17.351
aEp1 = 1.247
p_L1 = p_t1 - aEp1
p_R1 = p_t1 + aEp1
if (p_L1 <= p_e1 && p_R1 >= p_e1) disp('Dung')
else disp('Sai')
end

p_t2 = 11115
p_e2 = 11205
aEp2 = 120
p_L2 = p_t2 - aEp2
p_R2 = p_t2 + aEp2;
if (p_L2 <= p_e2 && p_R2 >= p_e2) disp('Dung')
else disp('Sai')
end

p_t3 = 36.215
p_e3 = 38.735
aEp3 = 1.327
p_L3 = p_t3 - aEp3
p_R3 = p_t3 + aEp3
if (p_L3 <= p_e3 && p_R3 >= p_e3) disp('Dung')
else disp('Sai')
end

p_t4 = 297 
p_e4 = 319
aEp4 = 15
p_L4 = p_t4 - aEp4
p_R4 = p_t4 + aEp4
if (p_L4 <= p_e4 && p_R4 >= p_e4) disp('Dung')
else disp('Sai')
end
