function [B] = CongB(A, b)
    A(:,2) = A(:,2) + b;
    A(:,4) = A(:,4) + b;
    B = A;
end