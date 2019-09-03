#include<bits/stdc++.h>
using namespace std;

const int N=1e7+1;

short int a[N+1];

short int suf[N+1],pref;

int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long ans=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=n;i>=1;--i){
        if (a[i]>suf[i+1])suf[i]=a[i];
        else suf[i]=suf[i+1];
    }
    pref=a[1];
    for (int i=1;i<=n;++i){
        pref=max(pref,a[i]);
        ans+=min(pref,suf[i])-a[i];
    }
    cout<<ans;
}
