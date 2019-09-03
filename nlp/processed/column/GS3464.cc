#include <bits/stdc++.h>
#define dim 10000009
using namespace std;
typedef long long ll;
ll L[dim],a[dim],n;
int main()
{
    scanf("%lld", &n);
    a[0] = 0;
    ll mi = 0;
    for (int i = 1; i <= n; i++)
    {
        L[i] = mi;
        scanf("%lld", &a[i]);
        mi = max(mi, a[i]);
    }
    mi = 0;
    ll res = 0;
    for (int i = n; i >= 1; i--)
    {
        res += max( (ll) 0 , min( mi,L[i] ) - a[i]);
        mi = max(mi,a[i]);
    }
    printf("%lld\n", res);
    return 0;
}
