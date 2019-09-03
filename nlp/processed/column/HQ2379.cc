#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* dat = new int[n];
	int max = 0;
	long long result = 0;
	for (int i = 0; i<n; i++) {
		cin >> dat[i];
		if (dat[i]>max)
			max = dat[i];
		else
			result += max - dat[i];
	}
	int lastMax = dat[n - 1];
	for (int i = n - 1; i >= 0 && dat[i] != max; i--) {
		if (dat[i]>lastMax)
			lastMax = dat[i];
		result -= max - lastMax;
	}
	cout << result;
    return 0;
}

