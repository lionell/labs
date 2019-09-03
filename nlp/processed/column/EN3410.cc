/// íèíäçÿ-êàðàòèñò (ñ) Nasik
#include <bits/stdc++.h>
using namespace std;
const int N=1e7+1;
long long ans;
short x, a[N], mx[N];
int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    for (int i=n; i; i--){
        x=max(x,a[i]);
        mx[i]=min(mx[i],x);
        ans+=(long long)mx[i]-(long long)a[i];
    }

    cout<<ans;
}
