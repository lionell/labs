function H = blurmat(m, n, r)
    H = zeros(m, n);
    for y = 1:m
        for x = 1:n
            if (x - r - 1)^2 + (y - r - 1)^2 <= r^2
                H(y, x) = 1 / (pi * r^2);
            else
                H(y, x) = 0;
            end
        end
    end
end