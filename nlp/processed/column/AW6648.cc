#include<bits/stdc++.h>

using namespace std;

long long n;
int a[10000001];
int mx=-100000001, l, r, v;
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        mx=max(mx, a[i]);
    }
    for (int i=1; i<=n; ++i)
    {
        if (mx==a[i]) {l=i; break;}
    }
    for (int i=n; i>=1; --i)
    {
        if (mx==a[i]) {r=i; break;}
    }
    for (int i=l; i<=r; ++i)
    {
        ans+=mx-a[i];
    }
    for (int i=1; i<=l-1; ++i)
    {
        v=max(a[i], v);
        ans+=v-a[i];
    }
    v=0;
    for (int i=n; i>=r+1; --i)
    {
        v=max(v, a[i]);
        ans+=v-a[i];
    }
    cout<<ans;
}



