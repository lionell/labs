#include<iostream>
using namespace std;
int ab(int a,int b)
{
    if(a <= b)return a;
    else return b;
}
int main()
{
    int n;
    cin >> n;
    int *s = new int(n+1);
    int *leftb = new int(n+1);
    int *rightb = new int (n+1);
    int l=0,r=0;
    for(int i = 1; i <= n;i++)
        {
            cin >> s[i];
            if(s[i] > l)
            {
                leftb[i] = s[i];
                l = s[i];
            }
            else leftb[i] = l;
        }

    for(int i = n; i >= 1;i--)
    {
        if(s[i] > r)
        {
            rightb[i]=s[i];
            r = s[i];
        }
        else rightb[i] = r;
    }
    long long res=0;

    for(int i = 1; i <= n;i++) res+= ab(leftb[i],rightb[i]) - s[i];
    cout << res << endl;
    return 0;
}
