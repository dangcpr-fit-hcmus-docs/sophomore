function [] = TongQuat6(xx,yy,xc)
    X=[1 xx(1) xx(1)^2 xx(1)^3  xx(1)^4 xx(1)^5; 1 xx(2) xx(2)^2 xx(2)^3 xx(2)^4 xx(2)^5; ...
        1 xx(3) xx(3)^2 xx(3)^3 xx(3)^4 xx(3)^5; 1 xx(4) xx(4)^2 xx(4)^3 xx(4)^4 xx(4)^5; ...
        1 xx(5) xx(5)^2 xx(5)^3 xx(5)^4 xx(5)^5; 1 xx(6) xx(6)^2 xx(6)^3 xx(6)^4 xx(6)^5];
    Y=[yy(1);yy(2);yy(3);yy(4);yy(5);yy(6)];

    A=inv(X)*Y;

    syms x;
    P=A(1)+A(2)*x+A(3)*x^2+A(4)*x^3+A(5)*x^4+A(6)*x^5

    yc=double(subs(P,x,xc))

    ezplot(P,[xx(1) xx(end)]);
    hold on; plot(xx,yy,'bo')
end