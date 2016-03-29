/*
 * Definition's:
 *   A-warrior - warrior from array A
 *   B-warrior - warrior from array B
 *
 * Main idea
 * Sort input arrays. For each A-warrior let's find B-warrior
 * with maximum strength such that A-warrior can beat B-warrior.
 * If there are no B-warrior that can be beaten by this A-warrior
 * then it's optimal to put A-warrior into the battle with the
 * strongest B-warrior. It's easily to proof that optimal solution
 * on each step gives us optimal global solution.
 *
 * NOTE!!! This solution does'nt compile on VS because of bits/stdc++.h library.
 *
 * Example
 *  Input:
 *    10 // size of arrays
 *    1 3 5 7 9 11 13 15 17 19 // own army
 *    2 4 6 8 10 12 14 16 18 20 // enemy army
 *  Output:
 *    99 // 3+5+7+9+11+13+15+17+19=99
 *
 * Complexity
 *  Time: O(nlog(n)), the most consuming is sorting O(nlog(n))
 *  Memory: O(n)
 *
 * @author Ruslan Sakevych
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    // size of arrays
    int n;
    cin >> n;
    // memory allocation and reading
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int *b = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    // sorting input
    sort(a, a + n);
    sort(b, b + n);
    // two pointers: j in array b, and i on array a
    // if there are j such as b[j] < a[i] than we can use a[i]
    // to fight b[j], otherwise we can use a[i] to fight
    // the the strongest B-warrior, and of course he lose.
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[j]) {
            ans += a[i];
            j++;
        }
    }
    cout << ans;
    // cleaning memory
    delete[] b;
    delete[] a;
    return 0;
}