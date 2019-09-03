#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int h[N];
	for(int i = 0; i < N; i++){
		cin>>h[i];
	}
	int l, r, m = 0;
             r = N - 1;
             long long sum = 0;
             while (l < r)
             {
                 while (l < r && h[l] <= h[l+1])l++;
                 while (r > l && h[r] <= h[r-1])r--;
                 if (l == r) break;
                if (h[l]<=h[r])
                 {
                     int max = h[l];l++;
                     while (h[l]<max)
                     {
                         sum += max - h[l];
                         l++;
                     }
                 }
                 else
                 {
                     int max = h[r];
                     r--;
                     while (h[r] < max)
                     {
                        sum += max - h[r];r--;
                     }
                 }

             }
			 cout<<sum;
	return 0 ;
}