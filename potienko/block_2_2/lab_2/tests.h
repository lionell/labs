//
// Created by lionell on 4/7/15.
//

#ifndef LAB_2_TESTS_H
#define LAB_2_TESTS_H

#include "testutils.h"

class Test1: public Test {
public:
    void set_up() {
        train->push_back(new Tank());
        train->push_back(new Fridge());
        train->push_back(new Open());
        trains[0] = {1};
        trains[1] = {2};
        trains[2] = {3};
    }
};

class Test2: public Test {
public:
    void set_up() {
        train->push_back(new Tank());
        train->push_back(new Tank());
        train->push_back(new Fridge());
        train->push_back(new Tank());
        train->push_back(new Open());
        train->push_back(new Tank());
        trains[0] = {6, 4, 2, 1};
        trains[1] = {3};
        trains[2] = {5};
    }
};

class Test3: public Test {
public:
    void set_up() {
        train->push_back(new Fridge());
        train->push_back(new Tank());
        train->push_back(new Open());
        train->push_back(new Fridge());
        train->push_back(new Fridge());
        train->push_back(new Tank());
        train->push_back(new Tank());
        train->push_back(new Open());
        train->push_back(new Tank());
        train->push_back(new Fridge());
        train->push_back(new Open());
        train->push_back(new Fridge());
        train->push_back(new Fridge());
        trains[0] = {9, 7, 6, 2};
        trains[1] = {13, 12, 10, 5, 4, 1};
        trains[2] = {11, 8, 3};
    }
};

class Test4: public Test {
public:
    void set_up() {
        train->push_back(new Tank());
        train->push_back(new Open());
        train->push_back(new Fridge());
        train->push_back(new Fridge());
        train->push_back(new Tank());
        train->push_back(new Open());
        train->push_back(new Fridge());
        train->push_back(new Fridge());
        train->push_back(new Open());
        train->push_back(new Fridge());
        train->push_back(new Fridge());
        train->push_back(new Tank());
        train->push_back(new Fridge());
        train->push_back(new Tank());
        trains[0] = {14, 12, 5, 1};
        trains[1] = {13, 11, 10, 8, 7, 4, 3};
        trains[2] = {9, 6, 2};
    }
};

#endif //LAB_2_TESTS_H
