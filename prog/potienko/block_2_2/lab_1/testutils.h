//
// Created by lionell on 4/4/15.
//

#ifndef LAB_1_TESTUTILS_H
#define LAB_1_TESTUTILS_H

#include "testlib.h"
#include "Train.h"

class Test: public BasicTest {
public:
    Train* train;
    std::vector<int> trains[3];
    void initialize();
    virtual void set_up() = 0;
    bool run();
    void finalize();
};

std::vector<int> transform(Train *train);
bool is_equal(Train **one, std::vector<int> two[3]);


#endif //LAB_1_TESTUTILS_H
