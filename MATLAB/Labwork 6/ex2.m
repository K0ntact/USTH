clc;
clear;
clf;

f = @(xy) xy(1)*xy(2)*exp(-(xy(1)^2 + xy(2)^2));

options = optimset('Display', 'iter','TolFun', 1e-8);

hold on
[xy, fval, exitflag, output] = fminsearch(f, [0; 0]);
xy(1)
xy(2)

x = [-2: .15: 2];
y = [-2: .15: 2];

[xx, yy] = meshgrid(x, y);
z = xx.*yy.*exp(-(xx.^2+yy.^2));

mesh(x, y, z)
meshc(xx,yy,z)
xlabel("x")
ylabel("y")
zlabel("f(x,y)")
title("f(x,y) = x=y=exp(-(x^2 + y^2))")

grid on
hold off