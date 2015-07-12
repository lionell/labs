//
// Created by lionell on 5/13/15.
//

#include "calculator.h"
#include <stack>
#include <typeinfo>

BigFloat evaluate(const BigFloat &left, const std::string &operation) {
    BigFloat result;
    if (operation == "@") result = -left;
    return result;
}

BigFloat evaluate(const BigFloat &left, const BigFloat &right, const std::string &operation) {
    BigFloat result;
    if (operation == "+") result = left + right;
    else if (operation == "-") result = left - right;
    else if (operation == "*") result = left * right;
    else if (operation == "/") result = left / right;
    else if (operation == "^") result = left ^ right;
    return result;
}

BigFloat calculate(std::vector<Token*> rpn) {
    std::stack<BigFloat> stack1;
    for (auto& token: rpn) {
        if (typeid(*token) == typeid(Number)) {
            Number *number = static_cast<Number*>(token);
            stack1.push(number->get_value());
        } else if (typeid(*token) == typeid(UnaryOperator)) {
            UnaryOperator *operation = static_cast<UnaryOperator*>(token);
            BigFloat left = stack1.top(); stack1.pop();
            stack1.push(evaluate(left, operation->get_value()));
        } else if (typeid(*token) == typeid(BinaryOperator)) {
            BinaryOperator *operation = static_cast<BinaryOperator*>(token);
            BigFloat right = stack1.top(); stack1.pop();
            BigFloat left = stack1.top(); stack1.pop();
            stack1.push(evaluate(left, right, operation->get_value()));
        }
    }
    return stack1.top();
}