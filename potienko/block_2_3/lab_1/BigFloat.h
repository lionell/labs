//
// Created by lionell on 5/23/15.
//

#ifndef LAB_1_BIGFLOAT_H
#define LAB_1_BIGFLOAT_H

#include "BigInteger.h"
#include <iostream>

class BigFloat {
private:
    BigInteger numerator;
    BigInteger denominator;
    void balance();
public:
    BigFloat(const BigInteger _numerator = 0, const BigInteger _denominator = 1): numerator(_numerator), denominator(_denominator) {};
    BigFloat(const BigFloat &example);
    BigFloat(const std::string &s);
    friend void raw_print(const BigFloat x, std::ostream &out = std::cout);
    friend void print(BigFloat x, int precision = 20, std::ostream &out = std::cout);
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

#endif //LAB_1_BIGFLOAT_H
