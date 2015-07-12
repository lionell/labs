//
// Created by lionell on 6/9/15.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>

class Graph {
protected:
    bool *used;
    int *path;
    int path_length;
public:
    Graph(): used(nullptr), path(nullptr), path_length(0) {}
    virtual ~Graph() {}
    virtual void read(std::istream &in) = 0;
    virtual void find(int v, std::ostream &out) = 0;
};

class Graph1: public Graph {
private:
    bool search(int from, int v);
public:
    int n;
    int **map;
    Graph1(): Graph(), n(0), map(nullptr) {};
    ~Graph1();
    void read(std::istream &in);
    void find(int v, std::ostream &out);
};

class Graph2: public Graph {
private:
    bool search(int from, int v);
public:
    int n;
    int *m;
    int **map;
    Graph2(): Graph(), n(0), m(nullptr), map(nullptr) {};
    ~Graph2();
    void read(std::istream &in);
    void find(int v, std::ostream &out);
};


#endif //GRAPH_GRAPH_H
