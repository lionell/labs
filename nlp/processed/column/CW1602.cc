#include <bits/stdc++.h>
//#include <iostream.h>
//#include <vector>

typedef long long ll;

struct xyz
{
    ll l;
    ll mx;
    ll s;
};

using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector <ll> a(n);
    cin>>a[0];
    vector <xyz> b;
    xyz temp;
    temp.l=0;
    temp.mx=a[0];
    temp.s=0;
    b.push_back(temp);


    for (int i=1; i<n; i++)
    {
        cin>>a[i];
        if (a[i]<b[b.size()-1].mx)
        {
            b[b.size()-1].s+=b[b.size()-1].mx-a[i];
        }
        else
        {
            xyz Temp;
            Temp.l=i;
            Temp.mx=a[i];
            Temp.s=0;
            b.push_back(Temp);
        }

    }

    b.pop_back();

    vector <xyz> c;

    temp.l=n-1;
    temp.mx=a[n-1];
    temp.s=0;
    c.push_back(temp);


    for (int i=n-2; i>=0; i--)
    {
        if (a[i]<c[c.size()-1].mx)
        {
            c[c.size()-1].s+=c[c.size()-1].mx-a[i];
        }
        else
        {
            xyz Temp;
            Temp.l=i;
            Temp.mx=a[i];
            Temp.s=0;
            c.push_back(Temp);
        }

    }
    c.pop_back();

    ll ans=0;

    if (c.size()>0) ans+=c[0].s;
    //cout<<endl;
    for (int i=0; i<b.size(); i++)
    {
        //cout<<b[i].s<<' '<<b[i].l<<endl;
        if (b[i].s>ans) ans+=b[i].s;
    }

    cout<<ans;

}
