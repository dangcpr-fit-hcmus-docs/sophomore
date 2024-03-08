function [] = Lap(f,x,y,a,b,delta)
    x0 = a; y0 = 1; k= 1; yo=y0;
    while(1)
        yn = y0 + int(subs(f,y,yo),x,x0,x);
        rEyn=double(abs(int(yn-yo,x,a,b)/int(yo,x,a,b)));
        if(rEyn<=delta) break;
        end
        yo = yn;
        k = k + 1;
    end
    yn
end