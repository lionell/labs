#include <iostream>
#include <cstdio>
#include <algorithm>

#ifdef MEASURE_TIME
#include <chrono>
#endif // MEASURE_TIME

using namespace std;

int main() {
#ifdef FILE_IO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif // FILE_IO
#ifdef MEASURE_TIME
    auto __time = chrono::high_resolution_clock::now();
#endif // MEASURE_TIME
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
        res += max(min(max_prefix[i], max_suffix[i]) - s[i], 0);
    }

    cout << res << endl;

#ifdef MEASURE_TIME
    chrono::duration<double, milli> __diff = chrono::high_resolution_clock::now() - __time;
    cerr << "Time: " << __diff.count() << " msec." << endl;
#endif // MEASURE_TIME
}
