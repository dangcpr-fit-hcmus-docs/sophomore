function [Xo] = Lap5(A, C, df)
    B=-A./[diag(A) diag(A) diag(A) diag(A) diag(A)]+eye(5);
    G=C./diag(A);
    Xo=G;k=1;
    
    while(1)
        Xn = B*Xo + G;
        rEX = norm((Xn-Xo)./Xo);
        fX = norm(A*Xn-C);
        if (fX<=df) break;
        end
        Xo = Xn;
        k = k+1;
    end
end