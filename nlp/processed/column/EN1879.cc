#include <iostream>
using namespace std;

int main(){
	int colich;
	cin >> colich;
	int h[colich];
	for(int i = 0; i < colich; i++){
		cin>>h[i];
	}
	//peremenye
	int l, rasmer, n, m = 0;
	n = colich;
	l = 0;
	//count<<r*10 + 7
             rasmer = n - 1;
             long sum = 0;
             while (l < rasmer)
             {
                 while (l < rasmer && h[l] <= h[l+1])
                 {
                     l++;
                 }
                 while (rasmer > l && h[rasmer] <= h[rasmer-1])
                 {
                     rasmer--;
                 }
                 if (l == rasmer) break;
                if (h[l]<=h[rasmer])
                 {
                     int max = h[l];
                     l++;
                     while (h[l]<max)
                     {
                         sum += max - h[l];
                         l++;
                     }
                 }
				 //cin>>h;
                 else
                 {
                     int max = h[rasmer];
                     rasmer--;
                     while (h[rasmer] < max)
                     {
                        sum += max - h[rasmer];
                         rasmer--;
                     }
                 }

             }
			 cout<<sum;
	
	return 0 ;
}