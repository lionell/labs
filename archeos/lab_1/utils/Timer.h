//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef CONFIG_TIMER_H
#define CONFIG_TIMER_H

#include <chrono>
using Clock = std::chrono::high_resolution_clock;

class Timer {
    Clock::time_point start;
    Clock::time_point finish;
public:
    Timer();
    void stop();
    double duration();
    static double time_it(void (*func)(uint32_t), uint32_t n);
    static double time_it(void (*func)(void));
    static double speed_it(void (*func)(uint32_t), uint32_t n);
};


#endif //CONFIG_TIMER_H
