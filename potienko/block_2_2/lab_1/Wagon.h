//
// Created by lionell on 4/4/15.
//

#ifndef LAB_1_WAGON_H
#define LAB_1_WAGON_H


class Wagon {
public:
    static int count;
    int number;
    Wagon(): number(++count) {}
    virtual ~Wagon() {}
};

class Tank: public Wagon {
public:
    Tank(): Wagon() {}
};

class Fridge: public Wagon {
public:
    Fridge(): Wagon() {}
};

class Open: public Wagon {
public:
    Open(): Wagon() {}
};


#endif //LAB_1_WAGON_H
