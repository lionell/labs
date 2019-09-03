#include <iostream>

using namespace std;

int ar[10000002];

int main()
{
    int N, x, num_left_max, num_right_max, max_stolb = -1;
    long long wat_and_stone = 0, stone = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> x;
        ar[i] = x;
        stone += ar[i];
        if (x > max_stolb){
            num_left_max = i;
            num_right_max = i;
            max_stolb = x;
        }
        if (x == max_stolb){
            num_right_max = i;
        }
    }

    int h = 0;
    for (int i = 0; i < num_left_max; ++i){
        if (ar[i] > h){
            wat_and_stone += ar[i];
            h = ar[i];
        }
        else{
            wat_and_stone += h;
        }
    }
    wat_and_stone += (num_right_max - num_left_max + 1) * max_stolb;

    h = 0;
    for (int i = N-1; i > num_right_max; --i){
       if (ar[i] > h){
            wat_and_stone += ar[i];
            h = ar[i];
        }
        else{
            wat_and_stone += h;
        }
    }

    cout << wat_and_stone - stone;
    return 0;
}
