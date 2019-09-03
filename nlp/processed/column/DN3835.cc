#include <iostream>

using namespace std;

int l(int n);

int a[10000001], n, maxx, i, j;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << l(n - 1) <<  endl;
    return 0;
}

int l(int n)
{
    if (n == 0)
    {
        return 0;
    }
    for (; a[n - 1] >= a[n] && a[n + 1] > a[n]; n--);
    maxx = a[n - 1];
    j = n - 1;
    for (i = n - 1; i > -1; i--)
    {
        if (a[i] > maxx)
        {
            maxx = a[i];
            j = i;
        }
        if (maxx >= a[n])
        {
            break;
        }
    }
    int k = 0;
    if (a[n] >= a[j])
    {
        for (i = n - 1; i > j; i--)
        {
            k += (a[j] - a[i]);
        }
    }
    else
    {
        for (i = n - 1; i > j; i--)
        {
            k += (a[n] - a[i]);
        }
    }
    return k + l(j);
}
