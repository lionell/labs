#include<bits/stdc++.h>

#define min(a,b) (a<b ? (a) : (b))
#define max(a,b) (a>b ? (a) : (b))
#define abs(a) (a>=0 ? (a) : -(a))
#define PI 3.14159265358979323846264338327950288419716939937510
#define ll long long

using namespace std;

int main()
{
    long long int n, V=0, amaxL=0, amaxR=0, maxL, maxR, minamax;

    cin>>n;

    vector<int> h(n);
    for(int i=0;i<n;i++)
        cin>>h[i];

    for(int i=1;i<n/2;i++)
        if(h[amaxL]<h[i])
            amaxL=i;

    amaxR=n/2;
    for(int i=n/2+1;i<n;i++)
        if(h[amaxR]<h[i])
            amaxR=i;

    minamax=min(h[amaxL], h[amaxR]);

    maxL=h[0];
    for(int i=1;i<amaxL;i++)
    {
        if(h[i]<maxL)
            V+=maxL-h[i];
        else
            maxL=h[i];
    }

    for(int i=amaxL+1;i<amaxR;i++)
        V+=minamax-h[i];

    maxR=h[n-1];
    for(int i=n-2;i>amaxR;i--)
    {
        if(h[i]<maxR)
            V+=maxR-h[i];
        else
            maxR=h[i];
    }

    cout<<V;

    return 0;
}
