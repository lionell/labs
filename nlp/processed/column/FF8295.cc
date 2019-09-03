#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long s1 = 0;
    long long s2 = 0;
    int t;
    int t1 = 0;
    int n1 = 0;
    long long s3 = 0;
    int i;
    for (i = 0; i < n;i++)
    {
        cin >> t;
        s1 += t;
        if (t >= t1)
        {
            s3 = 0;
            t1 = t;
            n1 = i;
        }
        s2 += t1;
        s3 +=  t-t1;
    }
    s2 += s3;
    int m = s2-s1;
    cout << m;
}
