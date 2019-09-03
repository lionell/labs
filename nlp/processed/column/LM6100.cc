#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int *arr = new int[N+1];

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	arr[N] = 0;

	int *k = new int[N+1];
	for(int i = 0; i < N; i++)
		k[i] = -1;
	
	int p = 0;
	for(int i = 0; i < N; i++)
	{
		if(arr[i] > arr[i + 1] && k[p] < 0)
		{
			k[p] = i;
			if(p > 0)
				if(arr[i] < arr[k[p-1]] && i != N - 1)
				{
					k[p] = -1;
					p--;
				}
			p++;
		}
	}

	int i = 0, min;
	int sum = 0;
	while(k[i+1] != -1)
	{
		if(arr[k[i]] < arr[k[i+1]])
			min = arr[k[i]];
		else
			min = arr[k[i+1]];

		for(int j = k[i]+1; j < k[i+1]; j++)
		{
			if(min - arr[j] > 0)
				sum += (min - arr[j]);
		}
		i++;
	}
	cout << sum;

	
	return 0;
}