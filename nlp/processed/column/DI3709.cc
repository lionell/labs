#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7+2;

long long q[N], h = 0;
long long n, a[N], l[N], r[N];

signed main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    //n = 1e7;
    //a[1] = 1e9;
    //a[n] = 1e9;
    a[0] = 2e9;
    a[n+1] = 2e9;
    q[0] = 0;
    h = 1;
    for (long long i = 1; i <= n; i++)
    {
        while (1)
        {
            long long p = q[h-1];
            if (a[p] <= a[i])
                h--;
            else
                break;
        }
        l[i] = q[h-1];
        q[h] = i;
        h++;
    }
    h = 1;
    q[0] = n+1;
    for (long long i = n; i > 0; i--)
    {
        while (1)
        {
            long long p = q[h-1];
            if (a[p] <= a[i])
                h--;
            else
                break;
        }
        r[i] = q[h-1];
        q[h] = i;
        h++;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        if (l[i] > 0 && r[i] < n+1 && a[i] != a[i-1])
        {
            long long p = min(a[l[i]], a[r[i]]);
            ans += (r[i]-l[i]-1)*(p-a[i]);
        }
    //cout << clock()<<endl;
    cout << ans << endl;
    return 0;
}
