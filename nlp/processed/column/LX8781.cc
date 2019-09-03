#include <iostream>

using namespace std;

int main()
{
    int n,m,s,c;
    int  a[1000001];
    pair <int,int> mx[1000001];
    cin >> n ;
    cin >> a[0];
    s=0;
    m=a[0];
    mx[0].first=0;
    for (int i=1;i<n;i++)
    {
        cin >> a[i];
        if (a[i]>m)
            m=a[i];
        mx[i].first=m-a[i];
    }
    m=a[n-1];
    mx[n-1].second=a[n-1];
    for (int i=n-2;i>=0;i--)
    {
        if (a[i]>m)
            m=a[i];
        mx[i].second=m-a[i];
        int b = min(mx[i].second,mx[i].first);
        b = max(0,b);
        s+=b;
    }
    cout << s;
    return 0;
}
