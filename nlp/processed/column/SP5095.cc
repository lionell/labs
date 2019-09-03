#include<bits/stdc++.h>
using namespace std;

short int x, b[10000000+10], c[10000000+10];
long long  n,  i, sum, ans;
 main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
       cin>>x;
       sum+=x;
       c[i]=x;
       b[i]=max(b[i-1], x);

    }
    for (i=n;i>=1;i--)
        {
            c[i]=max(c[i+1], c[i]);
            ans+=min(c[i], b[i]);
        }

        ans-=sum;
    cout<<ans;
}
