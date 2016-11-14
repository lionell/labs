//
// Created by lionell on 4/4/15.
//

#ifndef LAB_1_TRAIN_H
#define LAB_1_TRAIN_H

#include "Wagon.h"
#include <vector>

struct Node {
    Node* prev;
    Node* next;
    Wagon* wagon;
    Node(Wagon* _wagon): wagon(_wagon), prev(nullptr), next(nullptr) {}
};

class Train {
private:
    Node* head;
    Node* tail;
public:
    Train(): head(nullptr), tail(nullptr) {}
    ~Train();
    Node *get_head();
    void push_back(Wagon* wagon);
    void push_front(Wagon* wagon);
    void extract(Node* node);
    std::vector<int> to_vector();
    friend void print(Train* train);
};


#endif //LAB_1_TRAIN_H
