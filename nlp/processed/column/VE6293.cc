#include <stdio.h>
#include <iostream>
using namespace std;
const int DEBUG = 0;
short* bowl;

int main(){
    long total = 0;
    int n,left,right;
    if(DEBUG){
        freopen("output.txt","w",stdout);
        freopen("input.txt","r",stdin);
    }
    scanf("%d",&n);
    bowl = new short[n];
    for(int i=0;i<n;++i)
        scanf("%hd",&bowl[i]);
    left = 0; right = n-1;
    while(left<right){
        while(left<right && bowl[left]<=bowl[left+1]) left++;
        while(left<right && bowl[right]<=bowl[right-1]) right--;        
        if(left==right)break;
        if(bowl[left]<=bowl[right]){
            int peak = bowl[left++];
            while(bowl[left]<peak)
                total += (peak-bowl[left++]);
        }else {
            int peak = bowl[right--];
            while(bowl[right]<peak)
                total += (peak-bowl[right--]);
        }

    }
    cout << total << endl;
    return 0;
}
