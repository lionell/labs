//
// Created by lionell on 5/13/15.
//

#ifndef LAB_1_CALCULATOR_H
#define LAB_1_CALCULATOR_H

#include <string>
#include <vector>
#include "BigFloat.h"
#include "token.h"

BigFloat evaluate(const BigFloat &left, const std::string &operation);
BigFloat evaluate(const BigFloat &left, const BigFloat &right, const std::string &operation);
BigFloat calculate(std::vector<Token*> rpn);

#endif //LAB_1_CALCULATOR_H
