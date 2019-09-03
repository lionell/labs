#include <iostream>

using namespace std;

int n,c,m1[2000007],m2[2000007],m3[2000007];
long long a;
int main(){
    cin >> n;
    for(c=1;c<=n;c++)cin >> m1[c];
    for(c=1;c<=n;c++)
        {
        m2[c]=max(m1[c],m2[c-1]);
        m3[n-c+1]=max(m3[n-c+2],m1[n-c+1]);
        }
    for(c=1;c<=n;c++)a+=min(m2[c],m3[c])-m1[c];
    cout<<a;
}
