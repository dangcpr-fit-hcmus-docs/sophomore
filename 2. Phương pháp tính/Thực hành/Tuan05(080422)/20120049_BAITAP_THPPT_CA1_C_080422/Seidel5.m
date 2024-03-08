function [Xo] = Seidel5(A,C,df)
    B=-A./[diag(A) diag(A) diag(A) diag(A) diag(A)]+eye(5);
    G=C./diag(A);
    Xo=G;k=1;Xn=Xo;
    while(1)  
        Xn(1)=B(1,:)*Xo+G(1);
        Xn(2)=B(2,1)*Xn(1)+B(2,2)*Xo(2)+B(2,3)*Xo(3)+B(2,4)*Xo(4)+B(2,5)*Xo(5)+G(2);
        Xn(3)=B(3,1)*Xn(1)+B(3,2)*Xn(2)+B(3,3)*Xo(3)+B(3,4)*Xo(4)+B(3,5)*Xo(5)+G(3);
        Xn(4)=B(4,1)*Xn(1)+B(4,2)*Xn(2)+B(4,3)*Xn(3)+B(4,4)*Xo(4)+B(4,5)*Xo(5)+G(4);
        Xn(5)=B(5,1)*Xn(1)+B(5,2)*Xn(2)+B(5,3)*Xn(3)+B(5,4)*Xn(4)+B(5,5)*Xo(5)+G(5);
        rEx=norm((Xn-Xo)./Xo);
        FX=norm(A*Xn-C);
        if(abs(FX)<= df) break
        end
        Xo=Xn;
        k=k+1;
    end
end