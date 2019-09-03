  #include<bits/stdc++.h>
  using namespace std;

  short int a[10000001], b[10000001];

  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, mx_l = -1, mx_r = -1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
     {
        cin >> a[i];
        if (a[i] < mx_l) b[i] = mx_l - a[i];
        else {mx_l = a[i]; b[i] = 0;}
     }
     for (int i = n - 1; i >= 0; --i)
     {
         if (a[i] < mx_r) ans += min((long long)b[i], mx_r - a[i]);
         else mx_r = a[i];
     }
     cout << ans;

  }
