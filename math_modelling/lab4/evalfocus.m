function err = evalfocus(X)
    [m, n] = size(X);
    err = 0;
    for y = 1:m
        for x = 1:n
            e = 0;
            c = 0;
            if y > 1
                e = e + abs(X(y, x) - X(y - 1, x));
                c = c + 1;
            end
            if y < m
                e = e + abs(X(y, x) - X(y + 1, x));
                c = c + 1;
            end
            if x > 1
                e = e + abs(X(y, x) - X(y, x - 1));
                c = c + 1;
            end
            if x < n
                e = e + abs(X(y, x) - X(y, x + 1));
                c = c + 1;
            end
            err = err + e / c;
        end
    end
end