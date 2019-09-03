#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, a[10005], max, rez = 0, rezerv = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
      cin >> a[i];
  }
  max = 0;
  for(int i = 1; i < n - 1; i++){
      if(a[i] >= a[max]){
          max = i;
          rez += rezerv;
          rezerv = 0;
      } else {
          rezerv += a[max] - a[i];
      }
  }
  if ( a[max] > a[n-1]){
      rezerv = 0;
      int max2 = n-1;
      for ( int i = 2; i < n - max +1; i++){
      if(a[n - i] >= a[max2]){
          max2 = n - i;
          rez += rezerv;
          rezerv = 0;
      } else {
          rezerv += a[max] - a[i];
      }
  }
  rez += rezerv;
  }
  cout << rez << endl;
  return 0;
}
