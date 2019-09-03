#include <iostream>
#include <algorithm>

using namespace std;

int c[10000000];
int ml[10000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    
    int mlc = 0;
    for (int i = 0; i < n; ++i) {
        mlc = max(mlc, c[i]);
        ml[i] = mlc;
    }
    
    mlc = 0;
    long long res = 0;
    for (int i = n - 1; i >= 0; --i) {
        mlc = max(mlc, c[i]);
        int mc = min(mlc, ml[i]);
        if (mc > c[i])
            res += mc - c[i];
    }
    
    cout << res << '\n';
    return 0;
}

