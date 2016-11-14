//
// Created by lionell on 3/12/16.
//

#include <bits/stdc++.h>

using namespace std;

#define cin in
ifstream in("/home/lionell/dev/labs/zavadsky/2016-12-03/in.txt");

const int MAX_N = 1001;
int f[MAX_N], s[MAX_N];

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= s1.length(); ++i) {
            for (int j = 1; j <= s2.length(); ++j) {
                s[j] = s1[i - 1] == s2[j - 1] ? f[j - 1] + 1 : max(f[j], s[j - 1]);
            }
            swap(f, s);
        }
        cout << f[s2.length()] << endl;
    }
    return 0;
}