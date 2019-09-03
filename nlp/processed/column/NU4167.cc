#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cur = 0, prev = 0;
    int volume = 0;
    cin >> prev;
    int cur_volume = 0, high = prev, len = 0;
    for (int i = 1; i < N; i++) {
        cin >> cur;
        if (cur < high){
            cur_volume += high - cur;
            len++;
        }
        else {
            volume += cur_volume;
            cur_volume = 0;
            high = cur;
            len = 0;
        }
        prev = cur;
    }
    if (cur < high) {
        cur_volume -= (high - cur) * len;
        if (cur_volume > 0) {
            volume += cur_volume;
        }
    }
    cout << volume << endl;
    return 0;
}
