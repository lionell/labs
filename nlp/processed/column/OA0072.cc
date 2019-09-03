#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define endl "\n"
template <typename T> inline T sqr(T t){return t*t;}

int n;
short a[10000005], r[10000005];
ll ans;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--){
        r[i] = max(r[i+1], a[i]);
    }
    short cur;
    for (int i = 1; i <= n; i++){
        ans += (min(r[i], max(a[i], a[i-1])) - a[i]);
        a[i] = max(a[i-1], a[i]);
    }
    cout << ans;

}
