function [aEp1,rEp1] = SaiSo(f,x,y)
    p = f(x,y);
    p_1 = round(p,3);
    aEp1=abs(p-p_1)
    rEp1=abs((p-p_1)/p)
end