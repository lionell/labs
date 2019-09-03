/*
PROG : milk2
LANG : C++
*/
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fi first
#define se second
#define sqr(a) ((a) * (a))
#define pi 3.1415926535897932
#define read ifstream in("input.txt")
#define write ofstream out("output.txt")
#define vii vector<int>
#define mii map<int, int>

using namespace std;

int n, m, k;
int a[10000005], pref[10000005], suf[10000005];

int main()
{
    //ifstream in("moocast.in");
    //ofstream out("moocast.out");
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%I64d", &a[i]);
        pref[i] = max(pref[i - 1], a[i]);
    }

    for(int i = n;i >= 1;i--)
        suf[i] = max(suf[i + 1], a[i]);

    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ans = ans + (ll)min(pref[i], suf[i]) - (ll)a[i];
    }

    printf("%I64d\n", ans);

    return 0;
    ///dont forget about initialization array please
}

