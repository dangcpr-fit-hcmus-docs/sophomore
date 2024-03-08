function [] = BPNNThang(xx,yy,xc)
    N=length(xx);X=sum(log(xx));lY=sum(log(yy));
    lX=sum(log(xx).*log(xx));lXlY=sum(log(xx).*log(yy));
    
    syms A B
    [A,B]=solve(X*A+lX*B==lXlY,N*A+lX*B==lY);
    
    syms x
    R=exp(A)*(x^B)
    
    yc=double(subs(R,x,xc))
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end