#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    long long n, ans = 0;
    cin >> n;
    vector <long long> a, l, r;
    a.resize(n);
    l.resize(n);
    r.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    l[0] = a[0];
    r[n-1] = a[n-1];
    for (int i = 1; i < n; i++)
        l[i] = max(l[i-1],a[i]);
    for (int i = n - 2; i >= 0; i--)
        r[i] = max(r[i+1],a[i]);
    for (int i = 0; i < n; i++)
        ans += min(r[i],l[i]) - a[i];
    cout << ans << endl;
}
