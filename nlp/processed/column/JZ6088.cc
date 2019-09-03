#include<bits/stdc++.h>

using namespace std;

int data[10000000];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    long long ind = 0, ans = 0, cur = 0;

    for(int i = 1; i < n; i++)
    {
        if(data[i] >= data[ind])
        {
            ans += cur;
            cur = 0;
            ind = i;
        }
        else
        {
            cur += data[ind] - data[i];
        }
    }

    cur = 0;

    int ind2 = n-1;

    for(int i = n - 2; i >= ind; i--)
    {
        if(data[i] >= data[ind2])
        {
            ans += cur;
            cur = 0;
            ind2 = i;
        }
        else
        {
            cur += data[ind2] - data[i];
        }
    }

    cout << ans;
}
