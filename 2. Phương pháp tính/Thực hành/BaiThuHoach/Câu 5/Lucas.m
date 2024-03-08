function [L] = Lucas(n,p,q)
    if (n == 0)
        L=0;
    elseif (n==1)
        L=1;
    else
        L=p*Lucas(n-1,p,q)-q*Lucas(n-2,p,q);
end