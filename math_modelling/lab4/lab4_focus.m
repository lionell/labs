%% Read image
U = double(imread('lab4/data/y6.BMP'));

figure
imshow(scale2im(U))
title('Unfocused image')

%% Focus image
[F, r] = autofocus(U, 3, 10);
disp(r);
figure
imshow(scale2im(F))
title('Auto-focused image with r=' + string(r))
