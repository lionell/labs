//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef LAB_1_BENCHMARK_H
#define LAB_1_BENCHMARK_H

#include <string>
#include <vector>
#include <iostream>

class Benchmark {
public:
    static std::vector<std::tuple<std::string, std::string, double>> run_cpp(std::ostream *out = &std::cerr);

    static std::vector<std::tuple<std::string, std::string, double>> run_asm(std::ostream *out = &std::cerr);
};


#endif //LAB_1_BENCHMARK_H
