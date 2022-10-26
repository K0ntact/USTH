clc;
clear;
clf;

f = @(x) exp(-x)-exp(-x^3)+1;
options = optimset('Display', 'iter','TolFun', 1e-4);

hold on
[x, fval, info, output] = fzero(f, 1, options);

fplot(f, [-1.5 1.5], 'b');
plot(x, f(x), 'r+');
grid on
hold off