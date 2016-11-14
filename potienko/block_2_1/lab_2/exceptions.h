//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_2_EXCEPTIONS_H_
#define _LAB_2_EXCEPTIONS_H_

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

#endif //_LAB_2_EXCEPTIONS_H_
