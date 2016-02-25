//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    vector<pair<int, int>> a;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int x, y;
//        cin >> x >> y;
//        a.emplace_back(y, x);
//    }
//    sort(begin(a), end(a));
//    int r = 0;
//    int ans = 0;
//    for (auto x : a) {
//        if (x.second >= r) {
//            ans++;
//            r = x.first;
//        }
//    }
//    cout << ans;
//}