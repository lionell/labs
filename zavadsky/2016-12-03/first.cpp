//
// Created by lionell on 3/12/16.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

int ans[MAX_N];

int costs[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main() {
    double x;
    cin >> x;
    int s = (int) (x * 100);
    ans[0] = 1;
    for (int j = 0; j < 11; ++j) {
        for (int i = 0; i <= s; ++i) {
            ans[i] += (i >= costs[j] ? ans[i - costs[j]] : 0);
        }
    }
    cout << ans[s];
    return 0;
}