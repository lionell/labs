#include<iostream>
#include<stdio.h>
using namespace std;
int arr[10000000];
int main()
{
	long long n , i1 , i2 , leftMAX , ind1 = 0 , ind2 , rightMAX , count = 0;
	cin >> n;
	ind2 = n-1;
	for(long long i = 0;i < n;i++)
		scanf("%lld" , &arr[i]);
	i1 = 0;i2 = n-1;
	leftMAX = arr[0];rightMAX = arr[n-1];
	while(i2 >= 0)
	{
		if(arr[i1] >= leftMAX)
		{
			for(int i = i1-1;i >= ind1;i--)
			{
				count += leftMAX - arr[i];
				arr[i] += leftMAX - arr[i];
				
			}
			
			leftMAX = arr[i1];
			ind1 = i1;
		}
		if(arr[i2] >= rightMAX)
		{
			for(int i = i2+1;i <= ind2;i++)
			{
				count += rightMAX - arr[i];
				arr[i] += rightMAX - arr[i];
			}
			rightMAX = arr[i2];
			ind2 = i2;
		}
		i1++;
		i2--;
	}
	cout << count;
}
