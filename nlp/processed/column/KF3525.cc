#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> c1(n);
    vector<int> c2(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    c1[0] = 0;
    for(int i = 1; i < n; i++) {
        c1[i] = max(c1[i - 1], h[i - 1]);
    }

    c2[c2.size()-1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        c2[i] = max(c2[i + 1], h[i + 1]);
    }

    int s = 0;
    for(int i = 0; i < n; i++) {
        s += min(0, min(c1[i] - h[i], c2[i] - h[i]));
    }
}