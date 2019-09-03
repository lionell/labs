#include <iostream>

using namespace std;

int main()
{
   long long n, a, l,r,max,sum=0;
   cin>>n;
   long long h[10000];
   for(int i=0;i<n;i++){
        cin>>a;
        h[i]=a;
   }
   l=0, r=n-1;
   while(l<r){
    while(l<r && h[l]<= h[l+1])
        l++;
     while(l<r && h[r]<= h[r-1])
        r--;

    if(l==r)
        break;

    if(h[l]<=h[r]){
        max=h[l];
        l++;
        while(h[l]<max){
            sum=sum+max-h[l];
            l++;
        }

    }
    else{
        max=h[r];
        r--;
        while(h[r]<max){
            sum=sum+max-h[r];
            r--;

        }}

        }
        cout<<sum;

    }


