function [D] = NghichDao(A)
    [row, col] = size(A);
    for i=1:row
        for j=1:col
            if (A(i,j) ~= 0)
                A(i,j) = 1/A(i,j);
            end
        end
    end
   D = A;
end