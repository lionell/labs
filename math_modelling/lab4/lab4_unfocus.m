%% Read image
O = double(imread('lab2/data/y10.BMP'));

figure
imshow(scale2im(O))
title('Original image')

%% Unfocus image
r = 7;
U = unfocus(O, r);
figure
imshow(scale2im(U))
title('Unfocused image with r=' + string(r))
