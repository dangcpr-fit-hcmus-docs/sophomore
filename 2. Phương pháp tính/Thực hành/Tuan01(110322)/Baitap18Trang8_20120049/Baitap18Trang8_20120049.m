clear all; clc;
a=input('Nhap a: ')
b=input('Nhap b: ')
c=input('Nhap c: ')
function PTBachai(a,b,c)
    if a==0
        disp(sprintf('Khong phai pt bac 2'))
    else
        delta=b^2-4*a*c
        if delta > 0
            x1=(-b+sqrt(delta))/(2*a);
            x2=(-b-sqrt(delta))/(2*a);
            disp(sprintf('Phuong trinh co 2 nghiem la: %f, %f',x1,x2))
        elseif delta==0
            x1=(-b+sqrt(delta))/(2*a);
            disp(sprintf('Phuong trinh co nghiem kep la: %f',x1))
        else 
            disp(sprintf('Phuong trinh vo nghiem'))
        end
    end
end

PTBachai(a,b,c)