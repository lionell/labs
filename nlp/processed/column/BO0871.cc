#include <iostream>

using namespace std;

int main()
{
    int n;
    short a[1000000];
    cin >> n;
    int i;
    for (i=1; i<=n; i++)
        cin >> a[i];
    i=1;
    int j,s,c,j1;
    s = 0;
    while (i<n)
    {
        c = 0;
        j = i+1;
        while (a[j]<a[i] && j<=n)
        {
            c = c + a[i]-a[j];
            j++;
        }
        if (j<=n)
        s = s + c;
        else
        {
            j1 = n-1;
            c = 0;
            while (a[j1]<a[n] && j1>i)
            {
                c = c + a[n]-a[j1];
                j1--;
            }
            s = s + c;
        }
        i = j;
    }
    cout << s;
}
