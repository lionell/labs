#include <iostream>


using namespace std;

int main()
{
   int n;
   cin>>n;
   if(n<=2){
    cout<<0<<endl;
    return 0;
   }
    int arr[n];
    int i=0;
     for( i=0;i<n;i++)
     {
        cin>>arr[i];
        }
     i=0;
     int start=-1;
     while(true)
      {
       if(i!=n-1 && arr[i+1]<arr[i])
       {
           start=i;
        break;
       }
       if(i==n-1)
        break;
        i++;
      }
      i=n-1;
      int fin=-1;
      while(true)
      {
          if(i!=0 && arr[i-1]<arr[i])
          {
              fin=i;
             break;
          }
          if(i==0)
            break;
          i--;
      }
      int mn=min(arr[start],arr[fin]);
      bool flag=0;
      if(start==-1 || fin==-1)
      {
          cout<<0<<endl;
          return 0;
      }
      for(i=start+1;i<fin;i++)
      {
          if(arr[i]<mn)
            flag=1;
      }
      if(flag==0)
      {
          cout<<0<<endl;
          return 0;
      }
      else
      {
          start++; fin--;
          int sum=0;
          for(int i=start;i<=fin;i++)
          {
              if(arr[i]<=mn)
             sum+=arr[i];
             else
            sum+=mn;
          }
          int mn2=fin-start+1;
          int s=mn2*mn;
          int rez=s-sum;
          cout<<rez<<endl;
      }
    return 0;
}
