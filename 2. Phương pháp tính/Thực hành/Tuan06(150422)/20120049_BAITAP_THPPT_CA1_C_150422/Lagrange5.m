function [] = Lagrange5(xx,yy,xc)
    syms x
    L04=((x-xx(2))*(x-xx(3))*(x-xx(4))*(x-xx(5)))/...
        ((xx(1)-xx(2))*(xx(1)-xx(3))*(xx(1)-xx(4))*(xx(1)-xx(5)));
    L14=((x-xx(1))*(x-xx(3))*(x-xx(4))*(x-xx(5)))/...
        ((xx(2)-xx(1))*(xx(2)-xx(3))*(xx(2)-xx(4))*(xx(2)-xx(5)));
    L24=((x-xx(1))*(x-xx(2))*(x-xx(4))*(x-xx(5)))/...
        ((xx(3)-xx(1))*(xx(3)-xx(2))*(xx(3)-xx(4))*(xx(3)-xx(5)));
    L34=((x-xx(1))*(x-xx(2))*(x-xx(3))*(x-xx(5)))/...
        ((xx(4)-xx(1))*(xx(4)-xx(2))*(xx(4)-xx(3))*(xx(4)-xx(5)));
    L44=((x-xx(1))*(x-xx(2))*(x-xx(3))*(x-xx(4)))/...
        ((xx(5)-xx(1))*(xx(5)-xx(2))*(xx(5)-xx(3))*(xx(5)-xx(4)));
    L=L04*yy(1)+L14*yy(2)+L24*yy(3)+L34*yy(4)+L44*yy(5)
    yc=double(subs(L,x,xc))
    ezplot(L, [xx(1),xx(end)]);
    hold on
    plot(xx,yy,'bo')
end