#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int mxl[10000000], arr[10000000];

int main()
{
	long long sum = 0;
	int n;
	cin >> n;
	int mxrp = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		if (i > 0) {
			mxl[i] = max(mxl[i-1], arr[i]);
		}
		else
			mxl[i] = arr[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		int mxr = max(mxrp, arr[i]);
		mxrp = mxr;
		sum += max(0, min(mxr, mxl[i]) - arr[i]);
	}
	cout << sum;
}
