#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
#define ld long double

const int N = 1e7 + 11;

short int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=b[i-1];
        if (a[i]>b[i]) b[i]=a[i];
    }
    short int l=0;
    ll ans=0;
    for (int i=n; i>=1; i--)
    {
        if (l>a[i]&&b[i-1]>a[i]) ans+=(ll)min(l,b[i-1])-(ll)a[i];
        if (a[i]>l) l=a[i];
    }
    cout<<ans<<endl;
}



