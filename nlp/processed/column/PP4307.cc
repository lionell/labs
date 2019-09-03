#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0, anst = 0, s = -1, f;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    f = n - 1;
    while (a[f] <= a[f-1])
            f--;

    if (a[0] > a[1])
        s = 0;

    for (int i = 1; i < f; i++)
    {
        if (s != -1)
        {
            if (a[s] - a[i] > 0)
                anst += a[s] - a[i];
            else
            {
                ans += anst;
                anst = 0;
                s = i;
            }
        }

        if ((s == -1) && (a[i] > a[i+1]) && (a[i] >= a[i-1]))
            s = i;
    }

    ans += anst;
    if (a[f] < a[s])
        ans -= (a[s] - a[f]) * (f - s - 1);
    cout << ans;
    return 0;
}
