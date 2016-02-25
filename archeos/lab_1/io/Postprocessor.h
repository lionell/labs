//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef LAB_1_PREPROCESSOR_H
#define LAB_1_PREPROCESSOR_H

#include <bits/stdc++.h>

class Preprocessor {
    std::vector<std::tuple<std::string, std::string, double>> data_;
public:
    Preprocessor(const std::vector<std::tuple<std::string, std::string, double>> &data) : data_(data) { }

    virtual ~Preprocessor() { }
};


#endif //LAB_1_PREPROCESSOR_H
