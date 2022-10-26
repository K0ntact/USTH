%Exercise 4
x = -3:0.1:3;
y = -3:0.1:3;
[X,Y] = meshgrid(x,y);
Z = peaks(X,Y);

figure
surf(X,Y,Z);
title('3D Surface')

%Compute
fprintf("COmpute z(1.2, 2.8 \n");
x1 = 1.2;
y1 = 2.8;