////
//// Created by lionell on 22.02.16.
//// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<pair<int, int>> a;
//
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int s, t;
//        cin >> s >> t;
//        a.emplace_back(t, s);
//    }
//    sort(begin(a), end(a), greater<pair<int, int>>());
//    int max_t = 0;
//    int sum = 0;
//    for (auto x : a) {
//        sum += x.second;
//        max_t = max(max_t, sum + x.first);
//    }
//    cout << max_t;
//    return 0;
//}