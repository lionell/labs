#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10000001;

int n, arr[N];

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    //n = 10000000;
    long long s = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        //arr[i] = 10000;
    }
    long long water = 0;
    int last_max = 0, moves = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[last_max]){
            water += (long long)moves*arr[last_max] - sum;
            last_max = i;
            moves = sum = 0;
            continue;
        }
        moves++;
        sum += arr[i];
    }
    int l = last_max;
    moves = sum = 0;
    last_max = n - 1;
    for(int i = n - 1; i >= l; i--){
        if(arr[i] >= arr[last_max]){
            water += (long long)moves*arr[last_max] - sum;
            last_max = i;
            moves = sum = 0;
            continue;
        }
        moves++;
        sum += arr[i];
    }
    cout<<water<<endl;
}
