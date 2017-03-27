function Y = scale2im(X)
    T = X - min(min(X));
    Y = uint8(T ./ max(max(T)) * 255);
end