#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int MAX_FIB = 88;

ull fib[MAX_FIB];

void setup_fib() {
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < MAX_FIB; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

ull encode(int n) {
    int p = 0;
    while (fib[p] <= n) {
        p++;
    }
    p--;

    ull res = 1;
    while (p >= 0) {
        res <<= 1;
        if (fib[p] <= n) {
            res |= 1;
            n -= fib[p];
        }
        p--;
    }

    return res;
}

int main() {
    setup_fib();
    cout << encode(5);
    return 0;
}