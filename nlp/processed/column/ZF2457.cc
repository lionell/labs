//
//  Column.cpp
//  Vinnica
//
//  Created by Raksha Vadim on 10.11.2017.
//  Copyright © 2017 Raksha Vadim. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> IntegerVector;

int main() {
    int n;
    cin >> n;
    int data[n];
    vector<IntegerVector> columns(n);
    
    int max = -1;
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        data[i] = r;
        if (r > max) max = r;
    }
    
    for (int i = 0; i < n; i++) {
        columns[i] = vector<int>(max);
        for (int j = 0; j < max; j++) {
            if (j <= data[i] - 1)
                columns[i][j] = 1;
            else
                columns[i][j] = 0;
        }
    }
    
    int water = 0;
    for (int i = 0; i < max; i++) {
        bool started = false;
        int tempWater = 0;
        
        for (int j = 0; j < columns.size(); j++) {
            int prevValue = j >= 1 ? columns[j-1][i] : -1;
            int nextValue = j + 1 < columns.size() ? columns[j+1][i] : -1;
            
            int value = columns[j][i];
            
            if (value == 1) {
                if (nextValue == 0) {
                    started = true;
                } else {
                    if (started && prevValue == 0) {
                        water += tempWater;
                        tempWater = 0;
                    }
                    started = false;
                }
            } else if (value == 0) {
                if (prevValue == 1 || (prevValue == 0 && started)) {
                    tempWater++;
                }
            }
        }
    }
    
    cout << water << endl;
    
    return 0;
}
