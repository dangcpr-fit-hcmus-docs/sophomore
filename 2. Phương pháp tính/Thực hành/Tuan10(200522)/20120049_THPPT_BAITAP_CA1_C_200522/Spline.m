function [] = Spline(xx,yy,x1,x2)
    h=xx(2:end)-xx(1:end-1);
    VT=[1,0,0,0;h(1)/6,(h(1)+h(2))/3,h(2)/6,0;...
        0,h(2)/6, (h(2)+h(3))/3,h(3)/6;0,0,0,1];
    VP=[0;(yy(3)-yy(2))/h(2)-(yy(2)-yy(1))/h(1);...
        (yy(4)-yy(3))/h(3)-(yy(3)-yy(2))/h(2);0];
    m=inv(VT)*VP;
    
    M=yy(1:end-1)-m(1:end-1).*h(1:end).^2/6
    N=yy(2:end)-m(2:end).*h(1:end).^2/6
    
    syms x
    S1=m(2)*(x-xx(1))^3/6/h(1)+m(1)*(xx(2)-x)^3/6/h(1)...
        +M(1)*(xx(2)-x)/h(1)+N(1)*(x-xx(1))/h(1);
    S2=m(3)*(x-xx(2))^3/6/h(2)+m(2)*(xx(3)-x)^3/6/h(2)...
        +M(2)*(xx(3)-x)/h(2)+N(2)*(x-xx(2))/h(2);
    S3=m(4)*(x-xx(3))^3/6/h(3)+m(3)*(xx(4)-x)^3/6/h(3)...
        +M(3)*(xx(4)-x)/h(3)+N(3)*(x-xx(3))/h(3);
    
    y1=subs(S1,x,x1);
    y2=subs(S3,x,x2);
    
    hold on; plot(xx,yy,'bo');ezplot(S1,[xx(1) xx(2)]);
    ezplot(S2,[xx(2) xx(3)]); ezplot(S3,[xx(3) xx(4)]);
end