function [] = LamTron(p_e1,n)
    p_a1 = round(p_e1,n)
    aEp1a = abs(p_e1-p_a1)
    rEp1a = abs((p_e1-p_a1)/p_e1)
    p_b1 = floor(p_e1*10^n)/10^n;
    aEp1b = abs(p_e1-p_b1)
    rEp1b = abs((p_e1-p_b1)/p_e1)
end