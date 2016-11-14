//
// Created by lionell on 22.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    while (s.size() != 1) {
        int x = *s.begin(); s.erase(begin(s));
        int y = *s.begin(); s.erase(begin(s));
        s.insert(x + y);
        ans += 2 * (x + y);
    }
    cout << ans;
}