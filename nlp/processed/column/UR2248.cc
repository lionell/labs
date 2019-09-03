#include<bits/stdc++.h>
using namespace std;

long long s;
int A[10000001];
int l,r,n,m;

int main()
{
    bool haspositive = false;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        m=max(m,A[i]);
    }
    for(int i=1;i<=n;i++)
        if(A[i]==m){l=i;break;}
    for(int i=n;i>=1;i--)
        if(A[i]==m){r=i;break;}
    for (int i=l; i<=r;i++) s+=m-A[i];
    m=0;
    for (int i=1; i<=l;i++)
    {
        m=max(m, A[i]);
        s+=m-A[i];
    }
    m=0;
    for (int i=n; i>=r;i--)
    {
       m=max(m, A[i]);
       s+=m-A[i];
    }
    cout<<s;
}
