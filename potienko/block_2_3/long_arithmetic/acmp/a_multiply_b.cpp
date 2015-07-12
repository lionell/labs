//
// Created by lionell on 5/21/15.
//
// Verdict: Accepted(mccme)
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifdef ACMP
#include <fstream>
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif

class BigInteger {
private:
    static constexpr int BASE = 10;
    static constexpr int DIGITS_COUNT = (int)log10(BASE);
    vector<int> data;
    bool positive;
public:
    BigInteger(): data(), positive(true) {}
    friend void scan(BigInteger &x);
    friend void print(const BigInteger &x);
    friend const BigInteger operator-(const BigInteger &x);
    friend const BigInteger operator*(const BigInteger &left, const BigInteger &right);
};

void scan(BigInteger &x) {
    x.data.clear();
    string s = "";
    cin >> s;
    int index = 0;
    if (s[index] == '-') {
        x.positive = false;
        index++;
    }
    while (index + BigInteger::DIGITS_COUNT <= s.length()) {
        x.data.push_back(atoi(s.substr(1UL * index, 1UL * BigInteger::DIGITS_COUNT).c_str()));
        index += BigInteger::DIGITS_COUNT;
    }
    if (index < s.length()) x.data.push_back(atoi(s.substr(1UL * index, 1UL * (s.length() - index + 1)).c_str()));
    reverse(x.data.begin(), x.data.end());
    while (x.data.size() > 1 && x.data.back() == 0) x.data.pop_back();
}

void print(const BigInteger &x) {
    if (x.data.back() != 0 && !x.positive) printf("-");
    cout << (x.data.empty() ? 0 : x.data.back());
    for (int i = (int)x.data.size() - 2; i >= 0; --i)
        cout << setfill('0') << setw(BigInteger::DIGITS_COUNT) << x.data[i];
}

const BigInteger operator-(const BigInteger &x) {
    BigInteger result(x);
    result.positive ^= 1;
    return result;
}

const BigInteger operator*(const BigInteger &left, const BigInteger &right) {
    if (left.positive == right.positive) {
        BigInteger result;
        result.data.resize(left.data.size() + right.data.size(), 0);
        for (int i = 0; i < left.data.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < right.data.size() || carry; ++j) {
                unsigned long long current = result.data[i + j] + carry + 1UL * left.data[i] * (j < right.data.size() ? right.data[j] : 0);
                result.data[i + j] = (int)(current % BigInteger::BASE);
                carry = (int)(current / BigInteger::BASE);
            }
        }
        while (result.data.size() > 1 && result.data.back() == 0) result.data.pop_back();
        return result;
    } else return left.positive ? -(left * -right) : -(-left * right);
}

int main() {
    BigInteger a, b;
    scan(a);
    scan(b);
    print(a * b);
    return 0;
}