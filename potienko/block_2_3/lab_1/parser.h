//
// Created by lionell on 5/11/15.
//

#ifndef LAB_1_PARSER_H
#define LAB_1_PARSER_H

#include <string>
#include <vector>
#include "token.h"
#include "lexeme.h"

int get_priority(std::string op);
void push_operator(std::vector<Token*> *result, std::string op);
std::vector<Token*> parse(std::vector<Lexeme*> lexemes);

#endif //LAB_1_PARSER_H
