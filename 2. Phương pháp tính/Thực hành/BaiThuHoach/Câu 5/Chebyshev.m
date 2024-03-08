function [T] = Chebyshev(n,x)
    if (n==0)
        T=1;
    elseif (n==1)
        T=x;
    else
        T=2*x*Chebyshev(n-1,x)-Chebyshev(n-2,x);
    end
end