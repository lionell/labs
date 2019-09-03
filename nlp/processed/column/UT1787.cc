#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define debug

main()
{
    #ifdef debug
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // debug
    int n, sum = 0;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
//    for (int i = 0; i < n; ++i)
//    {
//        if (i == 0 || i == n - 1)a[i] = 10000;
//        else a[i] = 0;
//    }
    int l = 0, r = n - 1;
    while (l < r)
    {
        while (a[l] < a[l + 1] && l < r)++l;
        while (a[r] < a[r - 1] && l < r)--r;
        if (a[l] > a[r])
        {
            int r_a = a[r];
            while (a[r] <= r_a && l < r)
            {
                sum += r_a - a[r];
                --r;
            }
        }
        else
        {
            int l_a = a[l];
            while (a[l] <= l_a && l < r)
            {
                sum += l_a - a[l];
                ++l;
            }
        }
    }
    printf("%lld", sum);
    return 0;
}
