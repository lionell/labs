#include <bits/stdc++.h>
using namespace std;
long long n,i,x,maxl,maxr,a[10000007],l[10000007],r[10000007],sum;
int main()
{
    scanf("%lld",&n);
    l[1]=0;
    r[n]=0;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=2;i<=n;i++){
     maxl=max(maxl,a[i-1]);
     l[i]=maxl;
    }
    for(i=(n-1);i>=1;i--){
     maxr=max(maxr,a[i+1]);
     r[i]=maxr;
    }
    for(i=1;i<=n;i++){
     x=min(l[i],r[i]);
     if(a[i]<x)sum+=(x-a[i]);
    }
    cout<<sum<<endl;
}
