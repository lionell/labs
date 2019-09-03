#include <bits/stdc++.h>
using namespace std;

long long n,s=0;
vector <long long> A;
vector <long long> B;

void urav()
{
    for(long long i=1; i<=n; i++)
    {
        long long j=i;
        while (A[j]==A[j+1]) j++;
        if (j>n) j=n;
        for(long long r=i+1; r<=j; r++) B[i]=B[i]+B[r];
        for (long long r=i+1; r<=n-j+i; r++) {A[r]=A[r+j-i]; B[r]=B[r+j-i];}
        n-=(j-i);
        if (j!=i)
        {
        i=0;
        }
    }
}

int main () {
	cin >> n;
	A.resize(n+4,0);
	B.resize(n+4,1);
	for(long long i = 1; i <= n; i ++)
		cin >> A[i];
	urav();
	for(long long i = 1; i <= n - 2;)
	{
		if (min(min(A[i],A[i+1]),A[i+2])==A[i+1])
		{
			long long r = min(A[i],A[i+2]);
			s = s+(r-A[i+1])*B[i+1];
			A[i+1]=r;
		}
		else
		if (max(max(A[i],A[i+1]),A[i+2])==A[i] && min(min(A[i],A[i+1]),A[i+2])==A[i+2])
		{
			bool flag=false;
			long long qq=-1;
			for(long long j=i+2; j<=n; j++)
				if (A[j]>A[i+2])
				{
					qq=max(qq,A[j]);
					flag=true;
				}
			if (flag)
			{
				long long ww=min(qq,A[i+1]);
				s=s+(ww-A[i+2])*B[i+2];
				A[i+2]=ww;
			}
			else
			i++;
		}
		else
		i++;
		urav();
	}
	cout << s;
}
