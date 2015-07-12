//
// Created by lionell on 5/14/15.
//

#ifndef LONG_ARITHMETIC_EXCEPTIONS_H
#define LONG_ARITHMETIC_EXCEPTIONS_H

#include <exception>
#include <string>

class UndefinedError: public std::exception {
private:
    std::string message;
public:
    UndefinedError(const char *_message): message(_message) {}
    const char *what() const throw() {
        return ("Undefined error occurred with message '" + message + "'").c_str();
    }
};

class MathError: public std::exception {
private:
    std::string message;
public:
    MathError(const char *_message): message(_message) {}
    const char *what() const throw() {
        return ("Math error occurred with message '" + message + "'").c_str();
    }
};

#endif //LONG_ARITHMETIC_EXCEPTIONS_H
