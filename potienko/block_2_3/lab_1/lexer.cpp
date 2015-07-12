//
// Created by lionell on 5/13/15.
//

#include "lexer.h"

std::vector<Lexeme*> scan(const std::string &s) {
    std::vector<Lexeme*> result;
    unsigned long i = 0;
    while (i < s.length()) {
        if (s[i] == ' ') ++i;
        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^') {
            result.emplace_back(new Lexeme(LexemeType::OPERATOR, s.substr(i++, 1)));
        } else if (s[i] == '(' || s[i] == ')') {
            result.emplace_back(new Lexeme(LexemeType::BRACKET, s.substr(i++, 1)));
        } else if (isdigit(s[i])) {
            unsigned long j = i;
            while (isdigit(s[j])) ++j;
            if (s[j] == '.' || tolower(s[j]) == 'e') ++j;
            while (isdigit(s[j])) ++j;
            result.emplace_back(new Lexeme(LexemeType::NUMBER, s.substr(i, j - i)));
            i = j;
        }
    }
    return result;
}