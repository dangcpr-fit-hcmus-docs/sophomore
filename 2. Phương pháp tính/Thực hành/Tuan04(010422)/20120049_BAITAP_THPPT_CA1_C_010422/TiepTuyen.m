function TiepTuyen(f,df,xBD,delta)
    syms x;
    k=1
    df=diff(f,x)
    xBD=xBD-subs(f,x,xBD)/subs(df,x,xBD)
    while abs(subs(f,x,xBD))>=delta
        k=k+1
        xBD=xBD-subs(f,x,xBD)/subs(df,x,xBD)
    end
    disp('Nghiem: ');double(xBD)
end