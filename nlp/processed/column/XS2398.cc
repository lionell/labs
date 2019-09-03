#include<bits/stdc++.h>
using namespace std;



const int N=1e7+1;



short a[N],suf[N],mx;
int n;
long long ans;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    suf[n]=a[n];
    for(int i=n-1;i>=1;i--){
        suf[i]=max(suf[i+1],a[i]);
    }
    mx=a[1];
    for(int i=2;i<n;i++){
        ans+=max(0,min(suf[i+1],mx)-a[i]);
        mx=max(mx,a[i]);
    }
    cout<<ans;
}

