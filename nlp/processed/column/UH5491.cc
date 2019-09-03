#include<bits/stdc++.h>
using namespace std;
long long ans;
int a[10000001],m;
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
        m=max(m,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==m){l=i;break;}
    }
    for(int i=n;i>=1;i--)
    if(a[i]==m){r=i;break;}
    for (int i=l; i<=r;i++)
    ans+=m-a[i];
    m=0;
for (int i=1; i<=l;i++){
    m=max(m, a[i]);
    ans+=m-a[i];
}
m=0;
for (int i=n; i>=r;i--){
   m=max(m, a[i]);
   ans+=m-a[i];
}
cout<<ans;
}
