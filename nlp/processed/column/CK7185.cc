#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 10000000;
int s[N], bl[N],br[N];

int main(){
    ios::sync_with_stdio(false);
    long long int n, ans=0;
    cin>>n;
    //vector<int> bl, br, s;
    //s.resize(n), bl.resize(n, 0), br.resize(n, 0);
    memset(bl, 0, sizeof(bl[0] * n));
    memset(br, 0, sizeof(bl[0] * n));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        if(i!=0)bl[i]=bl[i-1];
        if(s[i]>=bl[i]) bl[i]=s[i];

        if(i!=0)br[n-i-1]=br[n-i];
        if(s[n-i-1]>=br[n-i-1]) br[n-i-1]=s[n-i-1];
    }
    for(int i=0;i<n;i++){
        ans+=min(bl[i], br[i])-s[i];
    }
    cout<<ans;
}
