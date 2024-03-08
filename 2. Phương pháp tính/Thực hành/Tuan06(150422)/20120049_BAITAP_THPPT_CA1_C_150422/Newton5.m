function [] = Newton5 (xx,yy,xc) 
    n1=yy;
    
    n2(1)=(n1(2)-n1(1))/(xx(2)-xx(1));
    n2(2)=(n1(3)-n1(2))/(xx(3)-xx(2));
    n2(3)=(n1(4)-n1(3))/(xx(4)-xx(3));
    n2(4)=(n1(5)-n1(4))/(xx(5)-xx(4));
    
    n3(1)=(n2(2)-n2(1))/(xx(3)-xx(1));
    n3(2)=(n2(3)-n2(2))/(xx(4)-xx(2));
    n3(3)=(n2(4)-n2(3))/(xx(5)-xx(3));
    
    n4(1)=(n3(2)-n3(1))/(xx(4)-xx(1));
    n4(2)=(n3(3)-n3(2))/(xx(5)-xx(2));
    
    n5(1)=(n4(2)-n4(1))/(xx(5)-xx(1));
    
    syms x;
    N = n1(1)+n2(1)*(x-xx(1))+n3(1)*(x-xx(1))*(x-xx(2))...
        +n4(1)*(x-xx(1))*(x-xx(2))*(x-xx(3))...
        +n5(1)*(x-xx(1))*(x-xx(2))*(x-xx(3))*(x-xx(4))
    yc=double(subs(N,x,xc))
    
    ezplot(N,[xx(1),xx(end)]);
    hold on
    plot(xx,yy,'bo');
end