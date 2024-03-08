function [] = BPNNThang(xx,yy,xc)
    N=length(xx);X=sum(xx);Y=sum(yy);
    XX=sum(xx.*xx);XY=sum(xx.*yy);
    
    syms a b
    [a,b]=solve(XX*a+X*b==XY,X*a+N*b==Y)
    
    syms x
    R=a*x+b;
    
    yc=subs(R,x,xc);
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end