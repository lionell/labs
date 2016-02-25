//
// Created by lionell on 5/14/15.
//

#include "BigInteger.h"
#include "exceptions.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

BigInteger::BigInteger(const BigInteger &example): BigInteger() {
    this->data = example.data;
    this->positive = example.positive;
}

BigInteger::BigInteger(long long x): BigInteger() {
    this->positive = x >= 0;
    x = abs(x);
    while (x > 0) {
        this->data.emplace_back(x % BigInteger::BASE);
        x /= BigInteger::BASE;
    }
    if (this->data.empty())
        this->data.emplace_back(0);
    while (this->data.size() > 1 && this->data.back() == 0)
        this->data.pop_back();
}

BigInteger::BigInteger(const std::string s): BigInteger() {
    int index = 0;
    if (s[0] == '-') {
        this->positive = false;
        index = 1;
    }
    while (index + BigInteger::DIGITS_COUNT <= s.length()) {
        this->data.emplace_back(atoi(s.substr(1UL * index, 1UL * BigInteger::DIGITS_COUNT).c_str()));
        index += BigInteger::DIGITS_COUNT;
    }
    if (index < s.length())
        this->data.push_back(atoi(s.substr(1UL * index, 1UL * (s.length() - index + 1)).c_str()));
    reverse(this->data.begin(), this->data.end());
    while (this->data.size() > 1 && this->data.back() == 0)
        this->data.pop_back();
}

BigInteger &BigInteger::operator=(const BigInteger &example) {
    this->data = example.data;
    this->positive = example.positive;
}

void print(const BigInteger x) {
    if (x.data.back() != 0 && !x.positive) printf("-");
    cout << (x.data.empty() ? 0 : x.data.back());
    for (int i = (int)x.data.size() - 2; i >= 0; --i)
        cout << setfill('0') << setw(BigInteger::DIGITS_COUNT) << x.data[i];
}

void scan(BigInteger &x) {
    x.data.clear();
    string s = "";
    cin >> s;
    x = BigInteger(s);
}

const BigInteger operator-(const BigInteger& x) {
    BigInteger result = x;
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

bool operator>(const BigInteger &left, const BigInteger &right) {
    if (left.positive == right.positive) {
        if (left.positive) {
            if (left.data.size() == right.data.size()) {
                int index = (int)left.data.size() - 1;
                while (index >= 0 && left.data[index] == right.data[index]) --index;
                return (index >= 0 && left.data[index] > right.data[index]);
            } else return left.data.size() > right.data.size();
        } else return -left <= -right;
    } else return left.positive;
}

bool operator==(const BigInteger &left, const BigInteger &right) {
    return !(left < right || left > right);
}

bool operator!=(const BigInteger &left, const BigInteger &right) {
    return !(left == right);
}

bool operator<=(const BigInteger &left, const BigInteger &right) {
    return !(left > right);
}

bool operator>=(const BigInteger &left, const BigInteger &right) {
    return !(left < right);
}

const BigInteger operator+(const BigInteger &left, const BigInteger &right) {
    if (left.positive == right.positive) {
        BigInteger result;
        result.positive = left.positive;
        int carry = 0;
        for (int i = 0; i < max(left.data.size(), right.data.size()) || carry; ++i) {
            int current = carry + ((i < left.data.size()) ? left.data[i] : 0) + ((i < right.data.size()) ? right.data[i] : 0);
            result.data.emplace_back(current);
            carry = result.data.back() >= BigInteger::BASE;
            if (carry) result.data.back() -= BigInteger::BASE;
        }
        return result;
    } else if (left.positive) return left - (-right);
    else return right - (-left);
}

const BigInteger operator-(const BigInteger &left, const BigInteger &right) {
    if (left.positive && right.positive) {
        if (left >= right) {
            BigInteger result;
            result.positive = left.positive;
            int carry = 0;
            for (int i = 0; i < left.data.size() || carry; ++i) {
                int current = (i < left.data.size() ? left.data[i] : 0) - (i < right.data.size() ? right.data[i] : 0) - carry;
                result.data.emplace_back(current);
                carry = result.data.back() < 0;
                if (carry) result.data.back() += BigInteger::BASE;
            }
            while (result.data.size() > 1 && result.data.back() == 0)
                result.data.pop_back();
            return result;
        } else return -(right - left);
    } else if (left.positive && !right.positive) return left + (-right);
    else if (!left.positive && right.positive) return -((-left) + right);
    else if (!left.positive && !right.positive) return (-right) - (-left);
}

const BigInteger operator*(const BigInteger &left, const BigInteger &right) {
    BigInteger result;
    result.data.resize(left.data.size() + right.data.size(), 0);
    result.positive = left.positive == right.positive;
    for (int i = 0; i < left.data.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < right.data.size() || carry; ++j) {
            unsigned long long cell = carry + result.data[i + j] + 1ULL * left.data[i] * (j < right.data.size() ? right.data[j] : 0);
            result.data[i + j] = (int)(cell % BigInteger::BASE);
            carry = (int)(cell / BigInteger::BASE);
        }
    }
    while (result.data.size() > 1 && result.data.back() == 0)
        result.data.pop_back();
    return result;
}

const BigInteger operator/(const BigInteger &left, const BigInteger &right) {
    if (right == 0) throw MathError("Division by zero");
    BigInteger result;
    result.positive = left.positive == right.positive;
    BigInteger current = 0;
    for (int i = (int)left.data.size() - 1; i >= 0; --i) {
        current *= BigInteger::BASE;
        current.data[0] = left.data[i];
        int l = 0, r = BigInteger::BASE;
        while (r - l > 1) {
            int middle = (l + r) / 2;
            if (right * middle <= current)
                l = middle;
            else r = middle;
        }
        result.data.emplace_back(l);
        current -= right * l;
    }
    reverse(result.data.begin(), result.data.end());
    while (result.data.size() > 1 && result.data.back() == 0)
        result.data.pop_back();
    return result;
}

const BigInteger operator%(const BigInteger &left, const BigInteger &right) {
    return left - right * (left / right);
}

const BigInteger operator^(const BigInteger &left, const BigInteger &right) {
    if (right < 0) throw MathError("Positive exponent expected");
    BigInteger result = 1;
    BigInteger base = left;
    BigInteger exponent = right;
    while (exponent != 0) {
        if (exponent % 2 == 1)
            result *= base;
        base *= base;
        exponent /= 2;
    }
    return result;
}

BigInteger &operator+=(BigInteger &left, const BigInteger &right) {
    left = left + right;
    return left;
}

BigInteger &operator-=(BigInteger &left, const BigInteger &right) {
    left = left - right;
    return left;
}

BigInteger &operator*=(BigInteger &left, const BigInteger &right) {
    left = left * right;
    return left;
}

BigInteger &operator/=(BigInteger &left, const BigInteger &right) {
    left = left / right;
    return left;
}

BigInteger &operator%=(BigInteger &left, const BigInteger &right) {
    left = left % right;
    return left;
}

BigInteger &operator^=(BigInteger &left, const BigInteger &right) {
    left = left ^ right;
    return left;
}

const BigInteger abs(const BigInteger &a) {
    return (a < 0) ? -a : a;
}

const BigInteger gcd(BigInteger a, BigInteger b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const BigInteger lcm(const BigInteger &a, const BigInteger &b) {
    return a * b / gcd(a, b);
}