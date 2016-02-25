//
// Created by lionell on 4/4/15.
//

#include "Train.h"
#include <typeinfo>
#include <iostream>

Train::~Train() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

Node *Train::get_head() {
    return head;
}

void Train::push_back(Wagon *wagon) {
    Node *new_node = new Node(wagon);
    if (tail != nullptr) {
        tail->next = new_node;
        new_node->prev = tail;
    } else head = new_node;
    tail = new_node;
}

void Train::push_front(Wagon* wagon) {
    Node *new_node = new Node(wagon);
    if (head != nullptr) {
        head->prev = new_node;
        new_node->next = head;
    } else tail = new_node;
    head = new_node;
}

void Train::extract(Node *node) {
    if (node == head) head = node->next;
    else node->prev->next = node->next;
    if (node == tail) tail = node->prev;
    else node->next->prev = node->prev;
    delete node;
}

std::vector<int> Train::to_vector() {
    std::vector<int> *result = new std::vector<int>();
    Node *current = head;
    while (current != nullptr) {
        result->push_back(current->wagon->number);
        current = current->next;
    }
    return *result;
}

void print(Train *train) {
    std::cout << "T ";
    Node* current = train->head;
    while (current != nullptr) {
        std::cout << current->wagon->number << "(" << typeid(*current->wagon).name() + 1 << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}