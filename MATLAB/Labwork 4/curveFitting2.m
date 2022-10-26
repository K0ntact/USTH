%Exercise 2
x = 0.1:0.1:1;
y = [1.6781 1.5711 1.4771 1.3945 1.3220 1.2584 1.2025 1.1535 1.1104 1.0725];
func = @(t) exp(-t*x)+0.8-y;

x0 = 1;
lb = [0, 1];
ub = [1, 2];

t1 = lsqnonlin(func, x0);
t2 = lsqnonlin(func, x0, lb, ub);

figure
hold on
box on
plot(x, y, 'b*', 'LineWidth',2);
plot(x, exp (-t1*x)+0.8, "Color",'red', 'LineWidth',1);
plot(x, exp (-t2*x)+0.8, "Color",'blue', 'LineWidth',1);
hold off
legend('Data', 'Best fit', 'Best fit with lb, ub1', 'Best fit with lb, ub2');
legend boxoff;
xlabel("x");
ylabel("exp (-t*x)+0.8");