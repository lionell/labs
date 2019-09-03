#include <bits/stdc++.h>

using namespace std;
long long i,j,k,n,m,s;
long long r[10000009],l[10000009],a[10000009];
int main()
{
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    r[1]=0;
    for(i=2;i<=n;i++){
        r[i]=max(a[i-1],r[i-1]);
    }
    l[n]=0;
    for(i=n-1;i>=1;i--){
        l[i]=max(a[i+1],l[i+1]);
    }
    i=1;

    while(i<=n){
        if(min(r[i],l[i])>a[i]){
            s+=min(r[i],l[i])-a[i];
        }
        i++;
    }
cout<<s<<endl;
    return 0;
}
