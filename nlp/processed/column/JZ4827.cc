#include <iostream>

using namespace std;

long long h[10000001];

long long mod(long long a)
{
    return a < 0 ? a * -1 : a;
}

int main()
{
    long long n, sum = 0;
    cin>>n;
    for(long long i = 0; i < n; ++i)
        cin>>h[i];
    for(long long i = 0; i < n - 2; i = i)
    {
        long long nsum = 0;
        for(long long j = i + 1; true; j++)
        {
            if(h[j] >= h[i])
            {
                //cout<<abs(h[i] - h[j]) * (j - i - 1)<<endl;
                i = j;
                //cout<<"1"<<endl;
                break;
            }
            else if(j == n - 1)
            {
                nsum -= (h[i] - h[j]) * (j - i - 1);
                if(nsum < 0)
                    nsum = 0;
                i = j;
                //cout<<"2"<<endl;
                break;
            }
            else
            {
                nsum += mod(h[i] - h[j]);
                //cout<<sum<<endl;
                //cout<<"3 "<<nsum<<endl;
            }
        }
        sum += nsum;
    }
    cout<<sum<<'\n';
    return 0;
}
