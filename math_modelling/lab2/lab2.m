%% Global constants
eps = 0.001;

X = double(imread('lab2/data/x1.bmp'));
Y = double(imread('lab2/data/y1.bmp'));

[m, n] = size(X);
m = m + 1;
X(m, :) = ones(1, n);

A0 = Y*pinv(X);
Y0 = A0*X;
A1 = Y*pminv(X, eps);
Y1 = A1*X;
A2 = Y*greville(X);
Y2 = A2*X;

disp('Y/Y0 err =');
disp(norm(Y - Y0));

disp('Y/Y1 err =');
disp(norm(Y - Y1));

disp('Y/Y2 err =');
disp(norm(Y - Y2));
