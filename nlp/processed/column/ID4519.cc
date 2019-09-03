#include<iostream>
#include<algorithm>
using namespace std;
unsigned long int m,ma,res,i,n,s=0,j=0,l1,l2;
int main(){
    cin>>n;
unsigned long int *a=new unsigned long int[n];
    for(i=0;i<n;i++)              
      cin>> a[i];
             i=0;
      while(a[i]<=a[i+1] && i<n-1)i++;
      l1=i;
      i=n-1;
       while(a[i]<=a[i-1] && i>0)i--;
       l2=i;
       i=l1+1;
        ma=*(max_element(a+i,a+l2+1));
              m=min(a[l1],ma);
                   for(i=l1+1; i<=l2; i++){              
                     if(a[i]<m )
                     {s+=a[i];j++;}
                     else { 
                         res=res+(min(m,a[i])*j-s); ma=*(max_element(a+i+1,a+l2+1));
                        m=min(a[i],ma); 
                          j=0;s=0;}
           }
                   cout<<res<<endl;
       
                          return 0;
           }
           
