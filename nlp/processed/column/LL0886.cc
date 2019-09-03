#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




const int N = 1e7 + 10;



int n;
LL ans;
unsigned short mx,pos,now,a[N];



main()
{

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n; ++i) {
        cin>>a[i];
        if (mx < a[i]) {
            mx = a[i];
            pos = i;
        }
    }

    now = 0;
    for (int i=0; i<pos; ++i) {
        if (a[i] > now)
            now = a[i];
        ans += now - a[i];
    }

    now = 0;
    for (int i=n-1; i>pos; --i) {
        if (a[i] > now)
            now = a[i];
        ans += now - a[i];
    }

    cout<<ans;























}















