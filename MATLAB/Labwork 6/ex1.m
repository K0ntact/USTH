clc;
clear;
clf;

f = @(x) -(x^3)*exp(-x);
a = 1;
b = 4;
options = optimset('Display', 'iter', 'TolFun', 1e-8);

hold on

[x, fval, info, output] = fminbnd(f, a, b, options);
fprintf('Minf = %4f at x = %4f0', fval, x);
fplot(f, [1 4], 'b');
plot(x, f(x), 'r+');
grid on
hold off