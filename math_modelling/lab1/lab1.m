%% Clear up
clc;
clear;

%% Setup signal params
T = 5;
freq = 100;
dt = 1/freq;

%% Read input signal
t = 0:dt:5;
data = dlmread('data/f10.txt');
len = length(data);

%% Plot input signal
figure
plot(t, data)
title('Input signal')
xlabel('t (seconds)')
ylabel('f(t)')

%% Spectral analysis
[freqs, shifts] = analyze_spectrum(data);

locs = findpeaks(freqs);
peaks = freqs(locs);
peak_freqs = (locs - 1)/T;

disp('peak_freqs = ');
disp(peak_freqs);

%% Plot signal spectrum
f = (0:length(freqs) - 1)/T;
figure
plot(f, freqs, peak_freqs, peaks, 'ro')
title('Signal spectrum')
xlabel('f (Hz)')
ylabel('|FFT(f)|')

%% Calculate coeficients
var_cnt = length(peak_freqs) + 4;
A = zeros(size(t));
for i = 1:len
	for j = 1:var_cnt
		if j <= 4
			A(i, j) = t(i)^(j - 1);
		else
			A(i, j) = sin(2*pi*peak_freqs(j - 4)*t(i));
		end
	end
end

coefs = pinv(A)*data';

disp('Coefs(1:7):');
disp(coefs(1:7));

%% Calculate approximation
approx = zeros(size(data));
for i = 1:len
	for j = 1:var_cnt
		if j <= 4
			approx(i) = approx(i) + coefs(j)*t(i)^(j - 1);
		else
			approx(i) = approx(i) + coefs(j)*sin(2*pi*peak_freqs(j - 4)*t(i));
		end
	end
end

%% Plot original vs approximation
figure

subplot(2, 1, 1)
plot(t, data)
title('Original')
xlabel('t (seconds)')
ylabel('f(t)')

subplot(2, 1, 2)
plot(t, approx, 'r')
title('Approximation')
xlabel('t (seconds)')
ylabel('f(t)')

%% Calculate MSE
mse = sum((data - approx).^2);

disp('MSE:');
disp(mse);
