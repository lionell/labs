#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
int n, i, k=0, t, y, x, j,  y1;
long long ss=0, s=0;
cin>>n;
int  a[n+1];
for(i=1;i<=n;i++)
    cin>>a[i];
x=1;
for(i=2;i<=n;i++)
{
    if(a[i]>a[x]) x=i;
}
y=1;
y1=x;
for(i=1;i<=x;i++)
{
   // cout<<a[x]<<" "<<a[i]<<endl;
    if(a[i]>=a[y])
    {
        for(j=y+1;j<=i-1;j++)
        {
            s+=min(a[y],a[i])-a[j];
        }
        //cout<<a[x]<<" "<<a[i]<<endl;
        y=i;
        y1=i;
        ss+=s;
        s=0;
    }

    //cout<<s;
}
//cout<<ss;
y=n;
//cout<<x;
for(i=n;i>=x;i--)
{
    //cout<<i<<" ";
    //cout<<i<<" "<<y1<<endl;
    if(a[i]>=a[y])
    {
        for(j=y-1;j>=i+1;j--)
        {
            s+=min(a[y],a[i])-a[j];
        }
        y=i;
        ss+=s;
        s=0;
    }
}
cout<<ss;
}
//24
//2 3 2 4 3 6 3 2 1 3 5 7 5 4 6 5 4 7 3 2 5 4 3 2 5

