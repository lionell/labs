#include <bits/stdc++.h>

#define D 10000007

using namespace std;

long long a[D], l[D];

int main()
{
    long long res = 0, n, x, maxi = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        maxi = max(maxi, a[i]);
        l[i] = maxi;
    }
    maxi = 0;
    for (int i = n; i >= 1; i--)
    {
        res += max(min(maxi, l[i]) - a[i], (long long) 0);
        maxi = max(maxi, a[i]);
    }
    printf("%lld\n", res);
    return 0;
}
