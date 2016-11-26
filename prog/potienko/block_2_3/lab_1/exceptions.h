//
// Created by lionell on 5/23/15.
//

#ifndef LAB_1_EXCEPTIONS_H
#define LAB_1_EXCEPTIONS_H

#include <exception>
#include <string>

class MathError: public std::exception {
private:
    std::string message;
public:
    MathError(const char *_message): message(_message) {}
    const char *what() const throw() {
        return ("Math error occurred with message '" + message + "'").c_str();
    }
};

class ModeError: public std::exception {
private:
    std::string message;
public:
    ModeError(const char *_message): message(_message) {}
    const char *what() const throw() {
        return ("Mode error occurred with message '" + message + "'").c_str();
    }
};

#endif //LAB_1_EXCEPTIONS_H
