//
// Created by lionell on 5/23/15.
//

#ifndef LAB_1_TESTLIB_H
#define LAB_1_TESTLIB_H

#include <vector>
#include <string>

class Test {
private:
    std::string input;
    std::string output;
public:
    Test(std::string _input, std::string _output): input(_input), output(_output) {}
    void describe();
    bool run();
};

class Tester {
private:
    std::vector<Test*> tests;
public:
    Tester() {}
    ~Tester();
    void add(Test *test);
    void run_all_tests();
};

#endif //LAB_1_TESTLIB_H
