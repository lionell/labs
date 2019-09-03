#include <iostream>
#include <cstring>
#include<string>
#include<cstdio>
#include <cmath> 
 
using namespace std;
 
int   A[10000000];
int main()
{
    int n,i,sum=0,j=0,k=0,max1=0,max2=0,s=0,s1=0,maxi=0,s2=0,maxin=0,s3=0;
   
    cin>>n;
    A[n]=0;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    i=1;
   
    while(j<n)
    {
        if(A[j]>A[i])
        {
             max1=A[j];
                maxi=j; 
            while(A[j]>A[i] and i<n)
            {
                   
                sum=sum+A[j]-A[i];
                 if(A[i]>maxin and A[i]>=A[i+1] and A[i]>A[i-1] and maxin!=0 )s=s+(A[i]-maxin)*(i-j-1)-(i-maxi-1)*(A[i]-maxin);
                 if(A[i]>=A[i+1] and A[i]>A[i-1] or A[i]>=A[i-1] and A[i]>A[i+1]){s=s+(s2-(A[j]-A[i])*(i-1-maxi));maxi=i;max1=A[i];s2=-A[j]+A[i];maxin=max1;}
                
              
                s1=s1+A[j]-A[i];
                s2=s2+A[j]-A[i];
                i=i+1;
                
            }
            if(i==n and A[j]>A[n-1] and s>0)sum=sum-s1+s;
            else if(i==n and A[j]>A[n-1] and s==0)sum=sum-s1;
            
            j=i;i=j+1;s=0;s1=0;s2=0;
        }
        else  {j=j+1;i=i+1;s=0;s1=0;s2=0;}             
    }     
    cout<<sum;
}
        
        
	
        
            
           

   
    
       
        
    
    
  



    
    
        
        
    
    
    


