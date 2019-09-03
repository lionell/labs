#include <iostream>

using namespace std;

int main()
{
    int n, a, b, sum = 0, k = 1, ans = 0, c = -999999999;
    cin >> n;
    if(n < 3) {
        cout << "0\n";
        return 0;
    }
    cin >> a >> b;
    sum+=b;
    c = 0;
    if(b >= a) {
        a = b;
        k = 0;
        sum = 0;
        c = -999999999;
    }
    for(int i = 2;i < n;i++) {
        cin >> b;
        c = max(k*b-sum, c);
        if(b >= a) {
            ans += k*a-sum;
            k = 0;
            sum = 0;
            a = b;
            c = -999999999;
        }
        sum+=b;
        k++;
        //cout << sum << ' ' << k << '\n';
    }
    if(c > 0)
        ans += c;
    cout << ans << '\n';
    return 0;
}
