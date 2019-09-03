#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
struct el{
    ll h, i;
};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, a=0, prev = 0, ans = 0, res = 0;
    cin >> n;
    vector<ll> us(n+1,0);
    vector<el> q;
    ll i = -1;
    while(a >= prev && i < n-1) prev = a,cin >> a, i++;
    q.push_back({prev, i-1});
    us[i] = a;
    prev = a;
    while(i < n-1){
        cin >> a, i++;
        us[i] = us[i-1] + a;
        if(a <= prev) q.push_back({a,i});
        else {
            int k;
            for(k = q.size()-1; k > 0; k--){
                if(q[k].h <= a) q.pop_back();
                else break;
            }
            ll res = min(a, ll(q[k].h))*(i - q[k].i - 1) -  (us[i-1] - us[q[k].i]);
            ans += res;
            us[i] += res;
            if(q[k].h <= a)
                q[k] = {a, i};
            else q.push_back({a,i});

        }
        prev = a;
    }
    cout << ans;
    return 0;
}
