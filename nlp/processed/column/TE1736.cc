//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long m[10000005];

int main()
{
	long long n, maxf, maxl, maxv=-1, i, j, res=0, maxt;

	scanf("%lld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &m[i]);
		if (m[i] > maxv)
		{
			maxf = i;
			maxl = i;
			maxv = m[i];
		}
		else if (m[i] == maxv)
		{
			maxl = i;
		}
	}

	for (i = maxf + 1; i < maxl; i++)
	{
		res += (maxv - m[i]);
	}

	maxt = m[0];
	for (i = 1; i < maxf; i++)
	{
		if (maxt > m[i])
		{
			res += (maxt - m[i]);
		}
		else if (maxt < m[i])
		{
			maxt = m[i];
		}
	}

	maxt = m[n-1];
	for (i = n-2; i > maxl; i--)
	{
		if (maxt > m[i])
		{
			res += (maxt - m[i]);
		}
		else if (maxt < m[i])
		{
			maxt = m[i];
		}
	}


	printf("%lld", res);

	return 0;
}