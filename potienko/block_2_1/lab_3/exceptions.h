//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_3_EXCEPTIONS_H_
#define _LAB_3_EXCEPTIONS_H_

#include <exception>

class DoubleExpected : public std::exception {
public:
    const char* what() const throw() {
        return "Error 1. Double expected";
    }
};

class PositiveDoubleExpected : public std::exception {
public:
    const char* what() const throw() {
        return "Error 2. Positive double expected";
    }
};

class IntegerExpected : public std::exception {
public:
    const char* what() const throw() {
        return "Error 3. Integer expected";
    }
};

class PositiveIntegerExpected : public std::exception {
public:
    const char* what() const throw() {
        return "Error 4. Positive integer expected";
    }
};

#endif //_LAB_3_EXCEPTIONS_H_
