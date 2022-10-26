%%Exercise 1
%Part a
a = 12^2 - 13^2;
disp("Ex 1 a: ")
disp(a)

%Part b
b = 24 * 5 /15;
disp("Ex 1 b: ")
disp(b)

%Part c
c = factorial(7);
disp("Ex 1 c: ")
disp(c)

%Part d
d = 4^2 + 3^3 - 124;
disp("Ex 1 d: ")
disp(d)

%Part e
e = 6/5 * ((1/2) * (1/4) -1);
disp("Ex 1 e: ")
disp(e)


%Exercise 2
%Part a
f = @(x) x^2-9;
a = fzero(f, 10);
disp("Ex 2 a: ")
disp(a)

%Part b
b = fzero(f, 0);
disp("Ex 2 b: ")
disp(b)

%Part c
options = optimset("display", "iter");  %hien thi ket qua vong lap cua fzero
c = fzero(f, 0, options);
disp("Ex 2 c: ")
disp(c)

%Part d
options = optimset("tolx", 10^(-3));        %set sai so la 10^-3
d = fzero(f, 0, options);
disp("Ex 2 d: ")
disp(d)

%Part e
v = [1 0 -9];
e = roots(v);
disp("Ex 2 e: ")
disp(e)

