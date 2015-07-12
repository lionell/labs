//
// Created by lionell on 4/4/15.
//

#include "Station.h"
#include "Train.h"
#include <typeinfo>
#include <typeindex>

Train** Station::unload(Train* train) {
    Train** result = new Train*[3];
    for (int i = 0; i < 3; ++i) result[i] = new Train();
    // Robot 1
    // wagon_types contains typeid's of all kinds of wagons
    const std::type_index wagon_types[] = {typeid(Tank), typeid(Fridge), typeid(Open)};
    for (int i = 0; i < 3; ++i) {
        // Iterating through train
        Node* current = train->get_head();
        while (current != nullptr) {
            Node *next = current->next; // Saving next node, to know where go next
            if (wagon_types[i] == typeid(*current->wagon)) {
                // This is an appropriate wagon
                result[i]->push_front(current->wagon);
                train->extract(current);
            }
            current = next;
        }
    }
    return result;
}