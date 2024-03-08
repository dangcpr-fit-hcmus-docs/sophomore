function [v] = GanV(x)
    v = [];
    [row, col] = size(x);
    for i=1:row
        for j=1:col
            if (x(i,j) > 10)
                v = [v,x(i,j)];
            end
        end
    end
end