function [] = HinhThang(xx,yy,I)
    [xxRow,xxCol]=size(xx);
    [yyRow,yyCol]=size(yy);
    s=0;
    for i = 2:xxRow
        a=xx(i);b=xx(i-1);x=yy(i-1);y=yy(i);
        s=s+(((a-b)/2)*(x+y));
    end
    I1=s
    rEI1=abs((I-I1)/I);
end