/**
* Problem`s solving workspace
* For c++
*
*
* author: Oleksiienko Pavlo
*/

#include<bits/stdc++.h>

#define cdbg cout << "Debug in " << __FUNCTION__ << ": "
#define debug(str) cout << "Debuging in " << __FUNCTION__ << ": " << str <<'\n';
#define q <<'\n'
#define sp << ' '
#define pb push_back
#define ll long long
#define intair pair<int , int>
#define f first
#define s second

#define FILE ""
/*
  defines here
*/

using namespace std;

//GLOBAL Vars and __Consts here...
int n,mx;

unsigned short arr[10000000];
//Functions
inline void streamconf(string arg)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (arg == "") return;
    if (arg == "w") freopen(FILE,"w",stdout);
    if (arg == "r") freopen(FILE,"r",stdin);
    if (arg == "rw") {freopen(FILE,"r",stdin);freopen(FILE,"w",stdout);}

}


int main()
{
    streamconf("");
    cin >> n;

  for (int i = 0;i<n;i++)
  {
      cin >> arr[i];
      if (arr[i] > arr[mx]) mx = i;
  }

  ll r = 0,res = 0;
  for (int i = 0;i<mx;i++)
  {
      if (arr[i] > r) r = arr[i];
      else res+=r-arr[i];
      //cdbg << arr[i] sp<< r q;
  }
 // debug(res);
  r = 0;
  for (int i = n-1; i > mx;i--)
  {
      if (arr[i] > r)r = arr[i];
      else res+=r-arr[i];
  }

cout << res;

}
