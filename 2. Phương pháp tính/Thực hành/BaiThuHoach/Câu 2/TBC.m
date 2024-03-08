function [w] = TBC(x)
    [row, col] = size(x);
    TrBinhCong = mean(x, 'all')
    for i=1:row
        for j=1:col
            if (x(i,j) < TrBinhCong)
                x(i,j) = 0;
            end
        end
    end
    w = x;
end