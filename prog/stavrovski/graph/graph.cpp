//
// Created by lionell on 6/9/15.
//

#include "graph.h"
#include <vector>

Graph1::~Graph1() {
    for (int i = 0; i < this->n; ++i) {
        delete[] this->map[i];
    }
    delete[] this->map;
}

void Graph1::read(std::istream &in) {
    in >> this->n;
    this->map = new int*[this->n];
    for (int i = 0; i < this->n; ++i) {
        this->map[i] = new int[this->n]();
    }
    int m = 0;
    in >> m;
    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0;
        in >> a >> b;
        this->map[a][b] = this->map[b][a] = true;
    }
}

bool Graph1::search(int from, int v) {
    this->path[this->path_length++] = v;
    for (int i = 0; i < this->n; ++i) {
        if (i != v && i != from && this->map[v][i]) {
            if (!this->used[i]) {
                this->used[i] = true;
                if (search(v, i)) return true;
                this->used[i] = false;
            }
            else {
                this->path[this->path_length++] = i;
                return true;
            }
        }
    }
    this->path_length--;
}

void Graph1::find(int v, std::ostream &out) {
    this->used = new bool[this->n]();
    this->path = new int[this->n]();
    this->used[v] = true;
    if (search(v, v)) {
        for (int i = 0; i < this->path_length - 1; ++i) {
            out << this->path[i] << "->";
        }
        out << this->path[path_length - 1];
    } else out << "No cycle found";
    out << std::endl;
    delete[] this->used;
    delete[] this->path;
}

Graph2::~Graph2() {
    for (int i = 0; i < n; ++i) {
        delete[] map[i];
    }
    delete[] m;
    delete[] map;
}

void Graph2::read(std::istream &in) {
    in >> this->n;
    int m = 0;
    in >> m;
    std::vector<int> list[n];
    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0;
        in >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    this->m = new int[n]();
    this->map = new int*[n];
    for (int i = 0; i < n; ++i) {
        this->m[i] = (int)list[i].size();
        this->map[i] = new int[this->m[i]]();
        for (int j = 0; j < list[i].size(); ++j) {
            this->map[i][j] = list[i][j];
        }
    }
}

bool Graph2::search(int from, int v) {
    this->path[this->path_length++] = v;
    for (int i = 0; i < this->m[v]; ++i) {
        int next = this->map[v][i];
        if (next != from) {
            if (!this->used[next]) {
                this->used[next] = true;
                if (search(v, next)) return true;
                this->used[next] = false;
            }
            else {
                this->path[this->path_length++] = next;
                return true;
            }
        }
    }
    this->path_length--;
}

void Graph2::find(int v, std::ostream &out) {
    this->used = new bool[this->n]();
    this->path = new int[this->n]();
    this->used[v] = true;
    if (search(v, v)) {
        for (int i = 0; i < this->path_length - 1; ++i) {
            out << this->path[i] << "->";
        }
        out << this->path[path_length - 1];
    } else out << "No cycle found";
    out << std::endl;
    delete[] this->used;
    delete[] this->path;
}