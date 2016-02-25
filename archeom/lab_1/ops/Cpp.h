//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef LAB_1_CPP_H
#define LAB_1_CPP_H

#pragma GCC push_options
#pragma GCC optimize ("O0")

#include "Op.h"
#include <stdint.h>

class Cpp : public Op {
public:
    template<typename T>
    static void _add(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] += a[0];
            a[1] += a[1];
            a[2] += a[2];
            a[3] += a[3];
            a[4] += a[4];
            a[5] += a[5];
            a[6] += a[6];
            a[7] += a[7];
            a[8] += a[8];
            a[9] += a[9];
        }
    }

    template<typename T>
    static void _sub(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] -= a[0];
            a[1] -= a[1];
            a[2] -= a[2];
            a[3] -= a[3];
            a[4] -= a[4];
            a[5] -= a[5];
            a[6] -= a[6];
            a[7] -= a[7];
            a[8] -= a[8];
            a[9] -= a[9];
        }
    }

    template<typename T>
    static void _mul(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] *= a[0];
            a[1] *= a[1];
            a[2] *= a[2];
            a[3] *= a[3];
            a[4] *= a[4];
            a[5] *= a[5];
            a[6] *= a[6];
            a[7] *= a[7];
            a[8] *= a[8];
            a[9] *= a[9];
        }
    }

    template<typename T>
    static void _div(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] /= a[0];
            a[1] /= a[1];
            a[2] /= a[2];
            a[3] /= a[3];
            a[4] /= a[4];
            a[5] /= a[5];
            a[6] /= a[6];
            a[7] /= a[7];
            a[8] /= a[8];
            a[9] /= a[9];
        }
    }

    template<typename T>
    static void _mod(uint64_t n) {
        T a[11] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22, 126};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] %= a[10];
            a[1] %= a[10];
            a[2] %= a[10];
            a[3] %= a[10];
            a[4] %= a[10];
            a[5] %= a[10];
            a[6] %= a[10];
            a[7] %= a[10];
            a[8] %= a[10];
            a[9] %= a[10];
        }
    }

    template<typename T>
    static void _neg(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] = ~a[0];
            a[1] = ~a[1];
            a[2] = ~a[2];
            a[3] = ~a[3];
            a[4] = ~a[4];
            a[5] = ~a[5];
            a[6] = ~a[6];
            a[7] = ~a[7];
            a[8] = ~a[8];
            a[9] = ~a[9];
        }
    }

    template<typename T>
    static void _and(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] &= a[0];
            a[1] &= a[1];
            a[2] &= a[2];
            a[3] &= a[3];
            a[4] &= a[4];
            a[5] &= a[5];
            a[6] &= a[6];
            a[7] &= a[7];
            a[8] &= a[8];
            a[9] &= a[9];
        }
    }

    template<typename T>
    static void _or(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] |= a[0];
            a[1] |= a[1];
            a[2] |= a[2];
            a[3] |= a[3];
            a[4] |= a[4];
            a[5] |= a[5];
            a[6] |= a[6];
            a[7] |= a[7];
            a[8] |= a[8];
            a[9] |= a[9];
        }
    }

    template<typename T>
    static void _xor(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 22};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] ^= a[0];
            a[1] ^= a[1];
            a[2] ^= a[2];
            a[3] ^= a[3];
            a[4] ^= a[4];
            a[5] ^= a[5];
            a[6] ^= a[6];
            a[7] ^= a[7];
            a[8] ^= a[8];
            a[9] ^= a[9];
        }
    }

    template<typename T>
    static void _lsh(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 2};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] <<= a[0];
            a[1] <<= a[1];
            a[2] <<= a[2];
            a[3] <<= a[3];
            a[4] <<= a[4];
            a[5] <<= a[5];
            a[6] <<= a[6];
            a[7] <<= a[7];
            a[8] <<= a[8];
            a[9] <<= a[9];
        }
    }

    template<typename T>
    static void _rsh(uint64_t n) {
        T a[10] = {57, 121, 89, 74, 123, 87, 52, 68, 69, 2};
        for (uint64_t i = 0; i < n; ++i) {
            a[0] >>= a[0];
            a[1] >>= a[1];
            a[2] >>= a[2];
            a[3] >>= a[3];
            a[4] >>= a[4];
            a[5] >>= a[5];
            a[6] >>= a[6];
            a[7] >>= a[7];
            a[8] >>= a[8];
            a[9] >>= a[9];
        }
    }
};

//int main() {
//    Cpp::_add<uint8_t>(100);
//    return 0;
//}

#pragma GCC pop_options

#endif //LAB_1_CPP_H
