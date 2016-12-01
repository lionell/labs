//
// Created by lionell on 4/4/15.
//

#ifndef LAB_1_TESTLIB_H
#define LAB_1_TESTLIB_H

#include <vector>
#include <iostream>
#include "Train.h"

class BasicTest {
public:
    BasicTest() {}
    virtual void initialize() {}
    virtual void describe() {}
    virtual bool run() = 0;
    virtual void finalize() {}
    virtual ~BasicTest() {}
};

class Tester {
private:
    std::vector<BasicTest*> tests;
public:
    Tester() {}
    void add(BasicTest* test);
    void run_all_tests();
};

#endif //LAB_1_TESTLIB_H
