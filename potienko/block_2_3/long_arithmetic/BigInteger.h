//
// Created by lionell on 5/14/15.
//

#ifndef LONG_ARITHMETIC_BIGINTEGER_H
#define LONG_ARITHMETIC_BIGINTEGER_H

#include <vector>
#include <string>
#include <cmath>

class BigInteger {
private:
    bool positive;
    std::vector<int> data;
public:
    static constexpr int BASE = 10;
    static constexpr int DIGITS_COUNT = (int)log10((double)BASE);
    BigInteger(): data(), positive(true) {}
    BigInteger(const BigInteger &example); // Checked
    BigInteger(long long x); // Checked
    BigInteger(std::string s); // Checked
    BigInteger &operator=(const BigInteger &example); // Checked
    friend void print(const BigInteger x); // Checked
    friend void scan(BigInteger &x); // Checked
    friend const BigInteger operator-(const BigInteger& x); // Checked
    friend bool operator<(const BigInteger &left, const BigInteger &right); // Checked
    friend bool operator>(const BigInteger &left, const BigInteger &right); // Checked
    friend bool operator==(const BigInteger &left, const BigInteger &right); // Checked
    friend bool operator!=(const BigInteger &left, const BigInteger &right); // Checked
    friend bool operator<=(const BigInteger &left, const BigInteger &right); // Checked
    friend bool operator>=(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator+(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator-(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator*(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator/(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator%(const BigInteger &left, const BigInteger &right); // Checked
    friend const BigInteger operator^(const BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator+=(BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator-=(BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator*=(BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator/=(BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator%=(BigInteger &left, const BigInteger &right); // Checked
    friend BigInteger &operator^=(BigInteger &left, const BigInteger &right); // Checked
};

const BigInteger abs(const BigInteger &a);
const BigInteger gcd(BigInteger a, BigInteger b);
const BigInteger lcm(const BigInteger &a, const BigInteger &b);

#endif //LONG_ARITHMETIC_BIGINTEGER_H
