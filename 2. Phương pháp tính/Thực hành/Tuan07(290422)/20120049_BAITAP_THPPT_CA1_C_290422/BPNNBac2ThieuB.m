function [] = BPNNBac2ThieuB(xx,yy,xc)
    N=length(xx);X=sum(xx);Y=sum(yy);
    X2=sum(xx.*xx);XY=sum(xx.*yy);
    X4=sum(xx.*xx.*xx.*xx);X3=sum(xx.*xx.*xx);
    X2Y=sum(xx.*xx.*yy);
    syms a b
    [a,b]=solve(X4*a+X2*b==X2Y,X2*a+N*b==Y);
    
    syms x
    R=a*x^2+b
    
    yc=subs(R,x,xc)
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end