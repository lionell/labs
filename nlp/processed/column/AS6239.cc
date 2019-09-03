#include<bits/stdc++.h>

using namespace std;

int s[10000000],l[10000000],r[10000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    l[0]=s[0];
    for(int i=1;i<n;i++)
        l[i]=max(l[i-1],s[i]);
    r[n-1]=s[n-1];
    for(int i=n-2;i>=0;i--)
        r[i]=max(r[i+1],s[i]);
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=min(l[i],r[i])-s[i];
    cout<<ans<<"\n";
}
