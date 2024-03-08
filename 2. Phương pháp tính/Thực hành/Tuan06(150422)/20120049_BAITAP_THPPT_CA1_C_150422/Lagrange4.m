function [] = Lagrange4(xx,yy,xc)
    syms x
    L03=((x-xx(2))*(x-xx(3))*(x-xx(4)))/...
        ((xx(1)-xx(2))*(xx(1)-xx(3))*(xx(1)-xx(4)));
    L13=((x-xx(1))*(x-xx(3))*(x-xx(4)))/...
        ((xx(2)-xx(1))*(xx(2)-xx(3))*(xx(2)-xx(4)));
    L23=((x-xx(1))*(x-xx(2))*(x-xx(4)))/...
        ((xx(3)-xx(1))*(xx(3)-xx(2))*(xx(3)-xx(4)));
    L33=((x-xx(1))*(x-xx(2))*(x-xx(3)))/...
        ((xx(4)-xx(1))*(xx(4)-xx(2))*(xx(4)-xx(3)));
    L=L03*yy(1)+L13*yy(2)+L23*yy(3)+L33*yy(4)
    yc=double(subs(L,x,xc))
    ezplot(L, [xx(1),xx(end)]);
    hold on
    plot(xx,yy,'bo')
end