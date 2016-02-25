#include <fstream>
#include <iostream>

using namespace std;

#define DEBUG

#ifdef DEBUG
#define cin in
ifstream in("/home/lionell/Developing/university/matfuck/mili/in.txt");
#endif

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int **delta = new int*[m];
    for (int i  = 0; i < m; ++i)
        delta[i] = new int[n]();
    int **lambda = new int*[m];
    for (int i = 0; i < m; ++i)
        lambda[i] = new int[n]();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> delta[i][j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> lambda[i][j];
    }
    string input = "";
    cin >> input;
    int current = 0;
    for (int i = 0; i < input.length(); ++i) {
        cout << lambda[input[i] - '0'][current];
        current = delta[input[i] - '0'][current];
    }
    for (int i = 0; i < m; ++i)
        delete[] delta[i];
    delete[] delta;
    for (int i = 0; i < m; ++i)
        delete[] lambda[i];
    delete[] lambda;
    return 0;
}