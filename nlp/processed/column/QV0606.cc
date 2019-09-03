#include <bits/stdc++.h>

using namespace std;
#define DIM 10000007
long long int a[DIM],b[DIM],c[DIM];
long long int n;
long long r;

int main(){
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    for (int i = 1; i <= n; i++){
        b[i]=max(b[i-1],a[i]);
        c[n-i+1]=max(a[n-i+1],c[n-i+2]);
    }
    for (int i = 1; i <= n; i++)
        r+=min(b[i],c[i])-a[i];
    printf("%lld",r);
}
