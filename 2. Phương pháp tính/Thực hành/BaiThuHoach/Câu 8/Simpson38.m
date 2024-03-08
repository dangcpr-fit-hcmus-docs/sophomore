function [I1] = Simpson(xx,yy)
    [xxRow,xxCol]=size(xx);
    [yyRow,yyCol]=size(yy);
    s=0;
    for i = 4:3:xxCol
        s=s+((xx(i)-xx(i-3))*(yy(i)+3*yy(i-1)+3*yy(i-2)+yy(i-3))/8);
    end
    I1=s;
%     rEI1=abs((I-I1)/I);
end