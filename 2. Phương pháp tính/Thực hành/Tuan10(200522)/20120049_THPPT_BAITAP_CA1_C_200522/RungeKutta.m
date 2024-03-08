function [] = RungeKutta(f,a,b,h0)
    xx=a:h0:b; h=xx(2:end)-xx(1:end-1);
    [row,col]=size(xx);
    x0=a;y=0*xx;y0=1;
    k1=h(1)*f(x0,y0);
    k2=h(1)*f(x0+h(1)/2,y0+k1/2);
    k3=h(1)*f(x0+h(1),y0-k1+2*k2);
    y(1)=y0+(k1+4*k2+k3)/6;
    for i=2:col-1
        k1=h(i)*f(xx(i-1),y(i-1));
        k2=h(i)*f(xx(i-1)+h(i)/2,y(i-1)-k1+2*k2);
        k3=h(i)*f(xx(i-1)+h(i),y(i-1)-k1+2*k2);
        y(i)=y(i-1)+(k1+4*k2+k3)/6;
    end
    y
end