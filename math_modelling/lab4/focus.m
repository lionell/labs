function Y = focus(Z, r)
    [m, n] = size(Z);
    X = blurmat(m, n, r);
    Y = ifft2(fft2(Z) ./ fft2(X));
end