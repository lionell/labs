#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector < ll > a;
pair <ll, ll> m[10000001], v[10000001];

int main()
{
  ll n, x, j=0;
  cin >> n;
  cin >> x;
  a.push_back(x);
  m[0].first = x;
  m[0].second = 0;
  for(ll i = 1;i<n;i++)
  {
    cin >> x;
    a.push_back(x);
    if(x>=m[j].first) { j++; m[j].first = x; m[j].second = i; }
  }
  ll sum = 0;
  for(ll i = 0;i<j;i++)
  {
    for(ll k = m[i].second+1;k<m[i+1].second;k++)
    {
      sum += m[i].first-a[k];
    }
  }
  v[0].first = a[n-1];
  v[0].second = n-1;
  ll s = 0;
  for(ll i = n-2;i>=m[j].second;i--)
  {
    if(a[i]>=v[s].first) { s++; v[s].first = a[i]; v[s].second = i; }
  }
  for(ll i = 0;i<s;i++)
  {
    for(ll k = v[i].second-1;k>v[i+1].second;k--)
    {
      sum += v[i].first-a[k];
    }
  }
  cout << sum << '\n';
}
