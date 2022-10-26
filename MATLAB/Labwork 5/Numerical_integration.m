clc;
clear;
clf;

x = linspace(0, 0.8);
x = x';
y = 0.2 + 25*x - 200*x.^2 + 675*x.^3 - 900*x.^4 + 400*x.^5;

%trapz(x,y):  integrates Y with respect to X
Q = trapz(x, y);

f = @(x) 0.2 + 25*x - 200*x.^2 + 675*x.^3 - 900*x.^4 + 400*x.^5;
hold on
grid on
plot(x, f(x), 'b-')
plot(x(1:length(Q)), Q, 'r.');
hold off