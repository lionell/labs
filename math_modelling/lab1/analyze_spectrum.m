function [freqs, shifts] = analyze_spectrum(Y)
    L = length(Y);
    S = fft(Y);
    S = S(1:round(L/2));
    freqs = 2*abs(S)/L;
    shifts = imag(S);
end
