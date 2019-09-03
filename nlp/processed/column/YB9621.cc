#include <iostream>
using std::cin;
using std::cout;
int *asan;

int Calculate(int Left, int Right)
{
	int Result=0, max=0;

	if(asan[Left]<asan[Right]) max=asan[Left];
	else max=asan[Right];

	for(int i=Left+1; i<Right; i++) Result=Result + max - asan[i];

	return Result;
}

int main()
{
	int a, Left=0, Right=0, prom=0, V=0;

	cin>>a;
	a=a+2;
	asan=new int [a];
	asan[0]=0;
	asan[a-1]=0;

	for(int i=1; i<a-1; i++) cin>>asan[i];

	for(int j=0; j<(a-1); j++)
	{
		if(asan[Left]<=asan[j+1])
		{
			if(Right!=Left)
			{
				Right=j+1;
				if(Right-Left!=1) V=V+Calculate(Left, Right);
				Left=Right;
				prom=Right;
				Right--;
			}
			else 
			{
				Left=j+1;
				if(asan[Left]<=asan[j+2]) Right=Left;
			}
		}
	}

	Left=a-1;
	Right=a-1;
	for(int j=a-1; j>=0; j--)
	{
		if(asan[Left]<=asan[j-1])
		{
			if(Right!=Left)
			{
				Right=j-1;
				if(Left-Right!=1 && asan[Left]<=asan[Right] && Right>=prom) V=V+Calculate(Right, Left);
				Left=Right;
				Right++;
			}
			else 
			{
				Left=j-1;
				if(asan[Left]<=asan[j-2]) Right=Left;
			}
		}
	}

	cout<<V;
	return 0;
}
