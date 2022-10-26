%u(x,y)   v(x,y)
% x(i+1) = x(i) - {[( u(i)*dv(i)/dy - v(i)*du(i)/dy] / [du(i)/dx * dv(i)/dy -
%du(i)/dy * dv(i)/dx]}

% y(i+1) = y(i) - {[( v(i)*du(i)/dx - v(i)*dv(i)/dx] / [du(i)/dx * dv(i)/dy -
%du(i)/dy * dv(i)/dx]}

function x = newton_raphson(f,f1,x0,n)
    %solves f(x)= 0 by doing n steps of Newton's method starting at x0
    %f: function 
    %f0: it's derivative
    %x0: starting guess 
    %n: The number of steps
    %x: output of the approx solution
    %tol: desired tolerance
    x =x0;
    iter=0;
    for i = 1:n
        x1=x;
        x = x - f(x)/f1(x);
        iter = iter +1;
        y =  (abs((x-x1)/x)*100);
        fprintf("Iter: %d: x=%.20f, err=%.20f \n", iter, x,y);
        % display([iter' x' y' x1'])
    end
end