#include <iostream>
#include <algorithm>

using namespace std;
int check(int columns[], int position, int n)
{
	int answer = 0;
	int max = columns[position+1];
	for(int i = position+1; i < n; i++)
	{
		if(columns[i]>columns[max])
		{
			max = i;
		}
		if(columns[i] >= columns[position])
		{
			answer = i;
			return answer;
		}
	}
	return max;
}
int main()
{
	int n; 
	int result = 0;
	cin >> n;
	int columns[n];
	for(int i = 0; i < n; i++)
	{
		cin >> columns[i];
	}
	for(int i = 0; i < n; i++)
	{
		int j = check(columns, i, n);
		if(j - i > 1)
		{
			for(int k = i+1; k < j; k++)
			{
				result += min(columns[i],columns[j]) - columns[k];
			}
		}
	}
	cout << result;
	return 0;
}
