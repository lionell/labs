#include <iostream>
#include <stdio.h>
using namespace std;
int n,i,j,can,ij;
long long k;
int a[10000002];
int maxr[10000001];
int maxl[10000001];
int main()
{
    k=0;


    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);

    }

    for(i=0;i<=n+1;i++){
        {
            for(j=i+1;j<=n;j++){
                if(a[i]>maxl[j]){
                    maxl[j]=a[i];
                }
                else{break;}

            }
            for(j=i;j>=1;j--){
                if(a[i]>maxr[j]){
                    maxr[j]=a[i];
                }
                else{break;}

            }

    }
    }
    for(i=1;i<=n;i++){
        if((min(maxl[i],maxr[i]))>a[i]){
            k=k+min(maxr[i],maxl[i])-a[i];
        }
    }
    printf("%lld\n",k);
}
