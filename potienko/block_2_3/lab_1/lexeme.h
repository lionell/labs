//
// Created by lionell on 5/11/15.
//

#ifndef LAB_1_LEXEME_H
#define LAB_1_LEXEME_H

#include <string>

enum class LexemeType {
    NUMBER,
    OPERATOR,
    BRACKET
};

class Lexeme {
private:
    LexemeType _type;
    std::string _value;
public:
    Lexeme(LexemeType type, std::string value): _type(type), _value(value) {}
    LexemeType get_type() const { return _type; }
    std::string get_value() const { return _value; }
};

#endif //LAB_1_LEXEME_H
