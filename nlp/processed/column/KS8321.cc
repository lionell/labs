#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    vector<int> a(n),m1(n),m2(n);
    long long ans=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    m1[0]=a[0];
    for(int i=1;i<n;++i){
        m1[i]=max(m1[i-1],a[i]);
    }
    m2[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i){
        m2[i]=max(m2[i+1],a[i]);
    }
    for(int i=0;i<n;++i){
        m=min(m1[i],m2[i]);
        ans+=m-a[i];
    }
    cout<<ans;
    return 0;
}

