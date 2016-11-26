#include <fstream>
#include <sstream>
#include <ctime>
#include "graph.h"

using namespace std;

int main() {
    string file_name = "";
    ifstream in;
    do {
        cout << "Enter filename: ";
        cin >> file_name;
        in.open(file_name);
        if (!in.is_open()) cout << "No such file found! Try again." << endl;
    } while (!in.is_open());
    stringstream example;
    example << in.rdbuf();
    stringstream input1(example.str());
    Graph1 graph1;
    clock_t start = clock();
    graph1.read(input1);
    cout << "Matrix read: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s." << endl;
    start = clock();
    graph1.find(0, cout);
    cout << "Matrix eval: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s." << endl;
    stringstream input2(example.str());
    Graph2 graph2;
    start = clock();
    graph2.read(input2);
    cout << "Lists read: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s." << endl;
    start = clock();
    graph2.find(0, cout);
    cout << "Lists eval: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s." << endl;
    return 0;
}