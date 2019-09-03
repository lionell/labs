#include<bits/stdc++.h>
using namespace std;
long long ans;
int a[10000001],t;
int l,r,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
cin>>n;
for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t=max(t,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==t){l=i;break;}
    }
    for(int i=n;i>=1;i--)
    if(a[i]==t){r=i;break;}
    for (int i=l; i<=r;i++)
    ans+=t-a[i];
    t=0;
for (int i=1; i<=l;i++){
    t=max(t, a[i]);
    ans+=t-a[i];
}
t=0;
for (int i=n; i>=r;i--){
   t=max(t, a[i]);
   ans+=t-a[i];
}
cout<<ans;
}
