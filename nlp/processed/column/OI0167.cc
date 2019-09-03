#include <iostream>


using namespace std;

int main()
{
    int N, c=0, b, d, e,f,l;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];

    }
    b= N/2;
    for (int i=0; i<=b; i+2)
    {
        if(i>i+1)
        {
            d=i+1;
        }else if(i<i+1)
        {
            d=i+2;
        }else
        {
            d=i+2;
        }

    }
    for (int i=0; b<=N; b+2)
    {
        if(b>b+1)
        {
            e=b;
        }else if(i<i+1)
        {
            e=b+1;
        }else
        {
            e=b+1;
        }

    }
    l=d;

    for(int i=0; d<e; d++)
    {
        if(arr[l-1]>arr[e])
        {
            c+=(arr[l-1]-arr[d]);
        }else
        {
            c+=(arr[e]- arr[d]);
        }
    }
    cout<<c<<endl;
}




