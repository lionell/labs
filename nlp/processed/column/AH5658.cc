#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n<=2){
        cout<<0<<endl;
        return 0;
    }
    int m[n];
    int mmax=0;
    unsigned long long ans=0;
    for (int i=0; i<n; i++){
        cin>>m[i];
        if (m[i]>mmax) mmax=m[i];
    }
    for (int i=1; i<=mmax; i++){
        int j=0;
        while (j<n && m[j]<i) j++;
        if (j==n) break;
        int l=0;
        for (; j<n; j++){
            if (m[j]>=i){
                ans+=l;
                l=0;
            } else l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
