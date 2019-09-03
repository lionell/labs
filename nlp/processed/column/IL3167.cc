#include <iostream>

using namespace std;

int main()
{
    int n,k,maxi,h,number,sum,i;
    cin>>n;
    int a[n];
    i=1;cin>>a[i];
    h=a[i];
    number=i;
            for (i=2;i<=n;i++)
            {
            cin>>a[i];
                if(a[i]>=h)
                {
                h=a[i];
                number=i;
                }

            }
            sum=0;
            maxi=a[1];
            for(i=2;i<number;i++)
            {
                if (a[i]>=maxi)
                {
                    maxi=a[i];
                }
                else
                {
                    k=maxi-a[i];
                    sum=sum+k;
                }
            }
             maxi=a[n];
            for(i=n-1;i>number;i--)
            {
                if (a[i]>=maxi)
                {
                    maxi=a[i];
                }
                else
                {
                    k=maxi-a[i];
                    sum=sum+k;
                }
            }

   cout<<sum;


    return 0;
}
