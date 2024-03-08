function [P] = Legendre(n, x)
    if (n==0)
        P = 1;
    elseif (n==1)
        P = x;
    elseif (n==2)
        P = (3*(x^2)-1)/2;
    else
        P = ((2*n-1)*x*Legendre(n-1,x)-(n-1)*Legendre(n-2,x))/n;
    end
end