//
// Created by lionell on 5/11/15.
//

#ifndef LAB_1_TOKEN_H
#define LAB_1_TOKEN_H

#include <string>
#include "BigInteger.h"
#include "BigFloat.h"

class Token {
public:
    Token() {}
    virtual ~Token() {}
};

class Number: public Token {
private:
    BigFloat _value;
public:
    Number(const std::string s): _value(s) {}
    ~Number() {}
    BigFloat get_value() const { return _value; }
};

class Operator: public Token {
private:
    std::string _value;
public:
    Operator(std::string value = ""): _value(value) {}
    std::string get_value() const { return _value; }
};

class UnaryOperator: public Operator {
public:
    UnaryOperator(std::string value): Operator(value) {}
    ~UnaryOperator() {}
};

class BinaryOperator: public Operator {
public:
    BinaryOperator(std::string value): Operator(value) {}
    ~BinaryOperator() {}
};

#endif //LAB_1_TOKEN_H
