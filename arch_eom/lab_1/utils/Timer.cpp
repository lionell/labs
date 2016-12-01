//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {
    start_ = Clock::now();
}

void Timer::stop() {
    finish_ = Clock::now();
}

void Timer::restart() {
    start_ = Clock::now();
}

double Timer::duration() {
    return std::chrono::duration<double>(finish_ - start_).count();
}

double Timer::time_it(void (*func)(uint64_t), uint64_t n) {
    Timer timer;
    func(n);
    timer.stop();
    return timer.duration();
}

double Timer::speed_it(void (*func)(uint64_t), uint64_t n, uint64_t count) {
    return n * count / time_it(func, n);
}
