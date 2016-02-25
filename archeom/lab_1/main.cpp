/*
 * Created by lionell on 20.02.16.
 * Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
 *
 * +--------------------+-------------+---+---+---+---+---+---+---+---+---+----+----+
 * |      typename      |    type     | + | - | * | / | % | ~ | & | | | ^ | << | >> |
 * +--------------------+-------------+---+---+---+---+---+---+---+---+---+----+----+
 * | signed char        | int8        | + | + | + | + | + | + | + | + | + | +  | +  |
 * | unsigned char      | uint8       | + | + | + | + | + | + | + | + | + | +  | +  |
 * | signed short       | int16       | + | + | + | + | + | + | + | + | + | +  | +  |
 * | unsigned short     | uint16      | + | + | + | + | + | + | + | + | + | +  | +  |
 * | signed int         | int32       | + | + | + | + | + | + | + | + | + | +  | +  |
 * | unsigned int       | uint32      | + | + | + | + | + | + | + | + | + | +  | +  |
 * | signed long long   | int64       | + | + | + | + | + | + | + | + | + | +  | +  |
 * | unsigned long long | uint64      | + | + | + | + | + | + | + | + | + | +  | +  |
 * | float              | float       | + | + | + | + | - | - | - | - | - | -  | -  |
 * | double             | double      | + | + | + | + | - | - | - | - | - | -  | -  |
 * | long double        | long double | + | + | + | + | - | - | - | - | - | -  | -  |
 * | bool               | bool        | + | + | + | + | + | + | + | + | + | +  | +  |
 * +--------------------+-------------+---+---+---+---+---+---+---+---+---+----+----+
 */

#include "io/Postprocessor.h"
#include "Benchmark.h"
#include "utils/Timer.h"
#include "ops/Cpp.h"
#include "ops/Asm.h"

int main() {
//    std::ofstream out("/home/lionell/dev/labs/archeos/lab_1/logs/asm.txt");
//    Postprocessor::process(Benchmark::run_cpp(&std::cerr), &std::cerr);
    Postprocessor::process(Benchmark::run_asm(&std::cerr), &std::cerr);
//    out.close();
    return 0;
}
