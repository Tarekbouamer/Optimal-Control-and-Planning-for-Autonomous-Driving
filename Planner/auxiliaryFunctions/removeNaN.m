function [NaNfree] = removeNaN(A)

[I,J] = find(isnan(A));

for i=1:length(I)
    A(I(i),J(i)) = 0;
end
NaNfree = A;

end