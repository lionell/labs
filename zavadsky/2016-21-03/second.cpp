/*
 * Main idea
 * Let's show how we can evaluate solution for n, t, p using previous.
 * If we have dp[i][j] - number of partitions sum of j into i terms,
 * then dp[i][j] = sum dp[i - 1][k], where k = 1..(j - p).
 * Answer will be dp[n][t]. There is several overheads in this solution.
 * Main one if memory overhead. We can store only previous line.
 * Also we can speed up solution using some hack to make zero memory in O(1).
 * But I think it's not necessary in this problem.
 *
 * NOTE!!! This solution does'nt compile on VS because of bits/stdc++.h library.
 *
 * Example
 *  Input:
 *    2 // number of tests
 *    3 34 10 // test no. 2
 *    2 18 8 // test no. 1
 *  Output:
 *    15 // too many...
 *    3 // 10 + 8, 8 + 10, 9 + 9
 *
 * Complexity
 *  Time: O(n*t*k), where k - number of tests.
 *  Memory: O(n*k)
 *
 * @author Ruslan Sakevych
 */
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int t, int p) {
    // memory allocation
    int *f = new int[t + 1]();
    f[0] = 1;
    int *s = new int[t + 1];
    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i < p; ++i) {
            s[i] = 0;
        }
        for (int i = p; i <= t; ++i) {
            s[i] = (i > 0 ? s[i - 1] : 0) + f[i - p];
        }
        swap(f, s);
    }
    int ans = f[t];
    // cleaning memory
    delete[] s;
    delete[] f;
    return ans;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n, p, t;
        cin >> n >> t >> p;
        cout << solve(n, t, p) << endl;
    }
    return 0;
}

