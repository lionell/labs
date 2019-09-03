#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
short int a[10000005], b[10000005];
ll ans, m, n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >>n;
    for (int i = 1; i <= n; ++i){
        cin >>a[i];
        m = a[i];
        ans -= m;
        b[i] = max(b[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i){
        a[i] = max(a[i], a[i + 1]);
    }
    for (int i = 1; i <= n; ++i){
        m = min(a[i], b[i]);
        ans += m;
    }
    cout <<ans;
}
