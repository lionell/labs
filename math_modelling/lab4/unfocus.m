function Z = unfocus(X, r)
    [m, n] = size(X);
    Y = blurmat(m, n, r);
    Z  = ifft2(fft2(X) .* fft2(Y));
end