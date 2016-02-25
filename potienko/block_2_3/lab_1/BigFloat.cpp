//
// Created by lionell on 5/23/15.
//

#include "BigFloat.h"
#include <iostream>
#include "exceptions.h"

using namespace std;

BigFloat::BigFloat(const BigFloat &example): BigFloat() {
    this->numerator = example.numerator;
    this->denominator = example.denominator;
    this->balance();
}

BigFloat::BigFloat(const std::string &s): BigFloat() {
    int i = 0;
    if (s[i] == '-') ++i;
    while (i < s.length() && isdigit(s[i])) ++i;
    int j = 0;
    if (tolower(s[i]) == 'e' && s[i + 1] == '-') ++j;
    while (i + 1 + j < s.length() && isdigit(s[i + 1 + j])) ++j;
    if (s[i] == '.') {
        this->numerator = s.substr(0UL, 1UL * i) + s.substr(1UL * i + 1, 1UL * j);
        this->denominator = BigInteger(BigInteger::BASE) ^ j;
    } else if (tolower(s[i]) == 'e') {
        BigInteger exponent = s.substr(1UL * i + 1, 1UL * j);
        this->numerator = s.substr(0UL, 1UL * i);
        this->denominator = 1;
        if (exponent > 0) this->numerator *= BigInteger(BigInteger::BASE) ^ exponent;
        else this->denominator *= BigInteger(BigInteger::BASE) ^ -exponent;
    } else {
        this->numerator = s.substr(0UL, 1UL * i);
        this->denominator = 1;
    }
    this->balance();
}

void BigFloat::balance() {
    BigInteger common = gcd(abs(this->numerator), this->denominator);
    this->numerator /= common;
    this->denominator /= common;
}

void raw_print(const BigFloat x, ostream &out) {
    print(x.numerator, out);
    out << "/";
    print(x.denominator, out);
}

void print(BigFloat x, int precision, ostream &out) {
    if (x.numerator < 0) {
        out << "-";
        x.numerator *= -1;
    }
    print(x.numerator / x.denominator, out);
    x.numerator %= x.denominator;
    out << ".";
    for (int i = 0; i < precision; ++i) {
        x.numerator *= BigInteger::BASE;
        print(x.numerator / x.denominator, out);
        x.numerator %= x.denominator;
    }
}

const BigFloat operator-(const BigFloat &x) {
    BigFloat result = x;
    result.numerator *= -1;
    return result;
}

const BigFloat operator+(const BigFloat &left, const BigFloat &right) {
    BigInteger denominator = lcm(left.denominator, right.denominator);
    BigInteger numerator = left.numerator * denominator / left.denominator + right.numerator * denominator / right.denominator;
    return BigFloat(numerator, denominator);
}

const BigFloat operator-(const BigFloat &left, const BigFloat &right) {
    BigInteger denominator = lcm(left.denominator, right.denominator);
    BigInteger numerator = left.numerator * (denominator / left.denominator) - right.numerator * (denominator / right.denominator);
    return BigFloat(numerator, denominator);
}

const BigFloat operator*(const BigFloat &left, const BigFloat &right) {
    BigInteger denominator = left.denominator * right.denominator;
    BigInteger numerator = left.numerator * right.numerator;
    return BigFloat(numerator, denominator);
}

const BigFloat operator/(const BigFloat &left, const BigFloat &right) {
    BigInteger denominator = left.denominator * right.numerator;
    if (denominator == 0) throw MathError("Division by zero");
    BigInteger numerator = left.numerator * right.denominator;
    if (denominator < 0) numerator *= -1;
    return BigFloat(numerator, abs(denominator));
}

const BigFloat operator^(const BigFloat &left, const BigFloat &right) {
    if (right.denominator != 1) throw MathError("Unexpected non-integer argument");
    BigFloat result(1, 1);
    BigFloat base = left;
    BigInteger exponent = right.numerator;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result *= base;
        base *= base;
        exponent /= 2;
    }
    return result;
}

BigFloat &operator+=(BigFloat &left, const BigFloat &right) {
    left = left + right;
    return left;
}

BigFloat &operator-=(BigFloat &left, const BigFloat &right) {
    left = left - right;
    return left;
}

BigFloat &operator*=(BigFloat &left, const BigFloat &right) {
    left = left * right;
    return left;
}

BigFloat &operator/=(BigFloat &left, const BigFloat &right) {
    left = left / right;
    return left;
}

BigFloat &operator^=(BigFloat &left, const BigFloat &right) {
    left = left ^ right;
    return left;
}