#include <bits/stdc++.h>
using namespace std;

bool logg = false;

int main(){
    int n;
    cin>>n; if(n==0){cout<<0;return 0;}
    vector<long> cols(n);
    for(int i=0; i<n; i++)
        cin>>cols[i];

    vector<long> maxLeft(n);
    maxLeft[0] = cols[0];
    for(int i=1; i<n; i++)
        maxLeft[i] = max(maxLeft[i-1], cols[i]);

    vector<long> maxRight(n);
    maxRight[n-1] = cols[n-1];
    for(int i=n-2; i>-1; i--)
        maxRight[i] = max(maxRight[i+1], cols[i]);

    long long result = 0;
    for(int i=1; i<n-1; i++)
        result+= max((long)0, min(maxLeft[i] - cols[i], maxRight[i] - cols[i]));
    cout<<result;

    if(logg){
        cout<<'\n';
        for(int i=0; i<n; i++){
            cout<<cols[i]<<'\t'<<maxLeft[i]<<'\t'<<maxRight[i]<<'\n';
        }
    }
    return 0;
}
