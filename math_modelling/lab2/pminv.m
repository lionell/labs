function Y = pminv(X, eps)
	%% Penrose-Moore
	[m, n] = size(X);
	err = inf;
	ds = 1;
	prev = X';
	while err > eps
		next = (X'*X + ds*eye(n))\X';
		err = norm(next - prev);
		prev = next;
		ds = ds/2;
	end
	Y = next;
end
