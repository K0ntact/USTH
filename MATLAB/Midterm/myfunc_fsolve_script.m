clc
clear all
fun = @myfun;
x0 = [0,0];
[x,fval] = fsolve(fun,x0);
