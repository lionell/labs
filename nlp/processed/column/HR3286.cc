#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define READ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int mmx, n, mas[10000001], mn, mid;
ll ans;
pair <int , int > pr;

int main(){

    READ

  cin>>n;

    for (int i = 0 ; i < n ; ++i){
        cin>>mas[i];
         if ( mas[pr.f] < mas[i] )pr.f = i;
    }

    mmx = pr.f;

    for (int i = 0 ; i < mmx ; ++i){
        mn = max(mas[i],mn);
        mid = min (mn, mas[mmx]);
        ans += mid - mas[i];
    }

   mn = 0;

    for (int i = n - 1 ; i > mmx ; --i){
        mn = max(mas[i],mn);
        mid = min (mn, mas[mmx]);
        ans += mid - mas[i];
    }

    cout<<ans;
}
