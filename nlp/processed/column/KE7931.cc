#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <math.h>
#include <iomanip>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>


using namespace std;


struct mas{ int height, num; };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<mas> Arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		Arr.push_back({ a, i });
	}
	long long ansv = 0;
	int firstmax = 0;
	for (int i = 0; i < n;)
	{
		long long water = 0;
		bool flag = false;
		i++;
		while (i < n && Arr[firstmax].height > Arr[i].height)
		{
			water += Arr[firstmax].height - Arr[i].height;
			flag = true;
			i++;
		}

		if (i != n)
		{
			ansv += water;
			firstmax = i;
		}
		if (i == n && flag)
		{
			mas maxnum = { -1, -1 };
			for (int j = firstmax + 1; j < n; j++)
			{
				if (j==n-1)
				{
					if (Arr[j].height > Arr[j - 1].height)
						if (Arr[j].height > maxnum.height)
							maxnum = Arr[j];
					continue;
				}
				if (Arr[j].height > Arr[j - 1].height && Arr[j].height >= Arr[j + 1].height)
					if (Arr[j].height > maxnum.height)
						maxnum = Arr[j];
			}
			if (maxnum.height == -1)
				break;
			for (int j = firstmax + 1; j < maxnum.num; j++)
				ansv += min(Arr[firstmax].height,Arr[maxnum.num].height) - Arr[j].height;
			firstmax = maxnum.num;
			i = firstmax;
		}
	}
	cout << ansv;

	

	
}