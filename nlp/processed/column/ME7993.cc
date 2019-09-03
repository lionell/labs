#include <iostream>
using namespace std;
int main()
{
	int n,max[10000],nom=0,k=1,mak=0;
	cin>>n;
	int mas[n];
	max[10000]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>mas[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			nom=0;
			if(mas[i]<=mas[j]&&j!=i)
			{
				nom=j;
				break;
			}
		}
		if(nom>=i)
		{
			for(int g=nom;g>=i;g--)
			{
				if(mas[g]!=0&&mas[i]!=0&&mas[g]<mas[i])
				max[k]=max[k]+mas[i]-mas[g];
			}
			k++;
		}
		else
		{
			for(int g=i;g>=nom;g--)
			{
				if(mas[g]!=0&&mas[i]!=0&&mas[g]<mas[i])
				max[k]=max[k]+mas[i]-mas[g];
			}
			k++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mak<max[i])
		{
			mak=max[i];
		}
	}
	cout<<mak;
	return 0;
}
