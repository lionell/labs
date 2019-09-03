#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    int data[n];

    int fMax = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
        if (data[i] > fMax)
            fMax = data[i];
    }

    int maxs[n][2];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
            maxs[i][j] = 0;

    maxs[0][0] = data[0];
    maxs[0][1] = fMax;

    maxs[n-1][0] = fMax;
    maxs[n-1][1] = data[n-1];

    for (int i = 1; i < n - 1; ++i)
    {
        maxs[i][0] = max(data[i], maxs[i-1][0]);
        maxs[n - i - 1][1] = max(data[n - i - 1], maxs[n-i][1]);
    }

    unsigned long long sum = 0;
    for (int i = 1; i < n - 1; ++i)
        sum += min(maxs[i][0], maxs[i][1]) - data[i];

    cout << sum << "\n";

    return 0;
}
