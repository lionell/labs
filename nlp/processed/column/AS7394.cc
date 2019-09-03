#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    vector <int> Col;
    int n; long long Sum = 0; bool p = 1,f = 1;

    scanf("%d", &n); Col.resize(n);
    for (int i = 0; i<n; i++) scanf("%d", &Col[i]);

    int max_col = Col[0];
    for (int i = 0; i<n; i++) if (max_col < Col[i]) max_col = Col[i];

    for (int i = 1; i+1<n; i++){
        for (int j = Col[i]+1; j<=max_col; j++){
            p = 1; f = 1;
            for (int k = i; k>=0; k--) if (Col[k] >= j) p = 0;
            for (int k = i; k<n; k++)  if (Col[k] >= j) f = 0;
            if ((p == 0) && (f == 0)) Sum++;
        }
    }

    printf("%lld", Sum);

    return 0;
}
