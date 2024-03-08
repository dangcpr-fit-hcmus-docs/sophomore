function [z] = BoiSo3(x)
    [row, col] = size(x);
    for i=1:row
        for j=1:col
            if (mod(x(i,j),3) == 0)
                x(i,j) = 3;
            end
        end
    end
    z = x;
end