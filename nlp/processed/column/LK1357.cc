#include <iostream>

using namespace std;

int a[10000000];

int main()
{
    int n,k,mx;
    long long s = 0;
    cin >> n;
    //int a[13];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int pmx = 0;
    for(int i = 0; i < n; i++)
        if (a[pmx] < a[i]) pmx = i;
//---------------------
    int i=1;
    while (a[i] >= a[i-1]) i++;
    while (i <= pmx)
    {
        k = a[i-1];
        while (i <= pmx && a[i] < k)
        {
            s += k - a[i];
            i++;
        }
        i++;
    }
//------------------
    i = n-2;
    while (a[i] >= a[i+1]) i--;
    while (i >= pmx)
    {
        k = a[i+1];
        while (i >= pmx && a[i] < k)
        {
            s += k - a[i];
            i--;
        }
        i--;
    }
//------------------
    cout << s;
}
