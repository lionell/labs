#include <bits/stdc++.h>
using namespace std;

int firstMax = -1, lastMax = -1;
short a[10000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int maxim = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == maxim)
        {
            lastMax = i;
        }
        else if(a[i] > maxim)
        {
            maxim = a[i];
            firstMax = i;
            lastMax = i;
        }
    }
    long long ans = 0;

    for(int i = firstMax; i <= lastMax; i++)
    {
        ans += maxim - a[i];
    }
    maxim = -1;
    for(int i = 0; i < firstMax; i++)
    {
        if(a[i] > maxim)
        {
            maxim = a[i];
        }
        else
        {
            ans += maxim - a[i];
        }
    }
    maxim = -1;
    for(int i = n - 1; i > lastMax; i--)
    {
        if(a[i] > maxim)
        {
            maxim = a[i];
        }
        else
        {
            ans += maxim - a[i];
        }
    }
    cout << ans;
    return 0;
}

