#include <iostream>

using namespace std;


int main()
{
    int m[3000000];
    int n;
    int k=0;
    int kx=0;
    int ans=0;
    cin>>n;
    cin>>m[1];
    int hx=m[1];
    for (int i=2;i<=n;i++)
    {
        cin>>m[i];
        if (m[i]<m[i-1])
        {
            if (k==0)
            {
            k=1;
            hx=m[i-1];
            kx=i-1;
            ans+=(hx-m[i]);
            }
            else
            {
                ans+=(hx-m[i]);
            }
        }
        if (m[i]>=m[i-1])
        {
            if (k==1)
            {
                if (m[i]<hx)
                {
                ans+=(hx-m[i]);
                }
                else
                {
                    k=0;
                    hx=m[i];
                    kx=i;
                }
            }
            else
            {
                hx=m[i];
                kx=i;
            }
        }
    }
    if (k==1)
    {
        for (int i=kx+1;i<=n;i++)
        {
            ans-=(hx-m[i]);
        }
    }
    hx=m[n];
    if (k==1)
    {
        for (int i=n-1;i>=kx;i--)
        {
        if (m[i]<m[i+1])
        {
            if (k==0)
            {
            k=1;
            hx=m[i+1];
            ans+=(hx-m[i]);
            }
            else
            {
                ans+=(hx-m[i]);
            }
        }
        if (m[i]>=m[i+1])
        {
            if (k==1)
            {
                if (m[i]<hx)
                {
                ans+=(hx-m[i]);
                }
                else
                {
                    k=0;
                    hx=m[i];
                }
            }
            else
            {
                hx=m[i];
            }
        }
    }
    }
    cout<<ans;
}
