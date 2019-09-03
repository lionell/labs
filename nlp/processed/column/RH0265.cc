#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned int n, max = 0, temp, temp_prev, ans = 0, square = 0, columns = 0, counter = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp > max){ans+=max*counter - columns; columns=0;counter = 0; max = temp;square = 0;}
        else {
            if(temp > temp_prev)square = temp*counter -columns;
            columns +=temp;
            counter++;
        }
        temp_prev = temp;
    }
    cout << ans + square << '\n';
    return 0;
}
