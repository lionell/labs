#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int mas[n];
    int first = 0;
    int rez = 0;
    int last = 0;
    int indexFirst = 0;
    int indexLast = 0;
    int mini = 0;
    bool ready = true;
    for(int i = 0;i < n;i++){
        cin >> mas[i];
    }
    for(int h = 0;h < n+1;h++){
        first = mas[h];
        indexFirst = h;
        last = mas[n-1];
        indexLast = n-1;
        for(int j = n-1;j > h;j--){
            ready = true;
            last = mas[j];
            indexLast = j;
            if(first >= last){
                mini = last;
            }else{
                mini = first;
            }
            for(int y = j-1;y > h;y--){
                if(mini <= mas[y]){
                    ready = false;
                }
            }
            if(ready){
                for(int g = indexFirst+1;g < indexLast;g++){
                    rez += mini-mas[g];
                    mas[g] = mini;
                }
                break;
            }
        }
    }
    cout << rez;
    return 0;
}
