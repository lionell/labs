#include <cstdio>
#include <algorithm>

static const int MAX_N=10000000;

int a[MAX_N],b[MAX_N],c[MAX_N];

int main()
{
    int N;
    long long S=0;
    std::scanf("%d",&N);
    for(int i=0;i<N;++i) std::scanf("%d",&(c[i]));
    for(int i=0;i<N;++i) a[i]=std::max(i==0?0:a[i-1],c[i]);
    for(int i=N-1;i>=0;--i) b[i]=std::max(i==N-1?0:b[i+1],c[i]);
    for(int i=0;i<N;++i) S+=std::min(a[i],b[i])-c[i];
    std::printf("%lld",S);
    return 0;
}
