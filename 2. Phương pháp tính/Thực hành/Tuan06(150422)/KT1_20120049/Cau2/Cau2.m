clear all;clc
format long;

A=[24.21 2.42 3.85; 2.31 31.49 1.52; 3.40 4.95 28.72]
C=[30.24 40.95 42.81]
df=10^-5;

B=-A./[diag(A) diag(A) diag(A)]+eye(3);
G=C./diag(A);

Xo=G;k=1;Xn=Xo;
while(1)
    Xn(1)=B(1,:)*Xo+G(1);
    Xn(2)=B(2,1)*Xn(1)+B(2,2)*Xo(2)+B(2,3)*Xo(3)+G(2);
    Xn(3)=B(3,1)*Xn(1)+B(3,2)*Xn(2)+B(3,3)*Xo(3)+G(3);
    rEx=norm((Xn-Xo)./Xo);
    FX=norm(A*Xn-C);
    if(FX<=df) break;
    end
    Xo=Xn;
    k=k+1;
end



