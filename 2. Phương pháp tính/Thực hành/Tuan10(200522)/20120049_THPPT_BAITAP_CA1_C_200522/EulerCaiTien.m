function [] = EulerCaiTien(f,a,b,h0,y0)
    xx = a:h0:b;
    [row,col]=size(xx);
    y2=0*xx;y2(1)=y0;
    for i=2:col
        y2(i)=y2(i-1)+(xx(i)-xx(i-1))*f(xx(i-1),y2(i));
        y2(i)=y2(i-1)+(xx(i)-xx(i-1))/2*(f(xx(i-1),y2(i))+f(xx(i),y2(i)));
    end
    y2
end