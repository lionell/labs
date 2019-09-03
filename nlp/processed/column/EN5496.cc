#include <queue>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <deque>
#include <sstream>
#include <map>
#include <iomanip>
#include <cstdlib>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ld long double
#define M_PI 3.14159265358979323846
#define puss vector
const ld EPS = 0.00001;
const ll INF = 1000000007;


using namespace std;
// scanf("%I64d", &x);
const ll MAXN = 10000003;
int a[10000003];
int main(){
    //int n=10000000;srand (244536);
    int n; scanf("%d", &n);
    ll mxp=0;
    bool tru=false;
    for (int i=0;i<n;i++){
        //a[i]=random()%10000+1;
        scanf("%d", &a[i]);
        if (a[i]>mxp){
            mxp=a[i];
            tru=false;
        }
        else
            if (a[i]==mxp)
                tru=true;
        //cout<<a[i]<<' ';
    }
    ll ans=0;
    ll pot=0;
    ll mx=0;
    for (int i=0;i<n;i++){
        if (a[i]>=mx){
            ans+=pot;
            pot=0;
            mx=a[i];
        }
        else{
            pot+=mx-a[i];
        }
    }
    ll mx2=0;
    pot=0;
    for (int i=n-1;i>=0;i--){
        if (a[i]>=mx2){
            if (mx2==mxp&&tru){
                pot=0;
                mx2=a[i];
                break;
            }
            else{
                ans+=pot;
                pot=0;
                mx2=a[i];
            }
        }
        else
            pot+=mx2-a[i];
    }
    cout<<ans<<endl;
}

