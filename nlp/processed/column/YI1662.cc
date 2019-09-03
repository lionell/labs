#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int *A;
inline int nextInt() {

    register char c = getchar();

    while(!isdigit(c)) {
        c = getchar();
    }

    register int ans = c - '0';

    c = getchar();

    while(isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }

    return ans;
}
int l, r, ans = 0;
main() {
    ios_base::sync_with_stdio(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n = nextInt();

    A = new int[n];

    for(register int i = 0; i < n; ++i)
        A[i] = nextInt();


    l = 0;
    r = n - 1;

    while(l < r) {
        while(l < r && A[l] <= A[l + 1])
            ++l;

        while(l < r && A[r] <= A[r - 1])
            --r;

        if(l == r)
            break;

        if(A[l] <= A[r]) {
            register int t = A[l];
            ++l;
            while(A[l] < t) {
                ans += t - A[l++];
            }
        }
        else {
            register int t = A[r];
            --r;
            while(A[r] < t) {
                ans += t - A[r--];
            }
        }
    }
    cout << ans << endl;
}
