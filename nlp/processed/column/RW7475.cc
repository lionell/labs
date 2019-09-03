#include <bits/stdc++.h>
using namespace std;
int  b, sum,m[10000000], a,d=0,xo,mx=0,x1,x2,h1,h2,k=0,i,j;
long long ans=0;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long f;
    cin>>a;
    for(i=1;i<=a;i++)
    {
        cin>>m[i];
        if(m[i]>=mx){mx=m[i];xo=i;}

    }

for(i=1;i<xo;i++)
{
    if(m[i+1]<m[i] && k==0){x1=i;h1=m[i];k=1;}
 if(m[i+1]>m[i] && m[i+1]>=h1 && k==1)
 {
     k=0;
     x2=i+1;
     h2=m[i+1];

     d=(x2-x1-1)*min(h1,h2);

     for(j=x1+1;j<x2;j++)
     {
         //cout<<d<<" ";
         d-=m[j];
     }
     ans+=d;
 }
}
for(i=a;i>xo;i--)
{
    if(m[i-1]<m[i] && k==0){x1=i;h1=m[i];k=1;}
 if(m[i-1]>m[i] && m[i-1]>=h1 && k==1)
 {
     k=0;
     x2=i-1;
     h2=m[i-1];

     d=(x1-x2-1)*min(h1,h2);
     for(j=x2+1;j<x1;j++)
     {
         //cout<<d<<" ";
         d-=m[j];
     }
     ans+=d;
 }
}
cout<<ans;
}
