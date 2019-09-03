#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if ( a[i - 1] > a[i] ) {
            int h = 0;
            int j;
            for (j = i + 1; j < n; j++)
                if (a[j] >= a[i - 1]) {
                    h = a[j];
                    break;
                } else {
                    h = max(h, a[j]);
                }
            if (h > a[i - 1]) {
                h = a[i-1];
                for ( int l = i; l < j; l++) {
                    i++;
                    ans += (h - a[l]);
                    a[l] = h;
                }
            } else {
                while (a[i] != h) {
                    ans += (h - a[i]);
                    a[i] = h;
                    i++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
