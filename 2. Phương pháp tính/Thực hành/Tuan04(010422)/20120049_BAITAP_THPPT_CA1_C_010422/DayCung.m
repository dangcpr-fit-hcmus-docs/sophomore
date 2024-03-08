function [] = DayCung(f,a,b,delta)
    syms x ;
    k=1
    c=0
    if (subs(f,x,a)*subs(f,x,b)<0)
        c=a-(b-a)/(subs(f,x,b)-subs(f,x,a))*subs(f,x,a);
        while abs(subs(f,x,c)) > delta
            if(subs(f,x,a)*subs(f,x,c)>0) a=c
            else
                if(subs(f,x,a)*subs(f,x,c)<0) b=c
                else break
            end
            end
            k=k+1
            c=a-(b-a)/(subs(f,x,b)-subs(f,x,a))*subs(f,x,a);
            double(c)
        end
           disp('Nghiem cua phuong trinh la: ');double(c)
    else
    disp('a va b khong thoa DK')
    end
end