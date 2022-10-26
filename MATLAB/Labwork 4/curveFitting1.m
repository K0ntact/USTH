%Exercise 1
%part a
students = ["Lan Anh", "Van Toan", "Quang Hai", "Xuan Truong", "Cong Phuong", "Huyen My", "My Linh", "Duc Chinh", "Phan Van Duc"];
weight = [40 63 62 68 64 45 50 66 67];
JHI = [1450 3817 3708 4300 3950 1896 2339 4200 4312];
VanLam = 72;


f = fit(weight', JHI', 'poly1');
func = @(x) f.p1*x + f.p2;
figure
hold on
grid on
box on
fplot (func, [20 80], 'g');
plot(weight', JHI', 'b*', 'LineWidth', 2);
plot(VanLam, func(VanLam), 'r*', 'LineWidth', 2);
legend('Linear Equation', 'Other players', 'Van Lam');
hold off

%part b
f = polyfit(weight, JHI, 2);
func = @(x) f(1)*x^2 + f(2)*x + f(3);
figure
hold on
grid on
box on
fplot(func, [20 80], 'g');
plot(weight', JHI', 'b*', 'LineWidth', 2);
plot(VanLam, func(VanLam), 'r*', 'LineWidth', 2);
legend('Linear Equation', 'Other players', 'Van Lam');
hold off

%part c
c = @(f, x) f(1)*x + f(2);
a = lsqcurvefit(c, [2;3], weight, JHI);
func = @(x) a(1)*x + a(2);
figure
hold on
grid on
box on
fplot(func, [20 80], 'g');
plot(weight', JHI', 'b*', 'LineWidth', 2);
plot(VanLam, func(VanLam), 'r*', 'LineWidth', 2);
legend('Linear Equation', 'Other players', 'Van Lam');
hold off


