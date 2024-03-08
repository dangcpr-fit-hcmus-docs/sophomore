function [C] = BoiSo(A, a)
    [row, col] = size(A);
    for i=1:row
        for j=1:col
            if (mod(A(i,j),a) == 0)
                A(i,j) = a;
            end
        end
    end
    C = A;
end