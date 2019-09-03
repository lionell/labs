#include <bits/stdc++.h>
#define DIM 10000007
#define INF 1000007
using namespace std;
long long n,a[DIM],l[DIM],r[DIM],res,mx;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);


    for(int i=1;i<=n;++i)
    {
        l[i]=mx;
        mx=max(mx,a[i]);
    }
    mx=0;

    for(int i=n;i>=1;--i)
    {
        r[i]=mx;
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;++i)
        if(min(l[i],r[i])>a[i]) res+=min(l[i],r[i])-a[i];

    printf("%lld",res);


    return 0;
}
