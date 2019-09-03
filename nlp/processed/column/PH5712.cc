#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
	int n,i,t,k,max1,max2,imax1,k1,imax2;
	long long s=0,s1;
	cin>>n;
	vector<int> a(n);
	for(i=0;i<n;i++) cin>>a[i];
	i=0;
	while(i<n-1)
	{
		if(a[i]>a[i+1])
		{
			s1=0;t=a[i];k=i;i++;
			while((t>a[i])&&(i<n))
			{
				s1=s1+t-a[i];
				i++;				
			}
			if(i!=n)
			{
				s=s+s1;				
			}
			else
			{
				s1=0;i=k;max1=t;imax1=k;
				while(i<n-1)
				{
					if(a[i]>a[i+1])
					{
						while((a[i]>=a[i+1])&&(i<n-1))
						{
							i++;
						}
						if(i!=(n-1))
						{
							k1=i;max2=-1;
							for(i=k1;i<n;i++)
							{
								if(a[i]>max2)
								{
									max2=a[i];
									imax2=i;
								}
							}
							for(i=imax1+1;i<imax2;i++)
							{
								if(a[i]<max2) s=s+max2-a[i];
							}
							max1=max2;imax1=imax2;i=imax2;
						}
					}else i++;
				}
			}
		}else i++;
	}
	cout<<s;
}
