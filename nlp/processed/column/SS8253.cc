#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    static int s[10000000], max_prefix[10000000], max_suffix[10000000];

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int cmax;

    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] > cmax) {
            cmax = s[i];
        }

        max_prefix[i] = cmax;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 || s[i] > cmax) {
            cmax = s[i];
        }
        max_suffix[i] = cmax;
    }

    long long res = 0;

    for (int i = 0; i < n; ++i) {
        res += min(max_prefix[i], max_suffix[i]) - s[i];
    }

    cout << res << endl;
}