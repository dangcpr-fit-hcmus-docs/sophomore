function [] = BPNNBac2(xx,yy,xc)
    N=length(xx);X=sum(xx);Y=sum(yy);
    X2=sum(xx.*xx);XY=sum(xx.*yy);
    X4=sum(xx.*xx.*xx.*xx);X3=sum(xx.*xx.*xx);
    X2Y=sum(xx.*xx.*yy);
    syms a b c
    [a,b,c]=solve(X4*a+X3*b+X2*c==X2Y,X3*a+X2*b+X*c==XY,X2*a+X*b+N*c==Y)
    
    syms x
    R=a*x^2+b*x+c;
    
    yc=subs(R,x,xc);
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end