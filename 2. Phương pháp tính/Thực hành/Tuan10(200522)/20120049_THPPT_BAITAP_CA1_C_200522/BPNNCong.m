function [] = BPNNThang(xx,yy,xc)
    N=length(xx);X=sum(xx);lY=sum(log(yy));
    XX=sum(xx.*xx);XlY=sum(xx.*log(yy));
    
    syms A B
    [A,B]=solve(XX*A+X*B==XlY,X*A+N*B==lY)
    
    syms x
    R=exp(B)*exp(A*x);
    
    yc=subs(R,x,xc);
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end