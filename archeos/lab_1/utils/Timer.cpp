//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {
    start = Clock::now();
}

void Timer::stop() {
    finish = Clock::now();
}

double Timer::duration() {
    return std::chrono::duration<double>(finish - start).count();
}

double Timer::time_it(void (*func)(uint32_t), uint32_t n) {
    Timer timer;
    func(n);
    timer.stop();
    return timer.duration();
}

double Timer::time_it(void (*func)(void)) {
    Timer timer;
    func();
    timer.stop();
    return timer.duration();
}

double Timer::speed_it(void (*func)(uint32_t), uint32_t n) {
    return n / time_it(func, n);
}