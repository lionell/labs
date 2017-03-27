function locs = findpeaks(Y)
    locs = [];
    for i = 2:length(Y) - 1
        if Y(i) >= Y(i - 1) && Y(i) >= Y(i + 1)
            locs = [locs i];
        end
    end
end

