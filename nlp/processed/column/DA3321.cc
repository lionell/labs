#include <iostream>

using namespace std;

static int S[10000001];

int main()
{
    int N,k=0,b=0,puddlestart=0,ans=0;
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>S[i];
    while (k<N)
    {
        ans+=b;
        b=0;
        puddlestart=k;
        for (k=k+1;S[puddlestart]>S[k]&&k<N-1;k++)
        {
            b+=S[k];
        }
    }
    cout<<ans<<endl;
}
