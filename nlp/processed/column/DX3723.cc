#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
//const ll mx=-10000000;

int m,c,p,v,o,l,r,n;
ll ans;
 int a[10000001];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v=max(v,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(v==a[i]){l=i;break;}
    }
    for(int i=n;i>=1;i--)
    if(a[i]==v){r=i;break;}
    for(int i=l;i<=r;i++)
        ans+=v-a[i];
     v=0;
    for(int i=1;i<=l-1;i++)
    {
        v=max(v,a[i]);
        ans+=v-a[i];

    }
    v=0;
    for(int i=n;i>=r+1;i--)
    {
        v=max(v,a[i]);
        ans+=v-a[i];

    }
    cout<<ans;

}
