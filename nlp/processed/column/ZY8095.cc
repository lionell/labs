#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int h[n], l[n], best = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (i == 1 && h[0] > h[1])
            best = h[0];
        if (i > 1)
            if (h[i-1] >= h[i-2] && h[i-1] >= h[i])
                best = max(best, h[i-1]);
        l[i] = best;
    }
    if (h[0] > h[1])
        l[1] = h[0];
    else
        l[1] = 0;
    long long ans = 0;
    best = h[n-1];
    if (h[n-1] > h[n-2]) {
        if (l[n-2] > h[n-2])
            ans = min(l[n-2], h[n-1]) - h[n-2];
        else
            ans = 0;
        best = h[n-1];
    }
    for (int i = n-3; i > 0; i--) {
        if (h[i+2] <= h[i+1] && h[i+1] >= h[i])
            best = max(best, h[i+1]);
        if (best > 0 && l[i] > 0)
            ans += max(0, min(l[i], best)-h[i]);
    }
    cout << ans << endl;
}

//19 2 3 2 4 1 1 2 3 1 1 2 3 4 3 1 0 1 2 2
