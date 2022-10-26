clc;
clear;
clf;

x = linspace(0, 0.8);
y = 0.2 + 25*x - 200*x.^2 + 675*x.^3 - 900*x.^4 + 400*x.^5;
f = @(x) 0.2 + 25*x - 200*x.^2 + 675*x.^3 - 900*x.^4 + 400*x.^5;

%Q = dy / dx
Q = diff(f(x))./diff(x);

box on;
hold on
grid on
plot(x, f(x), 'r-')
plot(x(1:length(Q)), Q, 'g.');

df = 25 - 400*x + 2025*x.^2 - 2700*x.^3 + 2000*x.^4;