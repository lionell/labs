#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long int n,pa,a,b[10001]={0},c[10001]={0},i,j,l=999999999,maxi=-999999999,kilk=0;
	bool flag=false,problem=false;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> a;
		maxi=max(maxi,a);
		if (i>=2){
					if (flag)
							{
								if (pa<a){
												for (j=min(a,l)-1;j>=0;j--)
												{
//													cout << i << " " << j << " " << b[j] << "\n";
													kilk=kilk+((min(a,l)-j)*b[j]);
													if (!(a>=l)) b[min(a,l)]+=b[j];
													b[j]=0;
												}
												
										 }
								if (a>=l){
											l=a;
										 }
									else {
											b[a]++;
										 }		 
							 }
					if (pa>a && !flag){
											l=pa;flag=true;b[a]++;
									  }
					
				 }
		pa=a;
	}
	cout << kilk ;
}
