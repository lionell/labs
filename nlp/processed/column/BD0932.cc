#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef map < int, int > mii;
typedef map < int , bool > mib;

const int mod = 1e9;
const int inf = 1e18;
const ld pi = acos(-1);
const ld eps = 0.000001;
const int N = 2*1e5 +1;
const int M = 1e7 +1;

#define iosbase ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define float_write(a) cout.precision(a); cout<<fixed;
#define files_in(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define files_dat(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define files_txt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout);
#define filestxt freopen("output.txt", "w", stdout); freopen("input.txt", "r", stdin);
#define slater(x) (x>='a'&&x<='z')
#define blater(x) (x>='A'&&x<='Z')
#define number(x) (x>='0'&&x<='9')
#define ms(x, y) memset(x, y, sizeof(x));
#define all(a) a.begin(),a.end()
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define y1 ihatethis
#define sz size()
#define s second
#define f first

int n;
long long ans;
short a[M], suf, pref[M];

main()
{
    iosbase;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = max(pref[i-1], a[i]);
    }

    for(int i = n; i ;i--)
    {
        suf = max(a[i], suf);
        if(a[i] < min(suf, pref[i]))
        {
            ans += min(suf, pref[i]) - a[i];
        }
    }

    cout << ans;
}

