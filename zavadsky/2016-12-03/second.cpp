//
// Created by lionell on 3/12/16.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 100000;

pii a[MAX_N];
int f[MAX_N], s[MAX_N];

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int j = 0; j < n; ++j) {
        for (int c = 0; c <= w; ++c) {
            s[c] = f[c];
            if (c >= a[j].first) {
                s[c] = max(s[c], f[c - a[j].first] + a[j].second);
            }
        }
        swap(f, s);
    }
    cout << f[w];
    return 0;
}