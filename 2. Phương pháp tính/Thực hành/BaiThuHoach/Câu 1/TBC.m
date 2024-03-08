function [F] = TBC(A)
    [row, col] = size(A);
    TrBinhCong = mean(A, 'all') %Tinh trung binh cong
    for i=1:row
        for j=1:col
            if (A(i,j) < TrBinhCong)
                A(i,j) = 0;
            end
        end
    end
    F = A;
end