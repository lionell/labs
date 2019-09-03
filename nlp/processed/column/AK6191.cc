#include<bits/stdc++.h>

using namespace std;
int n;
int a[10000001];	
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	vector <int> res1;
	vector <int> res2;
	int l(0) , r(0);
	long long result(0);
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]<a[i-1])
		{
			l=i-1;
			break;	
		}
	}
	
	for (int i=n-1;i>=1;i--)
	{
		if (a[i]<a[i+1])
		{
			r=i+1;
			break;
		}
	}
	if (l>=r)
	{
		cout << 0;
		return 0;
	}
	else
	{
		res1.push_back(l);
		int maybe_ans(a[l]);
		for (int i=l+2;i<=r;i++)
		{
			if (a[i]>=maybe_ans)
			{
					while(a[i]>=maybe_ans)
					{
						maybe_ans=a[i];
						i++;
					}
				res1.push_back(i-1);
			}			
		}
		res2.push_back(r);
		maybe_ans=a[r];
		for (int i=r-2;i>=l;i--)
		{
			if (a[i]>maybe_ans)
			{
					while(a[i]>maybe_ans)
					{
						maybe_ans=a[i];
						i--;
					}
				res2.push_back(i+1);
			}	
		}	
	}
	if (res1.size()>1)
	{
		for (int i=0;i<res1.size()-1;i++)
		{
			int maax , miin;
			maax=max(a[res1[i]] , a[res1[i+1]]);
			miin=min(a[res1[i]] , a[res1[i+1]]);
			for (int j=res1[i] ;j<=res1[i+1];j++)
			{
				(miin-a[j])>0 ? result+=miin-a[j] : result+=0;
			}
		}
	}
	if (res2.size()>1)
	{
		
		for (int i=0;i<res2.size()-1;i++)
		{
			int maax , miin;
			maax=max(a[res2[i]] , a[res2[i+1]]);
			miin=min(a[res2[i]] , a[res2[i+1]]);
			for (int j=res2[i+1] ;j<=res2[i];j++)
			{
				(miin-a[j])>0 ? result+=miin-a[j] : result+=0;
			}
		}
	}
	cout << result;
}
/*
11 2 1 2 3 4 3 2 1 2 3 4
*/
