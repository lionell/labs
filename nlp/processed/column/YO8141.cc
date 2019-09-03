#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector <long long> a (n);
    for (long long i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    long long i = 0, j = n - 1, maxI = 0, maxJ = 0, rez = 0;
    while (i < j)
    {
        if (a[i] > maxI)
        {
            maxI = a[i];
        }
        else
        {
            rez += maxI - a[i];
        }
        if (a[j] > maxJ)
        {
            maxJ = a[j];
        }
        else
        {
            rez += maxJ - a[j];
        }
        if (maxJ > maxI)
        {
            i ++;
        }
        else
        {
            j --;
        }
    }
    cout << rez;
    return 0;
}
