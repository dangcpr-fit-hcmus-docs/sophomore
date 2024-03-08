function [Xo] = Seidel3(A,C,df)
    B=-A./[diag(A) diag(A) diag(A)]+eye(3);
    G=C./diag(A);
    Xo=G;k=1;Xn=Xo;
    while(1)
        Xn(1)=B(1,:)*Xo+G(1);
        Xn(2)=B(2,1)*Xn(1)+B(2,2)*Xo(2)+B(2,3)*Xo(3)+G(2);
        Xn(3)=B(3,1)*Xn(1)+B(3,2)*Xn(2)+B(3,3)*Xo(3)+G(3);
        rEx=norm((Xn-Xo)./Xo);
        FX=norm(A*Xn-C);
        if(abs(FX)<=df) break;
        end
        Xo=Xn;
        k=k+1;
    end
end