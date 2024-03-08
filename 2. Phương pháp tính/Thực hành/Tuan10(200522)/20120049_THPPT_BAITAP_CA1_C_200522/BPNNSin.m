function [] = BPNNSin(xx,yy,xc)
    N=length(xx);X=sum(xx);Y=sum(yy);
    X2=sum(xx.*xx);XY=sum(xx.*yy);XSIN=sum(xx.*sin(xx));XCOS=sum(xx.*cos(xx));
    YSIN=sum(yy.*sin(xx));SIN2=sum(sin(xx).*sin(xx));
    SINCOS=sum(sin(xx).*cos(xx));COS2=sum(cos(xx).*cos(xx));YCOS=sum(yy.*cos(xx));
    syms a b c
    [a,b,c]=solve(X2*a+XSIN*b+XCOS*c==XY,XSIN*a+SIN2*b+SINCOS*c==YSIN,XCOS*a+SINCOS*b+COS2*c==YCOS)
    
    syms x
    R=a*x^2+b*sin(x)+c*sin(x)
    
    yc=double(subs(R,x,xc))
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo');
end