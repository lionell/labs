#include <iostream>

using namespace std;

int main()
{
    long long n, l = 0, max, sum = 0;
    cin >> n;
    long long r = n - 1;
    long long h[10000];
    for (int i=0;i<n;i++) cin >> h[i];
    while (l<r)
    {
        while (l<r && h[l]<=h[l+1]) l++;
        while (l<r && h[r]<=h[r-1]) r--;
        if (l==r) break;
        if (h[l]<=h[r])
        {
            max = h[l];
            l++;
            while (h[l]<max)
            {
                sum += max - h[l];
                l++;
            }
        }
        else
        {
            max = h[r];
            r--;
            while (h[r]<max)
            {
                sum += max - h[r];
                r--;
            }
        }
    }
    cout << sum;
    return 0;
}
