function x = Lap(f,x,phi, deltaf)
    k=0;hold on;
    while (abs(f(x))>=deltaf)
        fx=f(x)
        plot(k,fx,'ro');
        x=phi(x)
        k=k+1
    end
end