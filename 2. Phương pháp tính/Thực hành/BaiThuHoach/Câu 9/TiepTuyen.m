function [xBD]=TiepTuyen(f,x,xBD,delta)
    k=1;
    df=diff(f,x);
    xBD=xBD-subs(f,x,xBD)/subs(df,x,xBD);
    while abs(subs(f,x,xBD))>=delta
        k=k+1;
        xBD=xBD-subs(f,x,xBD)/subs(df,x,xBD);
    end
end