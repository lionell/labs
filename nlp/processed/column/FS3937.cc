#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN ((int)1e7 + 23)


inline void computeHigherBefore(int n, const int s[], int higherBefore[])
{
    int highest = s[0];
    
    for (int i = 1; i < n; ++i)
    {
        higherBefore[i] = highest;
        highest = max(highest, s[i]);
    }
}

inline void computeHigherAfter(int n, int s[], int higherAfter[])
{
    reverse(s, s + n);
    
    computeHigherBefore(n, s, higherAfter);
    
    reverse(s, s + n);
    reverse(higherAfter, higherAfter + n);
}

int main()
{
    int n;
    
    while (~scanf("%d", &n))
    {
        static int s[MAXN];

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &s[i]);
        }
        
        static int higherBefore[MAXN];
        static int higherAfter[MAXN];
        
        computeHigherBefore(n, s, higherBefore);
        computeHigherAfter(n, s, higherAfter);
        
        long long answer = 0;
        
        for (int i = 1; i + 1 < n; ++i)
        {
            long long currentWaterHeight = min(higherAfter[i], higherBefore[i]);
            long long waterOnlyHeight = max(0LL, currentWaterHeight - s[i]);
            
            answer += waterOnlyHeight;
        }
        
        printf("%lld\n", answer);
        
        break;
    }
    
    return 0;
}
