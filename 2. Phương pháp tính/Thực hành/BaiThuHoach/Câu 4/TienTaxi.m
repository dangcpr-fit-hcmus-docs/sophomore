function [r] = TienTaxi(a,b)
    r = 0;
    if (a > 0) 
        r = 14000;
    end
    if (a >= 2 && a <=25)
        r = r + 16300*(a-1);
    elseif (a >= 26)
         r = r + (16300*24 + 13300*(a-25));
    end
    r = r + 500*b;
end