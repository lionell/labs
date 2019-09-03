#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int h[10000000], min_max[10000000], N;
long long ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	min_max[0] = h[0];

	for (int i = 1; i < N; i++) 
		min_max[i] = max(min_max[i - 1], h[i]);

	min_max[N - 1] = min(min_max[N-1], h[N-1]);

	for (int i = N - 2; i >= 0; i--)
		min_max[i] = min(min_max[i], max(min_max[i + 1], h[i])),
		ans += min_max[i] - h[i];

	cout << ans << endl;

	return 0;
}