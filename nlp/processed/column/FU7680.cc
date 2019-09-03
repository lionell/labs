#include <iostream>
#include <vector>

using namespace std;

vector<int> cols, lmax;

bool check_pop(int m) {
    int n = lmax.size();
    return n > 1 && cols[lmax[n-2]] > cols[lmax[n-1]] && m > cols[lmax[n-1]];
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cols.resize(n);
    for (int i = 0; i < n; i++)
        cin >> cols[i];
    if (cols[0] > cols[1])
        lmax.push_back(0);
    for (int i = 1; i < n-1; i++)
        if (cols[i] > cols[i+1] && cols[i] >= cols[i-1]) {
            if (check_pop(cols[i]))
                lmax.pop_back();
            lmax.push_back(i);
        }
    if (cols[n-1] >= cols[n-2])
        lmax.push_back(n-1);

    long long ans = 0;
    int lower;
    for (int i = 0; i < (int)lmax.size()-1; i++) {
        lower = min(cols[lmax[i]], cols[lmax[i+1]]);
        for (int j = lmax[i]+1; j < lmax[i+1]; j++)
            ans += max(0, lower-cols[j]);
    }

    cout << ans;

    return 0;
}
