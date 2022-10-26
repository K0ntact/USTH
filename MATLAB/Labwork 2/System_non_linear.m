%Exercise 1
%Part a
figure
box on
hold on
f1 = @(x1, x2) x1^2 + x1 * x2 - 10;
f2 = @(x1, x2) x2 + 3 * x1 * x2^2 -57;
h1 = ezplot(f1, [0 8]);
h2 = ezplot(f2, [0 8]);
h1.LineColor = 'r';
h2.LineColor = 'b';
title("Bruh");
xlim([0 8]);
ylim([0 8]);
grid on
hold off

%Part b

%Newton Raphson method for system of equations


clc
clear all
close all

x=[1 1]';   %set x as a vertical matrix 1 1
N = 50;
for k=1:N   %loop from 1 to 50
F=[ x(1)*x(1)+ x(1)*x(2) - 10 ; x(2) + 3*x(1)*x(2)*x(2)-57];
    %func 1                      func 2
A=[2*x(1)+x(2), x(1) ; 3*x(2).^2 , 1 + 6*x(1).*x(2)];   %partial derivative
  %left to right: func 1 dx1/dF, func 1 dx2/dF ; func 2: dx1/dF, func 2 dx2/dF
dx=A\F;
x=x-dx;
k=k+1;
end
k;

x';
F';


function [x,f,ea,iter]=newtmult(func,x0,es,maxit,varargin)
% newtmult: Newton-Raphson root zeroes nonlinear systems
% [x,f,ea,iter]=newtmult(func,x0,es,maxit,p1,p2,...):
% uses the Newton-Raphson method to find the roots of
% a system of nonlinear equations
% input:
% func = name of function that returns f and J
% x0 = initial guess
% es = desired percent relative error (default = 0.0001%)
% maxit = maximum allowable iterations (default = 50)
% p1,p2,... = additional parameters used by function
% output:
% x = vector of roots
% f = vector of functions evaluated at roots
% ea = approximate percent relative error (%)
% iter = number of iterations
if nargin<2,error('at least 2 input arguments required'),end
if nargin<3||isempty(es),es=0.0001;end
if nargin<4||isempty(maxit),maxit=50;end
iter = 0;
x=x0;
while (1)
[J,f]=func(x,varargin{:});
dx=J\f;
x=x-dx;
iter = iter + 1;
ea=100*max(abs(dx./x));
if iter>=maxit||ea<=es, break, end
end
