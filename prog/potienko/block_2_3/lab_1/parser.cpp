//
// Created by lionell on 5/13/15.
//

#include "parser.h"
#include <stack>

using namespace std;

int get_priority(string op) {
    int result = -1;
    if (op == "(") result = 0;
    else if (op == "+" || op == "-") result = 1;
    else if (op == "*" || op == "/") result = 2;
    else if (op == "^") result = 3;
    else if (op == "@") result = 4;
    return result;
}

void push_operator(vector<Token*> *result, string op) {
    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^") result->emplace_back(new BinaryOperator(op));
    else if (op == "@") result->emplace_back(new UnaryOperator(op));
}

vector<Token*> parse(vector<Lexeme*> lexemes) {
    vector<Token*> result;
    stack<string> stack1;
    for (int i = 0; i < lexemes.size(); ++i) {
        Lexeme &lexeme = *lexemes[i];
        if (lexeme.get_type() == LexemeType::NUMBER) {
            result.emplace_back(new Number(lexeme.get_value()));
        } else if (lexeme.get_type() == LexemeType::OPERATOR) {
            string operation = lexeme.get_value();
            if (i == 0 || lexemes[i - 1]->get_value() == "(") operation = "@";
            while (!stack1.empty() && get_priority(stack1.top()) >= get_priority(operation)) {
                push_operator(&result, stack1.top());
                stack1.pop();
            }
            stack1.push(operation);
        } else if (lexeme.get_type() == LexemeType::BRACKET) {
            if (lexeme.get_value() == ")") {
                while (stack1.top() != "(") {
                    push_operator(&result, stack1.top());
                    stack1.pop();
                }
                stack1.pop();
            } else stack1.push(lexeme.get_value());
        }
    }
    while (!stack1.empty()) {
        push_operator(&result, stack1.top());
        stack1.pop();
    }
    return result;
}