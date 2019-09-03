#include<bits/stdc++.h>
 using namespace std;
 int n,k,l,m,b,nb1,nb2,i,max1,max2,min1,max4,j,max5,a[10000000+10];
 long long sum;
  int main()
{ ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
    {  cin>>a[i];
       if(i<=n/2+1&&max1<a[i]){max1=a[i]; nb1=i; }
       else if(i>=n/2+1&&max2<a[i]){max2=a[i];nb2=i;}
    }
    min1=min(max1,max2);
    for(i=nb1+1;i<nb2;i++)
    {

        sum+=min1-a[i];

    } max4=a[1];
    for(i=1;i<nb1;i++)
    {
       if(max4>a[i+1]){sum+=(max4-a[i+1]);}
       else if(max4<a[i+1])max4=a[i+1];
    }
    max4=a[n];
    for(i=n;i>nb2;i--)
    {
       if(max4>a[i-1]){sum+=(max4-a[i-1]);}
       else if(max4<a[i-1])max4=a[i-1];
    }
    cout<<sum;


}
