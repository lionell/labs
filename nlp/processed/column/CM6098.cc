#include <bits/stdc++.h>
using namespace std;
int prefix[10000000], suffix[10000000], mas[10000000];
int n=0;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> mas[i];
    }
    int Max=INT_MIN;
    for (int i=0; i<n; i++)
    {
        Max = max(Max, mas[i]);
        prefix[i] = Max;
    }
    Max = INT_MIN;
    for (int i=n-1; i>=0; i--)
    {
        Max = max(Max, mas[i]);
        suffix[i] = Max;
    }
    int Min=0;
    long long sum=0;
    for (int i=1; i<n-1; i++)
    {
        int a= prefix[i-1],b=suffix[i+1];
        int Min = min(a,b);
        if (Min>mas[i])
            sum+=Min-mas[i];
    }
    cout << sum;
}
