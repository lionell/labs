//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef LAB_1_PREPROCESSOR_H
#define LAB_1_PREPROCESSOR_H

#include <bits/stdc++.h>

class Postprocessor {
public:
    static void process(std::vector<std::tuple<std::string, std::string, double>> data, std::ostream *out = &std::cerr);

private:
    static double get_max_speed(std::vector<std::tuple<std::string, std::string, double>> data);

    static std::string generate_bar(int length);
};


#endif //LAB_1_PREPROCESSOR_H
