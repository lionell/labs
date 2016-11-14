//
// Created by lionell on 5/14/15.
//

#ifndef LONG_ARITHMETIC_BIGFLOAT_H
#define LONG_ARITHMETIC_BIGFLOAT_H

#include "BigInteger.h"

class BigFloat {
private:
    BigInteger numerator;
    BigInteger denominator;
    void balance();
public:
    BigFloat(const BigInteger _numerator = 0, const BigInteger _denominator = 1): numerator(_numerator), denominator(_denominator) {};
    BigFloat(const BigFloat &example);
    BigFloat(const std::string &s);
    friend void raw_print(const BigFloat x);
    friend void print(BigFloat x, int precision = 20);
    friend const BigFloat operator-(const BigFloat &x);
    friend const BigFloat operator+(const BigFloat &left, const BigFloat &right);
    friend const BigFloat operator-(const BigFloat &left, const BigFloat &right);
    friend const BigFloat operator*(const BigFloat &left, const BigFloat &right);
    friend const BigFloat operator/(const BigFloat &left, const BigFloat &right);
    friend const BigFloat operator^(const BigFloat &left, const BigFloat &right);
    friend BigFloat &operator+=(BigFloat &left, const BigFloat &right);
    friend BigFloat &operator-=(BigFloat &left, const BigFloat &right);
    friend BigFloat &operator*=(BigFloat &left, const BigFloat &right);
    friend BigFloat &operator/=(BigFloat &left, const BigFloat &right);
    friend BigFloat &operator^=(BigFloat &left, const BigFloat &right);
};


#endif //LONG_ARITHMETIC_BIGFLOAT_H
