#include <bits/stdc++.h>
using namespace std;


int n;
short a[10000005];
short p[10000005];
long long ans;
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        p[i]=p[i-1];
        if (a[i]>p[i]) p[i]=a[i];
    }
    short last=a[n];
    short x=0;
    for (int i=n-1;i>1;--i) {
        if (last>p[i-1]) x=p[i-1]; else x=last;
        if (x>a[i]) ans+=(long long)(x-a[i]);
        if (a[i]>last) last=a[i];
    }
    cout<<ans;
}

