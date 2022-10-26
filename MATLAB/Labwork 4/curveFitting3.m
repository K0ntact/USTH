%Exercise 3
x = [0.00000 0.78540 1.57080 2.35619 3.14159 3.92699 4.71239 5.49779 6.28319];
fx = [0.00000 0.70711 1.00000 0.70711 0.00000 -0.70711 -1.00000 -0.70711 0.00000];

x1 = 3;
x2 = 4.5;

figure;
box on;
hold on;
y1 = interp1(x, fx, x1);
y2 = interp1(x, fx, x2);
plot(x, fx, 'b-.o', 'LineWidth', 1);
plot(x1, y1, 'r*', 'LineWidth',5);
plot(x2, y2, 'k*', 'LineWidth',5);
xlabel('x');
ylabel('f(x');
legend('F(x)', 'F(3)', 'F(4.5)');