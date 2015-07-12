#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    int v;
    cout << "Enter the number of vertices\n";
    cin >> v;
    cout << "Enter the name of the file for output\n";
    char out_path[1000] = {};
    cin.get();
    cin.getline(out_path, 1000);
    if(out_path[0] == '\0') strcpy(out_path, "output.txt");
    ofstream out(out_path);
    out << v <<' '<< v <<endl;
    for(int i = 0; i < v - 1; ++i)
        out << i <<' '<< i + 1 <<endl;
    out << v - 1 <<' '<< 0 <<endl;
    return 0;
}
