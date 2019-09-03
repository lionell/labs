#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i",&n);
    int s[n];
    for (int i=0; i<n; i++)
        scanf("%i",s+i);
    int l=0, r=n-1;
    while ((s[l+1]>=s[l]) && (l<n-1)) l++;
    while ((s[r-1]>=s[r]) && (r>0)) r--;
    if (l>=r)
    {
        printf("0\n");
        return 0;
    }
    long s0,sum=0;
    int cur,r0,Max;
    while (l<r)
    {
        s0=0;
        cur=s[l];
        l++;
        Max=s[l];
        r0=l;
        while ((s[r0]<=cur) && (r0<r) && (s[r0]!=0))
        {
            r0++;
            if (s[r0]>=s[Max]) Max=r0;
        }
        if (s[r0]==0)
        {
            cur=s[Max];
            r0=Max;
        }
        if (r0==r)
        {
            if (s[r]>=s[Max])
            {
                if (s[r]<cur) cur=s[r];
            }
            else
            {
                cur=s[Max];
                r0=Max;
            }
        }
        while (l<r0)
        {
            if (s[l]==0)
            {
                s0=0;
                break;
            }
            s0+=cur-s[l];
            l++;
        }
        sum+=s0;
        while ((s[l+1]>=s[l]) && (l<r)) l++;
    }
    printf("%li\n",sum);
}
