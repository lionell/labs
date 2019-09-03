#include <iostream>
using namespace std;
int main()
{
    int n=0;
int sum=0;
sum=0;
    cin>>n;
    int maxv=0;
    int a[n];
    int iver=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ver=a[1];
    for(int i=0;i<n;i++)
    {
        if (a[i]>ver) {ver=a[i]; iver=i;}
    }
    for(int i=0;i<iver;i++)
    {
    if (maxv<a[i]) maxv=a[i];
    else sum+=maxv-a[i];
    }
    maxv=0;
    for(int i=n-1;i>iver;i--)
    {
    if (maxv<a[i]) maxv=a[i];
    else sum+=maxv-a[i];
    }
    cout<<sum;


}
