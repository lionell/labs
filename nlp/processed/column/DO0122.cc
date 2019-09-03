#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull  unsigned long long
#define ld long double
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define y1 ngngwengngigwi
#define x1 wejfiegnepgn
#define files freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define filesin(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define filestxt(x) freopen(x".txt","r",stdin);//freopen(x".txt","w",stdout);
#define iosbase ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define toch(x) fixed<<setprecision(x)
#define all(x) x.begin(),x.end()
#define pii pair < int , int >
#define pll pair < ll , ll >
#define sqr(x) ((x)*(x))

const ll inf=2e9;
const ll md=1e9+7;
const ll  P=27;
const ld ex=0.000000001;
const ld pi=3.14159265358979323846;

short int mx[10000001],a[10000001],mxx;
int n;
ll ans;

int main()
{
    iosbase;
    //files
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)mx[i]=max(mx[i-1],a[i]);
    for(int i=n;i;i--)
    {
        mxx=max(mxx,a[i]);
        //cout<<mx[i]<<' '<<a[i]<<' '<<mxx<<endl;
        ans+=max(0,min(mxx,mx[i])-a[i]);
    }
    cout<<ans;
}
///DO0122
