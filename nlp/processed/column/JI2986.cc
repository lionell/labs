#include <bits/stdc++.h>

using namespace std;
    long col[10000010],maxr[10000010],maxl[10000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long amo,maxi=0;
    long long rez=0;
    cin>>amo;
    for (long i = 0;i<amo;i++)
        {
        cin>>col[i];
        maxl[i]=maxi;
        if (col[i]>maxi) maxi = col[i];
        }
        maxi=0;
    for (long i = amo-1;i>=0;i--)
        {
        maxr[i]=maxi;
        if (col[i]>maxi) maxi = col[i];
        if (min(maxr[i],maxl[i])-col[i]>0) rez=rez+min(maxr[i],maxl[i])-col[i];
        }
    cout<<rez;
    return 0;
}
