//
// Created by lionell on 4/23/16.
//

#include "decode.h"
#include "utils.h"
#include "common.h"

int next(std::ifstream &in) {
    bool bits[4];

    bits[3] = next_bit(in);
    bits[2] = next_bit(in);
    bits[1] = next_bit(in);

    if (bits[1] && bits[2] && bits[3]) {
        return 1;
    }

    bits[0] = next_bit(in);

    if (bits[0] && bits[1] && bits[2]) {
        return 2;
    }

    int q = 0;
    int pos = 0;
    do {
        if (bits[3]) {
            q += f3[pos];
        }
        pos++;
        bits[3] = bits[2];
        bits[2] = bits[1];
        bits[1] = bits[0];
        bits[0] = next_bit(in);
    } while (!(bits[0] && bits[1] && bits[2]));

    return q + s3[pos - 1] + 1;
}

std::vector<int> decode(std::string path) {
    std::vector<int> ans;

    std::ifstream in(path);

    while (!in.eof()) {
        int num = next(in);
        ans.emplace_back(num);
    }

    in.close();
    return ans;
}