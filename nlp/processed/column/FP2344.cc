#include<bits/stdc++.h>

using namespace std;

const int N=1e7+5,
        INF=1e9+7;

int n;
short int a[N], mx;
long long ans;
int l, r;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for (int i=1; i<=n; ++i){
        cin>>a[i];
        mx=max(mx, a[i]);
    }
    for (int i=1; i<=n; ++i){
        if (a[i]==mx) {l=i; break;}
    }
    for (int i=n; i>=1; --i){
        if (a[i]==mx) {r=i; break;}
    }
    for (int i=l; i<=r; ++i){
        ans+=mx-a[i];
    }
    mx=0;
    for (int i=1; i<l; ++i){
        mx=max(mx, a[i]);
        ans+=mx-a[i];
    }
    mx=0;
    for (int i=n; i>r; --i){
        mx=max(mx, a[i]);
        ans+=mx-a[i];
    }
    cout<<ans;
}
