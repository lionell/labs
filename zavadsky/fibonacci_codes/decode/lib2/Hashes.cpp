//
// Created by lionell on 4/23/16.
//

#include "Hashes.h"

Hashes::Hashes(const int MAX_N): MAX_N(MAX_N) {
    f3 = new int[MAX_N];
    s3 = new int[MAX_N];

    f3[0] = 1;
    f3[1] = 2;
    f3[2] = 4;
    s3[0] = 2;
    s3[1] = 4;
    s3[2] = 8;

    for (int i = 3; i < MAX_N; ++i) {
        f3[i] = f3[i - 1] + f3[i - 2] + f3[i - 3];
        s3[i] = s3[i - 1] + f3[i];
    }
}

Hashes::~Hashes() {
    delete[] f3;
    delete[] s3;
}