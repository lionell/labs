#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define DIM 10000005

ll a[DIM],maxl[DIM],maxr[DIM];

int main()
{
    ll n;
    scanf("%lld",&n);
    ll mx = -1;
    for (ll i = 1; i <= n; i++)
    {
        maxl[i] = mx;
        scanf("%lld", &a[i]);
        mx = max(mx,a[i]);
    }

    mx = -1;
    for (ll i = n; i >= 1; i--)
    {
        maxr[i] = mx;
        mx = max(mx,a[i]);
    }

    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll r = min(maxl[i],maxr[i]);
        if (a[i] < r)
            res += r - a[i];
    }
    printf("%lld\n", res);
}
