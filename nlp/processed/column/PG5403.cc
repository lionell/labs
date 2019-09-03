#include<bits/stdc++.h>
#define ff first
#define ss secon
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'

using namespace std;

const int N=1e7+3;

int n;
short int mx;
ll ans;
short int a[N];
short int b[N];

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=max(b[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]<min(mx,b[i]))
        {
            ans+=min(mx,b[i])-a[i];
        }
        mx=max(mx,a[i]);
    }
    cout<<ans;

}
