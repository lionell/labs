#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, square = 0;
	int a[100000], b[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int max1 = b[n - 1];
	int max2 = b[n - 2];
	int i;
	i = 0;
	int max = 0;
	while (a[i] != max1 && a[i] != max2)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		else
		{
			square += max - a[i];
		}
		i++;
	}
	int pos_max1 = i;
	i = n - 1;
	while (a[i] != max1 && a[i] != max2)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		else
		{
			square += max - a[i];
		}
		i--;
	}
	int pos_max2 = i;
	int v = min(max1, max2);
	for (i = pos_max1; i <= pos_max2; i++)
	{
		square += v - a[i];
	}
	cout << square << endl;
	return 0;
}