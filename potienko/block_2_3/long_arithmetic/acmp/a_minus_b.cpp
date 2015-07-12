//
// Created by lionell on 5/20/15.
//
// Verdict: WA13(WTF, all is OK)
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
    friend const BigInteger operator-(const BigInteger &x);
    friend bool operator<(const BigInteger &left, const BigInteger &right);
    friend bool operator>(const BigInteger &left, const BigInteger &right);
    friend bool operator<=(const BigInteger &left, const BigInteger &right);
    friend bool operator>=(const BigInteger &left, const BigInteger &right);
    friend bool operator==(const BigInteger &left, const BigInteger &right);
    friend void scan(BigInteger &x);
    friend void print(const BigInteger &x);
    friend const BigInteger operator-(const BigInteger &left, const BigInteger &right);
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

bool operator<(const BigInteger &left, const BigInteger &right) {
    if (left.positive == right.positive) {
        if (left.positive) {
            if (left.data.size() == right.data.size()) {
                int index = (int)left.data.size() - 1;
                while (index >= 0 && left.data[index] == right.data[index]) --index;
                return index >= 0 && left.data[index] < right.data[index];
            } else return left.data.size() < right.data.size();
        } else return -left >= -right;
    } else return right.positive;
}

bool operator>=(const BigInteger &left, const BigInteger &right) {
    return !(left < right);
}

bool operator>(const BigInteger &left, const BigInteger &right) {
    if (left.positive == right.positive) {
        if (left.positive) {
            if (left.data.size() == right.data.size()) {
                int index = (int)left.data.size() - 1;
                while (index >= 0 && left.data[index] == right.data[index]) --index;
                return index >= 0 && left.data[index] > right.data[index];
            } else return left.data.size() > right.data.size();
        } else return -left <= -right;
    } else return left.positive;
}

bool operator<=(const BigInteger &left, const BigInteger &right) {
    return !(left > right);
}

bool operator==(const BigInteger &left, const BigInteger &right) {
    return !(left < right || left > right);
}

const BigInteger operator-(const BigInteger &left, const BigInteger &right) {
    if (left.positive && right.positive) {
        if (left >= right) {
            BigInteger result;
            int carry = 0;
            for (int i = 0; i < left.data.size() || carry; ++i) {
                int current = ((i < left.data.size()) ? left.data[i] : 0) - carry -  ((i < right.data.size()) ? right.data[i] : 0);
                result.data.push_back(current);
                carry = result.data.back() < 0;
                if (carry) result.data.back() += BigInteger::BASE;
            }
            while (result.data.size() > 1 && result.data.back() == 0) result.data.pop_back();
            return result;
        } else return -(right - left);
    }
}

int main() {
    BigInteger a, b;
    scan(a);
    scan(b);
    print(a - b);
    return 0;
}