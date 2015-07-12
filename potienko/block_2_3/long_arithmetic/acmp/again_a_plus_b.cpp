/*
 * Verdict: Accepted
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>

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
    friend const BigInteger operator+(const BigInteger &left, const BigInteger &right);
};

void scan(BigInteger &x) {
    x.data.clear();
    string s = "";
    cin >> s;
    int index = (int)s.length();
    while (index - BigInteger::DIGITS_COUNT >= 0) {
        index -= BigInteger::DIGITS_COUNT;
        x.data.push_back(atoi(s.substr(1UL * index, 1UL * BigInteger::DIGITS_COUNT).c_str()));
    }
    if (index > 0)
        x.data.push_back(atoi(s.substr(0UL, 1UL * index).c_str()));
}

void print(const BigInteger &x) {
    if (!x.data.empty() && !x.positive) printf("-");
    cout << (x.data.empty() ? 0 : x.data.back());
    for (int i = (int)x.data.size() - 2; i >= 0; --i)
        cout << setfill('0') << setw(BigInteger::DIGITS_COUNT) << x.data[i];
}

const BigInteger operator+(const BigInteger &left, const BigInteger &right) {
    if (left.positive && right.positive) {
        BigInteger result;
        int carry = 0;
        for (int i = 0; i < max(left.data.size(), right.data.size()) || carry; ++i) {
            int current = carry + ((i < left.data.size()) ? left.data[i] : 0) + ((i < right.data.size()) ? right.data[i] : 0);
            result.data.push_back(current);
            carry = result.data.back() >= BigInteger::BASE;
            if (carry) result.data.back() -= BigInteger::BASE;
        }
        return result;
    }
}

int main() {
    BigInteger a, b;
    scan(a);
    scan(b);
    print(a + b);
    return 0;
}