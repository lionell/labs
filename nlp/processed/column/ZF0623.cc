#include <bits/stdc++.h>
using namespace std;

int n, max_right_i = -1, max_right;
long long sum = 0;
vector<int> a, max_left;

main() {
	scanf("%d", &n);

	a.assign(n, 0);
	max_left.assign(n, 0);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
        max_left[i] = (i > 0) ? max(max_left[i-1], a[i]) : a[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		max_right = max(max_right_i, a[i]);
		sum += max(0, min(max_right, max_left[i]) - a[i]);
		max_right_i = max_right;
	}

	printf("%lld", sum);
}
