//
//  main.cpp
//  calc
//
//

#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Tree t;
    cout << "2+2*2 = " << t.calculate("    2 + 2 * 2    ") << "\n";
    cout << "(2+2)*2 = " << t.calculate("  (  2 + 2 )* 2    ") << "\n";
    cout << "4-3-2 = " << t.calculate("4-3-2") << "\n";
    cout << "4-3-(-2) = " << t.calculate("4-3-(-2)") << "\n";
    cout << "20 + (4-7)/2*(3+1) = " << t.calculate("20 + (4-7)/2*(3+1)") << "\n";
    cout << "12/2/3 = " << t.calculate("12/2/3") << "\n";
    cout << "12/(5%3) = " << t.calculate("12/(5%3)") << "\n";
    
    return 0;
}
