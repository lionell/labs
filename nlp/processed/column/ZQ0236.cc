#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 0 ; i < n; i++)
    {
        cin >> v[i];
    }
    int maxh=v[0],posm=0;
    int otv=0;
    for(int i = 0; i < n;i++)
    {
        if(v[i]>maxh)
        {
           maxh=v[i];
            posm=i;
        }
    }
        int a[n][maxh];
      for(int ii = maxh ; ii >0 ;ii--)
      {
          for(int i = 0; i<n;i++)
          {
            if(v[i]-ii>=0){a[i][maxh-ii]=1;}
            else{a[i][maxh-ii]=0;}
          }
      }
      int l =-1;
          for(int i = 0;i<maxh;i++)
          {
              for(int ii=0;ii<n;ii++)
              {
                  if(a[ii][i]==1 && l==-1){l=ii;}
                  else
                  if(a[ii][i]==1){otv+=ii-l-1;l=ii;}
                 // cout << a[ii][i] << " " ;
              }
             // cout << "\n";
             l=-1;
          }
          cout << otv;
       return 0;
}
