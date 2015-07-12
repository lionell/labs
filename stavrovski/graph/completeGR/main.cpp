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
    out << v <<' '<< (v * (v - 1))/2 <<endl;
    for(int i = 0; i < v; ++i)
        for(int j = i; j < v; ++j)
                if(i != j)out << i <<' '<< j <<endl;
    return 0;
}
