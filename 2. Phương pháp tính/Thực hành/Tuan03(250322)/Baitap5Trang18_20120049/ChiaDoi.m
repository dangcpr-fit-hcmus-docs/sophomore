function c = ChiaDoi(f,a,b,deltaf)
    c=(a+b)/2
    k=0
    hold on;
    while abs(f(c))>=deltaf
        fc=f(c)
        plot(k,fc,'ro');
        if f(a)*f(c)>0
            a=c
        else
            b=c
        end
        c=(a+b)/2
        k=k+1
    end
end