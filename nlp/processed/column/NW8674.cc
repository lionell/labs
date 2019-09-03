#include "iostream"

using namespace std;

int main()
{ 
  long i, a, n, imin, imax, used, b[10001][3]={0};
  long long  s=0;

  std::ios::sync_with_stdio(false);
  cin >> n; 

 for (i=0;i<n;i++)
  {
    cin >> a;
    if (b[a][0]==0)
    {
      b[a][0]=1;
      b[a][1]=i;
      b[a][2]=i;
    }
    else
    {
      b[a][0]++;
      b[a][2]=i;
    }
  }
 
  for (i=10000;i>0;i--)
  {
    if (b[i][0]==0) continue;
    if (b[i][0]==1)
    {
      imin = b[i][1];
      imax = imin;      
      s=0;
      break;
    }
    else
    {
      imin = b[i][1];
      imax = b[i][2];      
      s=(imax-imin-1)*(long long)i;
      s=s-(b[i][0]-2)*(long long)i;
      break;
    }
  }
 
  for (i=i-1;i>0;i--)
  {
    if (b[i][0]==0) continue;
    used = 0;
    if (b[i][1]<imin)    
    {      
      s=s+(imin-b[i][1]-1)*(long long)i;  
      used++;      
      imin = b[i][1];
    }
    if (b[i][2]>imax)
    {
      s=s+(b[i][2]-imax-1)*(long long)i;
      used++;
      imax = b[i][2];      
    }
    s=s-(b[i][0]-used)*(long long)i;
  }
  cout << s ;
  
  return 0;
}
