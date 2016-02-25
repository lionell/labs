//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef CONFIG_TIMER_H
#define CONFIG_TIMER_H

#include <chrono>
using Clock = std::chrono::high_resolution_clock;

class Timer {
    Clock::time_point start_;
    Clock::time_point finish_;
public:
    Timer();
    void stop();
    void restart();
    double duration();
    static double time_it(void (*func)(uint64_t), uint64_t n);
    static double speed_it(void (*func)(uint64_t), uint64_t n, uint64_t count = 10);
};


#endif //CONFIG_TIMER_H
