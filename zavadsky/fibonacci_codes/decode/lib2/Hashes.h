//
// Created by lionell on 4/23/16.
//

#ifndef DECODE_HASHES_H
#define DECODE_HASHES_H


class Hashes {
public:
    const int MAX_N;
    int* f3;
    int* s3;

    Hashes(const int MAX_N);

    virtual ~Hashes();
};


#endif //DECODE_HASHES_H
