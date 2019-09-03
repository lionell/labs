#include <iostream>
#include <vector>

using namespace std;

vector <int> h;
vector <int> left_side;
vector <int> right_side;

int main()
{
    int n;
    long long total = 0;
    cin >> n;
    h.resize(n + 1);
    left_side.resize(n + 1);
    right_side.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    int m = h[1];
    left_side[1] = m;
    for (int i = 2;i <= n; ++i){
        m = max(m, h[i]);
        left_side[i] = m;
    }
    m = h[n];
    right_side[n] = h[n];
    for (int i = n - 1; i ; --i ){
        m = max(m, h[i]);
        right_side[i] = m;
    }
    for (int i = 1; i <= n; ++i)
        total += min(left_side[i] - h[i], right_side[i] - h[i]);
    cout << total;
    return 0;
}
