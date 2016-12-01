//
// Created by lionell on 4/23/16.
//

#ifndef DECODE_DICTIONARY_H
#define DECODE_DICTIONARY_H

#include <string>
#include <map>

class Dictionary {
public:
    std::map<int, std::string> dict;

    void load(std::string path);
};


#endif //DECODE_DICTIONARY_H
