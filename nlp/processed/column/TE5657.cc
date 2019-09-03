#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define endl '\n'
#define fi first
#define se second

void file(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("wheel.in", "r", stdin); freopen("wheel.out", "w", stdout);
}

const int N = 100005;
ll n, m, ans, k, l;
int a[10000005];

int main()
{
    file();
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    m = a[0];
    l = 0;
    for (int i = 1; i < n; ++i){
        if (m <= a[i]) {
            ans += k;
            m = a[i];
            a[l] = -1;
            l = i;
            k = 0;
        } else k += m - a[i];
    }
    m = a[n - 1];
    k = 0;
    l = n - 1;
            for (int i = n - 2; i >= 0; --i){
            if (m <= a[i]) {
                ans += k;
                m = a[i];
                k = 0;
            } else k += m - a[i];
            if (a[i] == -1) break;
        }
    cout << ans;
}
/**

14
12

4

*/

