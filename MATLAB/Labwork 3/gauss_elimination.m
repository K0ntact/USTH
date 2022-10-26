%ex1

a = [2 1 -1; -3 -1 2; -2 1 2];
b = [8; -11; -3];
c = GaussPivot(a,b);
disp(c)

%part b
function x = GaussPivot(A,b)
% GaussPivot: Gauss elimination pivoting
% x = GaussPivot(A,b): Gauss elimination with pivoting.
% input:
% A = coefficient matrix
% b = right hand side vector
% output:
% x = solution vector

    [m,n]=size(A);
    if m~=n, error('Matrix A must be square'); end % m~=n is m!=n in C 
    nb=n+1;
    Aug=[A b];  %Augmented matrix
    
    % forward elimination
    for k = 1:n-1 

        % partial pivoting
        [big,i]=max(abs(Aug(k:n,k)));   % max returns Max of each column, I is number of coresponding column
        ipr=i+k-1;
        if ipr~=k
            Aug([k,ipr],:)=Aug([ipr,k],:);
        end

        for i = k+1:n
            factor=Aug(i,k)/Aug(k,k);
            Aug(i,k:nb)=Aug(i,k:nb)-factor*Aug(k,k:nb);
        end
    end

    % back substitution
    x=zeros(n,1);
    x(n)=Aug(n,nb)/Aug(n,n);
    for i = n-1:-1:1
        x(i)=(Aug(i,nb)-Aug(i,i+1:n)*x(i+1:n))/Aug(i,i);
    end

end